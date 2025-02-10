#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000000

int stack[MAX_STACK_SIZE];
int top=-1;
 
typedef char element;

typedef struct
{
  element data[SIZE];
  int rear, front;
} QueueType;

void init(QueueType *Q)
{
  Q->rear = Q->front = -1;
}

int is_empty(QueueType *Q)
{
  return Q->front == Q->rear;
}

void enqueue(QueueType *Q, element e)
{
  if (is_full(Q))
    printf("Overflow\n");
  else
  {
    Q->rear++;

    Q->data[Q->rear] = e;
  }
}

element dequeue(QueueType *Q)
{
  if (is_empty(Q))
  {
    printf("Empty\n");
    return 0;
  }
  else
  {
    Q->front++;
    return Q->data[Q->front];
  }
}

void print(QueueType *Q)
{
  printf("Front Pos : %d\n, Rear Pos : %d\n", Q->front, Q->rear);
  for (int i = Q->front + 1; i <= Q->rear; i++) //반대로 바꿔야함
  {
    printf("[%c] ", Q->data[i]);
  }
  printf("\n");
}

int main(){
  int n;
  char s1[5];
  char s2[5];
  
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%s %s", &s1,&s2);
    if (s2[0] == e){
      enqueue(s1);
    }
    else{
      dequeue(s1);
    }
  }

  while(IsFull()==false)
    printf(%d ", pop());
  
  
}
