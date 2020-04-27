#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct QueueRecord;
typedef struct	QueueRecord* Queue;

bool isEmpty(Queue Q);
bool isFull(Queue Q);
Queue CreatQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void EnQueue(int val, Queue Q);


