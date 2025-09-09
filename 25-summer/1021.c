#include <stdio.h>

int queue[100];
int front = 0, rear;

// 큐에서 몇 번째 인덱스에 있는지 반환
int place(int val, int size) {
    for (int i = 0; i < size; i++) {
        if (queue[(front + i) % 100] == val)
            return i;
    }
    return -1;
}

int main() {
    int N, M; // N <= 50, M <= N
    scanf("%d %d", &N, &M);

    rear = N;
    for (int i = 0; i < N; i++) {
        queue[i] = i + 1;
    }

    int count = 0;

    for (int i = 0; i < M; i++) {
        int target;
        scanf("%d", &target);
        int size = rear - front;
        int idx = place(target, size);

        // 2번 연산 (왼쪽으로)
        if (idx <= size / 2) { //어느쪽으로 돌리는게 더 빠른지 계산
            for (int j = 0; j < idx; j++) {
                int temp = queue[front];
                for (int k = front; k < rear - 1; k++) {
                    queue[k] = queue[k + 1];
                }
                queue[rear - 1] = temp;
                count++;
            }
        }
        // 3번 연산 (오른쪽으로)
        else {
            for (int j = 0; j < size - idx; j++) {
                int temp = queue[rear - 1];
                for (int k = rear - 1; k > front; k--) {
                    queue[k] = queue[k - 1];
                }
                queue[front] = temp;
                count++;
            }
        }

        // 1번 연산 (뽑기)
        front++;
    }

    printf("%d", count);
    return 0;
}
