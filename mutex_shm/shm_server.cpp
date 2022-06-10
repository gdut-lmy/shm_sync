//
// Created by lmy on 2022/6/9.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <pthread.h>
#include <unistd.h>

#include "sm_common.h"


int main(void) {
    int shm_id = -1;
    int ret = -1;
    int key = -1;
    int running = 1;

    struct sm_msg *msg = NULL;
    void *shared_memory = NULL;

    // 创建互斥锁
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);

    // 创建一片共享内存，使用同一个key: SM_ID
    //key = ftok( "./sm_common.h", 1 );
    //printf("key: %d\n", key);
    shm_id = shmget((key_t) SM_ID, sizeof(struct sm_msg), 0666 | IPC_CREAT);

    if (shm_id < 0) {
        perror("fail to shmget");
        exit(1);
    }

#if 1
    shared_memory = shmat(shm_id, NULL, 0);
    if (shared_memory == NULL) {
        perror("Failed to shmat");
        exit(1);
    }

    msg = (struct sm_msg *) shared_memory;

    msg->flag = 0;// 使用该标记位同步读写

    // 创建并初始化互斥锁
    pthread_mutex_init(&msg->sm_mutex, &attr);

    while (running) {
        pthread_mutex_lock(&msg->sm_mutex);// 阻塞,等待锁释放
        if (msg->flag == 1) {
            printf("Read message: %s\n", msg->buf);
            msg->flag = 0;
            pthread_mutex_unlock(&msg->sm_mutex);
            if (strncmp(msg->buf, "exit", 4) == 0) {
                running = 0;
            }
        } else {
           // printf("No available data to read, sleep...\n");
            pthread_mutex_unlock(&msg->sm_mutex);
            usleep(10000);
        }
    }
    ret = shmdt(shared_memory);
    if (ret < 0) {
        perror("Failed to shmdt");
        exit(1);
    }

    if (shmctl(shm_id, IPC_RMID, 0) < 0) {
        perror("failed to shmctl");
        exit(1);
    }
#endif
    return 0;
}
