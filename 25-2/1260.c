#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int N, M, V; //정점, 간선, 시작 정점
int graph[MAX][MAX]; //인접 행렬
int visited[MAX];

//DFS
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v); //방문한 것 출력
    for(int i = 1; i <= N; i++) { //작은 것부터 방문하여
        if(graph[v][i] && !visited[i]) {
            DFS(i); //재귀
        }
    }
}

//BFS
void BFS(int start) {
    int queue[MAX]; //큐
    int front = 0, rear = 0;

    for(int i = 1; i <= N; i++) visited[i] = 0; //초기화

    queue[rear++] = start;  
    visited[start] = 1;

    while(front < rear) {//큐가 빌 때까지 반복
        int v = queue[front++];
        printf("%d ", v);

        for(int i = 1; i <= N; i++) {
            if(graph[v][i] && !visited[i]) { //미방문이면 큐에 넣기
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &V);

    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1; //양방향
    }

    for(int i = 1; i <= N; i++) visited[i] = 0;
    DFS(V); //dfs 수행 및 출력
    printf("\n");
    BFS(V); //bfs
}
