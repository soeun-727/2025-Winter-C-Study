//모르겠다
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
  Q->rear = Q->front = -1;
}
void enqueue(QueueType *Q, element e)
{
  Q->rear++;
  Q->data[Q->rear] = e;
}
element dequeue(QueueType *Q)
{
  Q->front++;
  return Q->data[Q->front];
}

int main(){
  int N;
  scanf("%d", &N); //인원 N 입력받기

  int *arr = (int *)malloc(N*sizeof(int)); //N크기 배열 동적 할당
  int *result = (int *)malloc(N*sizeof(int)); //출력할 배열
  init(q);
  for (int i = 0; i < N; i++){
    scanf("%d", &arr[i]); //각 사람이 먹는 피자 조각 수 입력 받아 배열에 저장
    enqueue(q, arr[i]); //전체를 큐에 저장
  }

  //result에 인덱스+1을 저장하면서 dequeue
  //전체 arr에 대해 -1
  //if !=0 

  
   
  
  free(arr, result);
  return 0;
  
}
  
