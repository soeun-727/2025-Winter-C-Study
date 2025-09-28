#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

int N;
int arr[MAX];
int visited[MAX];

//큐 
typedef struct {
    int pos;
    int dist;
} Node;

Node queue[MAX*10];
int front = 0, rear = 0;

void enqueue(int pos, int dist) {
    queue[rear].pos = pos;
    queue[rear].dist = dist;
    rear++;
}

Node dequeue() {
    return queue[front++];
}


//BFS 함수
int BFS(int start, int end) {
    visited[start] = 1; //시작 위치
    enqueue(start, 0);

    while(front < rear) { ///큐가 빌 때까지 반복
        Node cur = dequeue();

        if(cur.pos == end) return cur.dist;

        int step = arr[cur.pos];
        //오른쪽 방향
        for(int k = 1; cur.pos + k*step <= N; k++) {
            int next = cur.pos + k*step;
            if(!visited[next]) {
                visited[next] = 1;
                enqueue(next, cur.dist + 1); //최소 점프 수
            }
        }
        //왼쪽 방향
        for(int k = 1; cur.pos - k*step >= 1; k++) {
            int next = cur.pos - k*step;
            if(!visited[next]) {
                visited[next] = 1;
                enqueue(next, cur.dist + 1);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &arr[i]);

    int a, b;
    scanf("%d %d", &a, &b);

    int ans = BFS(a, b); 
    printf("%d\n", ans);

    return 0;
}
