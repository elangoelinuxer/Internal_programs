#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
main()
{
int semid,i;
char a=97;

FILE *p;

struct sembuf v;

//creating semaphore
semid=semget(4,3,IPC_CREAT|0666);   //4 - semaphore key    3- no of sub semaphores

while(a!=123)
{

v.sem_num=2;
v.sem_op=-1;
v.sem_flg=SEM_UNDO;

semop(semid,&v,1);

p=fopen("file1","a"); //  

for(i=0;i<5;i++)
fputc(a,p);
fclose(p);
printf("writing in to file by process 2oooooo.. \n");
a++;
semctl(semid,2,SETVAL,0);
}

}

