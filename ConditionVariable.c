#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 10



pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t fill = PTHREAD_COND_INITIALIZER;


int buffer[MAX] = {0,};
int count = 0;
int fifi= 0;
int flag = 0;
int end = 0;  // 종료조건
void put (int value) {
    if(buffer[fifi]== 0){
        buffer[fifi]=value;
        fifi++;
        fifi%=MAX;
        count++;
        }
   
}

int get() {
    if(buffer[flag]==0)
        return 0;
    else{
        int tmp = buffer[flag];
        buffer[flag] = 0;
        flag++;
        count--;
        flag%=MAX;
       
        return tmp;
    }
}


void *producer1(void *arg){
    int large = 65; 
    int small = 97;
    int num = large;
    int i;
    int *loops = (int *) arg;
    for (i =0; i < *loops; i++){
        pthread_mutex_lock(&mutex);
        while (count == MAX){
            pthread_cond_wait(&empty, &mutex);}
        put(num);
        num++;
        if((i+1)%26 == 0 && i > 0 ){
            if((i+1)%51 == 0)
                num = large;
            else
                num = small;
        }
        pthread_cond_signal(&fill);
        pthread_mutex_unlock(&mutex);
    }
    end--;
   
}

void *producer2(void *arg){
    int i;
    int *loops = (int *) arg;
    int check=1;
    for (i =0; i < *loops; i++){
        pthread_mutex_lock(&mutex);
        while (count == MAX){
            pthread_cond_wait(&empty, &mutex);}
        put(check);
        if(check==50)
            check=1;
        else
            check++;
        pthread_cond_signal(&fill);
        pthread_mutex_unlock(&mutex);
    }
    end--;
}
       
void *consumer(void *arg) {
    int i=0;
    while(1){
        pthread_mutex_lock(&mutex);
        while (count == 0 && end!=-2){
            pthread_cond_wait(&fill, &mutex);}
       
        int tmp = get();
        if(end==-2 && tmp==0){
            pthread_mutex_unlock(&mutex);
            break;}
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
        if(tmp>0){
            if(tmp>50)
                printf("%c\t", (char)tmp);
            else
                printf("%d\t", tmp);

            if(i>0 && (i+1)%10==0)
                printf("\n");
        }
       
        i++;
    }
}

int main(int argc, char *argv[]){
    pthread_t p1, p2, p3;
    int loopnum = 52;
    int loopnum2 = 50;
    void *p = &loopnum;
    void *pp = &loopnum2;
   
   
    pthread_create(&p1, NULL, producer1, p);
    pthread_create(&p2, NULL, producer2, pp);

    usleep(5); 
    pthread_create(&p3, NULL, consumer, NULL);

    pthread_join(p3, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("end game\n");
    return 0;
}
