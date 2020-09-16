#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <sys/types.h> 

#define N 100

pthread_mutex_t mut;
pthread_cond_t condc, condp;
int buffer = 0;

void *producer(void *ptr)
{
    int i;

    while (1){
        pthread_mutex_lock(&mut);
        while(buffer != 0)
            pthread_cond_wait(&condp,&mut);
        buffer = i;
        pthread_cond_signal(&condc);
        pthread_mutex_unlock(&mut);
        i++;
    }
    pthread_exit(0);
}

void *consumer(void *ptr)
{
    while (1){
        pthread_mutex_lock(&mut);
        while(buffer == 0)
            pthread_cond_wait(&condc,&mut);
        buffer = 0;
        pthread_cond_signal(&condp);
        pthread_mutex_unlock(&mut);
    }
    pthread_exit(0);
}
void *printtext(){
    while(1){
        printf("%d\n", buffer);
        sleep(60);
    }
}
int main(){
    pthread_t pro, con, pri;
    pthread_mutex_init(&mut, 0);
    pthread_cond_init(&condc, 0);
    pthread_cond_init(&condp, 0);
    pthread_create(&con, 0, consumer, 0);
    pthread_create(&pro, 0, producer, 0);
    pthread_create(&pri, 0, printtext, 0);
    pthread_join(pro, 0);
    pthread_join(con, 0);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&mut);
    return 0;
}
