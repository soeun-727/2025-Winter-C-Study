#include <stdio.h>

#define MAX 100

int main() {
    int n;
    char cmd[55];
    scanf("%d", &n);
    scanf("%s", cmd);

    //방향 인덱스 북동남서
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    int dir = 2; //시작은 남쪽

    //미로 전체를 벽으로
    char map[MAX][MAX];
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            map[i][j] = '#';

    //시작 좌표는 가운데로
    int y = MAX/2, x = MAX/2;
    map[y][x] = '.';  //시작 위치 방문 처리

    //방문한 좌표 범위 추적
    int minY = y, maxY = y, minX = x, maxX = x;

    for (int i = 0; i < n; i++) {
        if (cmd[i] == 'L') {
            dir = (dir + 3) % 4; //왼쪽
        } else if (cmd[i] == 'R') {
            dir = (dir + 1) % 4; //오른쪽
        } else if (cmd[i] == 'F') {
            //현재 방향으로 한 칸 전진
            y += dy[dir];
            x += dx[dir];
            map[y][x] = '.'; //방문

            //방문 범위 갱신
            if (y < minY) minY = y;
            if (y > maxY) maxY = y;
            if (x < minX) minX = x;
            if (x > maxX) maxX = x;
        }
    }

    //실제 방문한 직사각형 범위만 출력
    for (int i = minY; i <= maxY; i++) {
        for (int j = minX; j <= maxX; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
