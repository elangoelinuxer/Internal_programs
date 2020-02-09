
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
  
// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 
void *myThreadFun(void *vargp) 
{ 
    sleep(5); 
    printf("Printing  from Thread 1 \n"); 
    return NULL; 
} 
   
void *myThreadFun1(void *vargp) 
{ 
    sleep(1); 
    printf("thread2 \n"); 
    return NULL; 
}

int main() 
{ 
    pthread_t thread_id, tmp_id; 
    printf("Before Thread\n"); 
    pthread_create(&thread_id, NULL, myThreadFun, NULL); 
    pthread_create(&tmp_id, NULL, myThreadFun1, NULL); 
 
    pthread_join(thread_id, NULL); 
    pthread_join(tmp_id, NULL); 


    printf("After Thread\n"); 
    exit(0); 
}

