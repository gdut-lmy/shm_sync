//
// Created by lmy on 2022/6/9.
//

#include <cstdio>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include <iostream>

using namespace std;

int main() {

    //1. 创建一个共享内存
    int shmid = shmget(100, 4096, IPC_CREAT | 0664);
    printf("shmid: %d", shmid);

    void *ptr = shmat(shmid, nullptr, 0);


    char str[1024];
    while (fgets(str, 1023, stdin)) {
        memcpy(ptr, str, strlen(str) + 1);

        memset(str,0,1024);

    }
    printf("按任意键继续\n");
    getchar();

    //取消关联
    shmdt(ptr);

    //删除
    shmctl(shmid, IPC_RMID, nullptr);

    return 0;

}