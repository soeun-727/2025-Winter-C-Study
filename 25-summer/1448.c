#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) return 1;
    if (num1 > num2) return -1;
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    int *sticks = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &sticks[i]);
    }

    //내림차순 정렬
    qsort(sticks, N, sizeof(int), compare);

    for (int i = 0; i < N - 2; i++) {
        //가장 긴 변의 길이가 나머지 두 변의 합보다 작은지 확인
        //sticks[i] : 가장 긴 변
        //sticks[i+1], sticks[i+2] : 나머지 두 변
        if (sticks[i] < (long long)sticks[i+1] + sticks[i+2]) {
            long long sum = (long long)sticks[i] + sticks[i+1] + sticks[i+2];
            printf("%lld\n", sum);
            free(sticks);
            return 0;
        }
    }

    //삼각형을 만들 수 없는 경우 -1
    printf("-1\n");
    free(sticks); 
}