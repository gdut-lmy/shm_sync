//
// Created by lmy on 2022/6/9.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <pthread.h>

#include "sm_common.h"


int main(void)
{
    int shm_id = -1;
    int ret = -1;
    int key = -1;
    int running = 1;
    struct sm_msg *msg = NULL;
    void *shared_memory = NULL;

    // 创建一片共享内存，使用同一个key: SM_ID
    //	key = ftok( "./sm_common.h", 1 );
    //printf("key: %d\n", key);
    shm_id = shmget((key_t)SM_ID, sizeof(struct sm_msg), 0666|IPC_CREAT);
    if(shm_id < 0)
    {
        perror("fail to shmget");
        exit(1);
    }

    shared_memory = shmat(shm_id, NULL, 0);
    if (shared_memory == NULL)
    {
        perror("Failed to shmat");
        exit(1);
    }

    msg = (struct sm_msg *)shared_memory;

    char buf[32];
    while (running)
    {
        printf("wait lock\n");
        pthread_mutex_lock(&msg->sm_mutex);// 阻塞等待内部的互斥锁
        printf("get lock\n");
        if(msg->flag == 1)
        {
            printf("Wait for other process's reading\n");
            pthread_mutex_unlock(&msg->sm_mutex);
            sleep(2);
        }
        else
        {
            printf("Please input data\n");
            fgets(buf, 32, stdin);
            printf("Write msg: %s\n", buf);
            strncpy(msg->buf, buf, sizeof(buf));
            msg->flag = 1;
            if (strncmp(msg->buf, "exit", 4) == 0)
            {
                running = 0;
            }
            pthread_mutex_unlock(&msg->sm_mutex);
        }
    }

    ret = shmdt(shared_memory);
    if (ret < 0)
    {
        perror("Failed to shmdt");
        exit(1);
    }

#if 0 //Do this in server.
    if(shmctl(shm_id, IPC_RMID, 0) < 0)
	{
		perror("failed to shmctl");
		exit(1);
	}
#endif
    return 0;
}