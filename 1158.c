//요세푸스 순열, k번째를 제거하고 k-1번째까지를 빼서 다시 추가한 후 k번째를 제거하는 것 반복

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5000

typedef struct 
{	
  int data[SIZE]; 
  int front, rear;
}QueueType;

void init(QueueType *Q)
{   
  Q->front = Q->rear = 0; 
}

int isEmpty(QueueType *Q) 
{
  return Q->front == Q->rear;
}
int isFull(QueueType *Q) 
{
  return Q->rear == SIZE-1;
}

void enqueue(QueueType *Q, int e)
{
  if(isFull(Q))
      printf("Queue is Full!\n");
  else
  {
      Q->rear = (Q->rear + 1) % SIZE;
      Q->data[Q->rear] = e;
  }
}

int dequeue(QueueType *Q)
{  
  if(isEmpty(Q))
  {
      printf("Queue is Empty.\n");
      return -1;
  }
  Q->front = (Q->front + 1) % SIZE;
  return Q->data[Q->front];
}

int main(){
  int N, K;
  scanf("%d %d", &N, &K);

  int *result = (int *)malloc(N * sizeof(int));
  QueueType Q;
  init(&Q);

  for(int i = 0; i < N; i++){
    enqueue(&Q, i+1);
  }

  int count = 0;
  printf("<");

  while (!isEmpty(&Q)) {
    for (int i = 0; i < K - 1; i++) {
      enqueue(&Q, dequeue(&Q));
    }
    result[count++] = dequeue(&Q);
  }
  
  for (int i = 0; i < N; i++) {
    printf("%d", result[i]);
    if (i != N - 1) {
      printf(", ");
    }
  }
  printf(">");

  free(result);
  return 0;
}
