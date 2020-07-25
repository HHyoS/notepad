#ifndef __Circle_Q_H__
#define __Clrcle_Q_H__

#define TRUE	1
#define FALSE	0

#define QUE_LEN	40

typedef int Data;

typedef struct _CircleQ
{
	int front;
	int rear;
	int counter;
	Data QArr[QUE_LEN];
} CircleQ;

typedef CircleQ Queue;

void QueueInit(Queue * pq);
void counterr(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data ErrorOut(Queue * pq);
#endif
