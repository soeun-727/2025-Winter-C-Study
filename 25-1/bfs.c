#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 102

// 이동 방향: 상, 하, 좌, 우
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int board[MAX][MAX];
bool visited[MAX][MAX];

typedef struct {
    int x, y, dist;
} Point;

Point queue[MAX * MAX];
int front = 0, rear = 0;

void enqueue(int x, int y, int dist) {
    queue[rear++] = (Point){x, y, dist};
}

Point dequeue() {
    return queue[front++];
}

int is_empty() {
    return front == rear;
}

// rectangle은 포인터 배열로 들어옴
int solution(int **rectangle, size_t rectangle_row_len, size_t rectangle_col_len, int characterX, int characterY, int itemX, int itemY) {
    memset(board, 0, sizeof(board));
    memset(visited, false, sizeof(visited));
    front = rear = 0;

    // 1. board 채우기 (2배 확장 후 테두리 포함)
    for (int i = 0; i < rectangle_row_len; i++) {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;

        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                board[x][y] = 1;
            }
        }
    }

    // 2. 내부 영역 제거
    for (int i = 0; i < rectangle_row_len; i++) {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;

        for (int x = x1 + 1; x < x2; x++) {
            for (int y = y1 + 1; y < y2; y++) {
                board[x][y] = 0;
            }
        }
    }

    // 3. BFS 탐색
    int startX = characterX * 2;
    int startY = characterY * 2;
    int endX = itemX * 2;
    int endY = itemY * 2;

    enqueue(startX, startY, 0);
    visited[startX][startY] = true;

    while (!is_empty()) {
        Point cur = dequeue();

        if (cur.x == endX && cur.y == endY) {
            return cur.dist / 2;  // 좌표 2배 했으므로 보정
        }

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx >= 0 && ny >= 0 && nx < MAX && ny < MAX) {
                if (!visited[nx][ny] && board[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    enqueue(nx, ny, cur.dist + 1);
                }
            }
        }
    }

    return -1;  // 도달 불가 (조건상 없음)
}
