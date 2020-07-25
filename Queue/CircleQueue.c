#include <stdio.h>
#include <stdlib.h>
#include "CircleQueue.h"

void QueueInit(Queue * pq)
{
	pq->front = 0;
	pq->rear = 0;
}
void counterr(Queue * pq) {
	pq->counter = 0;
}

int QIsEmpty(Queue * pq)
{
	if(pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos)
{
	if(pos == (QUE_LEN)-1)
		return 0;
	else
		return pos+1;
}

void Enqueue(Queue * pq, Data data)
{
	if(NextPosIdx(pq->rear) == pq->front) 
	{
		(pq->counter)++;
	}

	pq->rear = NextPosIdx(pq->rear); 
	pq->QArr[pq->rear] = data;
}

Data Dequeue(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		(pq->counter)++;
	}
	pq->front = NextPosIdx(pq->front);
	return pq->QArr[pq->front];
}

Data ErrorOut(Queue * pq) {
	return pq->counter;
}
