//요세푸스 순열, k번째를 제거하고 k-1번째까지를 빼서 다시 추가한 후 k번째를 제거하는 것 반복

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front, size, capacity;
} QueueType;

void initQueue(QueueType *Q, int capacity) { //큐 초기화
    Q->data = (int *)malloc(capacity * sizeof(int));
    Q->front = 0;
    Q->size = 0;
    Q->capacity = capacity;
}

int isEmpty(QueueType *Q) {
    return Q->size == 0;
}

void enqueue(QueueType *Q, int value) { //삽입
    int rear = (Q->front + Q->size) % Q->capacity;
    Q->data[rear] = value;
    Q->size++;
}

int dequeue(QueueType *Q) { //제거, 반환
    if (isEmpty(Q)) {
        return -1;
    }
    int value = Q->data[Q->front];
    Q->front = (Q->front + 1) % Q->capacity;
    Q->size--;
    return value;
}

void circle(int N, int K) { //순열 함수
    QueueType Q;
    initQueue(&Q, N);

    for (int i = 1; i <= N; i++) { //N까지 삽입
        enqueue(&Q, i);
    }

    printf("<");
    
    // 요세푸스 순열 계산
    for (int count = 0; count < N; count++) {
        // K-1까지 맨 앞 요소를 꺼내서 맨 뒤로 보냄
        for (int i = 0; i < K - 1; i++) {
            enqueue(&Q, dequeue(&Q));
        }
        // K번째 요소 제거 및 출력
        printf("%d", dequeue(&Q));
        if (count != N - 1) {
            printf(", ");
        }
    }
    
    printf(">\n");

    //메모리 해제
    free(Q.data);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    circle(N, K);
    return 0;
}
