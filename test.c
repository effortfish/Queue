#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

#define MaxSize 100

typedef struct Queue
{
	int numSpace[MaxSize];
	int front;
	int rear;
	int size;
}Queue;

Queue* CreateQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (!q)
	{
		printf("error\n");
	}
	q->front = 0;
	q->rear = -1;
	q->size = 0;
	return q;
}

int isFull(Queue* ps)
{
	if (ps->size == MaxSize)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int isEmpty(Queue* ps)
{
	if (ps->size == 0)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

bool Add(Queue* ps, int num)
{
	if (isFull(ps) == 1)
	{
		return false;
	}
	if (ps->rear == MaxSize - 1)
	{
		ps->rear = 0;
		ps->numSpace[ps->rear] = num;
		ps->size++;
		return true;
	}
	ps->rear = (ps->rear + 1) % MaxSize;
	ps->numSpace[ps->rear] = num;
	ps->size++;
	return true;
}

bool Delete(Queue* ps)
{
	if (isEmpty(ps) == 1)
	{
		return false;
	}
	ps->front = (ps->front + 1) % MaxSize;
	ps->size--;
	return true;
}

bool PrintQueue(Queue* ps)
{
	int index = ps->front;
	if (isEmpty(ps) == 1)
	{
		return false;
	}
	for (int i = 0; i < (ps->size); i++)
	{
		printf("%d ", ps->numSpace[index]);
		if (index == MaxSize - 1)
		{
			index = 0;
			continue;
		}
		index++;
	}
	return true;
}

int main()
{
	Queue* q = CreateQueue();
	Add(q, 2);
	Add(q, 4);
	Add(q, 5);
	Add(q, 6);
	PrintQueue(q);
	Delete(q);
	printf("\n");
	PrintQueue(q);
	return 0;
}