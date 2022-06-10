//
// Created by lmy on 2022/6/9.
//




#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/**
 实现 ps aux | grep xxx 父子进程通信

 子进程： ps aux ,子进程结束后，将数据发送给父进程
 父进程：获取到数据，过滤

 pipe()
 execlp()
 子进程将标准输出 stdout_fifeno 重定向到管道的写段  dup2


 */

int main() {
    int fd[2];
    int ret = pipe(fd);

    if (ret == -1) {
        perror("pipe");
        exit(0);
    }

    //创建进程

    pid_t pid = fork();

    if (pid > 0) {

        //父进程
        //关闭写段
        close(fd[1]);
        char buf[1024]={0};

        //从管道读取数据 过滤输出

        while (read(fd[0],buf, sizeof(buf)-1)>0){
            printf("%s",buf);
            memset(buf,0,1024);
            wait(NULL);
        }


    } else if (pid == 0) {

        //子进程
        //关闭读端
        close(fd[0]);

        //文件描述符重定向
        dup2(fd[1], STDOUT_FILENO);
        //执行 ps aux
        execlp("ps", "ps", "aux", NULL);
        perror("execlp");
        exit(0);

    } else {
        perror("fork");
        exit(0);
    }


    return 0;
}