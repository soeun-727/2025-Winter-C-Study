#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    char arr[50][51];
    for (int i = 0; i < N; i++) {
        scanf("%s", arr[i]);
    }

    int max = 0;

    for (int i = 0; i < N; i++) {
        int check[50] = {0}; //i의 2-친구 여부 체크

        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 'Y') {
                check[j] = 1; //접 친구
                for (int k = 0; k < N; k++) {
                    if (arr[j][k] == 'Y') {
                        check[k] = 1; //구의 친구
                    }
                }
            }
        }
        check[i] = 0; //자기 자신은 제외

        int count = 0;
        for (int j = 0; j < N; j++) {
            if (check[j]) count++;
        }
        if (count > max) max = count;
    }

    printf("%d\n", max);
}
