//큐 구현
//피자가 더 필요하지 않은 경우 dequeue 하며 출력
//피자가 더 필요한 경우 enqueue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

typedef int element;

typedef struct
{
  element data[SIZE];
  int front, rear;
} QueueType;

void init(QueueType *Q)
{
  Q->front = 0; 
  Q->rear = -1;
}
void enqueue(QueueType *Q, element e)
{
  if (Q->rear + 1 < SIZE) { 
    Q->data[++(Q->rear)] = e;
  }
}
element dequeue(QueueType *Q)
{
  if (Q->front > Q->rear) {  
    return -1;
  }
  return Q->data[(Q->front)++];
}

int main(){
  int N;
  scanf("%d", &N); //인원수 N 입력받기

  int *arr = (int *)malloc(N*sizeof(int)); //N크기 배열 동적 할당
  int *result = (int *)malloc(N*sizeof(int)); //출력할 배열
  memset(result, 0, N * sizeof(int));
  
  QueueType q; //큐 선언
  init(&q);
  
  for (int i = 0; i < N; i++){
    scanf("%d", &arr[i]); //각 사람이 필요한 피자 조각 수 입력 받아 배열에 저장
    enqueue(&q, i); //인덱스를 큐에 저장    
  }

  int sec = 0;

  while (q.front <= q.rear) {
    sec++; //1초 증가
    int person = dequeue(&q); //person에 dequeue한 값 (인덱스) 저장

    arr[person]--; //가져온 인덱스의 값(필요한 피자 조각 수)에서 1빼기
    
    if(arr[person]==0){ //더 이상 피자가 필요하지 않은 경우
      result[person] = sec; //결과에 초 저장
    }else{
      enqueue(&q, person); //인덱스 다시 enqueue
    }
  }

  //출력
  for (int i = 0; i <N; i++){
    printf("%d", result[i]);
    if (i < N - 1) printf(" "); 
  }
    
  free(arr);
  free(result);
  return 0;
  
}
  
