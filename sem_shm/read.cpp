//
// Created by lmy on 2022/6/9.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
};

int sem_id;

void sem_init(int semid, int nsignum, int sem_value)
{
    union semun sem_union;
    sem_union.val = sem_value;
    if (semctl(semid, nsignum, SETVAL, sem_union) == -1)
    {
        perror("semctl");
        exit(EXIT_FAILURE);
    }
}
/* P : -1 */
void sem_p(int semid, int nsignum)
{
    struct sembuf sops;
    sops.sem_num = nsignum;
    sops.sem_op  = -1;
    sops.sem_flg= SEM_UNDO;
    if (semop(semid, &sops, 1) == -1)
    {
        perror("semop");
        exit(EXIT_FAILURE);
    }
}

/* V : +1 */
void sem_v(int semid, int nsignum)
{
    struct sembuf sops;
    sops.sem_num = nsignum;
    sops.sem_op  = 1;
    sops.sem_flg = SEM_UNDO;
    if (semop(semid, &sops, 1) == -1)
    {
        perror("semop");
        exit(EXIT_FAILURE);
    }
}

void sem_print(int semid, int nsignum)
{
    int sem_value;
    sem_value = semctl(semid, nsignum, GETVAL);
    printf("sem[%d] = %d\n", nsignum, sem_value);
}

int main(int argc, char *argv[])
{
    int shm_id;
    key_t shm_key = ftok("./", 5151);
    key_t sem_key = ftok("./", 5152);

    shm_id = shmget(shm_key, 1024, IPC_CREAT|0664);
    void *shm_addr = shmat(shm_id, NULL, 0);

    sem_id = semget(sem_key, 2, IPC_CREAT|0644);
    if (sem_id == -1)
    {
        perror("semget");
        exit(EXIT_FAILURE);
    }
    else
    {
        sem_init(sem_id, 0, 0); //sem[0]: For read
        sem_init(sem_id, 1, 1); //sem[1]: For write
    }
    while(1)
    {
        sem_p(sem_id, 0);
        printf("%s\n", (char *)shm_addr);
        sem_v(sem_id, 1);
    }

    return 0;
}