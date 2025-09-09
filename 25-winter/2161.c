#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

typedef int element;

typedef struct
{
  element data[SIZE];
  int rear, front;
} QueueType;

void init(QueueType *Q)
{
  Q->rear = Q->front = 0;
}

int is_empty(QueueType *Q)
{
  return Q->front == Q->rear;
}

int is_full(QueueType *Q)
{
  return Q->front == (Q->rear + 1) % SIZE;
}

void enqueue(QueueType *Q, element e)
{
  if (is_full(Q))
    printf("Overflow\n");
  else
  {
    Q->rear = (Q->rear + 1) % SIZE;

    Q->data[Q->rear] = e;
  }
}

element dequeue(QueueType *Q)
{
  if (is_empty(Q))
  {
    printf("Empty\n");
    return -1;
  }
  else
  {
    Q->front = (Q->front + 1) % SIZE;
    return Q->data[Q->front];
  }
}

element peek(QueueType *Q)
{
  if (is_empty(Q))
  {
    printf("Empty\n");
    return 0;
  }
  return Q->data[(Q->front + 1) % SIZE];
}

void print(QueueType *Q)
{
  printf("Front Pos : %d\n, Rear Pos : %d\n", Q->front, Q->rear);
  int i = Q->front; 
  while (i != Q->rear)
  {
    i = (i + 1) % SIZE;
    printf("[%d]", Q->data[i]);
  }
  printf("\n");
}

int main()
{
  QueueType Q;
  init(&Q);
  
  int N;
  scanf("%d", &N);
  
  for (int i =1; i<=N; i++){
    enqueue(&Q, i);
  }

  while((Q.rear - Q.front) > 1){
    printf("%d ", dequeue(&Q));
    enqueue(&Q, dequeue(&Q));
  }

  printf("%d\n", dequeue(&Q));
  
}
