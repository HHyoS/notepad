#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct _MultiArg{
    char a;
    int b;
} MultiArg;

static volatile int counter = 0;

void * mythread(void *arg){
    MultiArg *my_arg = (MultiArg *) arg;
    printf("%s : bigin\n", &my_arg->a);
    int i;
    for(i=0; i<1000000; i++){
        usleep(my_arg->b);
        printf("[%s] %d usec\n", &my_arg->a, my_arg->b);
        counter = counter +1;
       
    }
   
    printf("%s : done counter -> %d \n", &my_arg->a, counter);

    return NULL;
    }

int main(int argc, char *argv[])
{   
    MultiArg *ma1, *ma2, *ma3, *ma4, *ma5;

    ma1 = (MultiArg *)malloc(sizeof(MultiArg));
    ma1->a = 'A';
    ma1->b =  100;

    ma2 = (MultiArg *)malloc(sizeof(MultiArg));
    ma2->a = 'B';
    ma2->b =  50;

    ma3 = (MultiArg *)malloc(sizeof(MultiArg));
    ma3->a = 'C';
    ma3->b =  30;

    ma4 = (MultiArg *)malloc(sizeof(MultiArg));
    ma4->a = 'D';
    ma4->b =  30;

    ma5 = (MultiArg *)malloc(sizeof(MultiArg));
    ma5->a = 'E';
    ma5->b =  10;
    pthread_t p1, p2, p3, p4, p5;
    printf("main : begin (counter = %d)\n", counter);
    pthread_create(&p5, NULL, mythread, (void *) ma5);
    pthread_create(&p4, NULL, mythread, (void *) ma4);
    pthread_create(&p3, NULL, mythread, (void *) ma3);
    pthread_create(&p2, NULL, mythread, (void *) ma2);
    pthread_create(&p1, NULL, mythread, (void *) ma1);
   
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);
    pthread_join(p5, NULL);
    printf("main: done with both (counter = %d)\n", counter);
    return 0;
} 
