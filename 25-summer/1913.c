
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);

    int **array = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        array[i] = (int *)malloc(N * sizeof(int));
    }

    int x = N / 2;
    int y = N / 2;
    array[x][y] = 1;

    int dx[] = {-1, 0, 1, 0}; //방향
    int dy[] = {0, 1, 0, -1};

    int num = 2;
    int d_idx = 0;
    int step = 1;
    int found_x = 0;
    int found_y = 0;

    //K가 1인 경우 좌표는 중심
    if (K == 1) {
        found_x = x + 1;
        found_y = y + 1;
    }

    while (num <= N * N) {
        //현재 방향으로 step만큼 이동
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < step; j++) {
                if (num > N * N) break;

                x += dx[d_idx];
                y += dy[d_idx];
                array[x][y] = num;

                if (num == K) {
                    found_x = x + 1;
                    found_y = y + 1;
                }

                num++;
            }
            d_idx = (d_idx + 1) % 4;
            if (num > N * N) break;
        }
        step++;
    }

    //배열 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    //좌표 출력
    printf("%d %d\n", found_x, found_y);

    for (int i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);
}