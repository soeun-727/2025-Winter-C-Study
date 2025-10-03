#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){ //qsort용
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(){
  //총 대기시간의 최소는 절대값 합의 최소를 구하는 것
    int N;
    if (scanf("%d", &N) != 1) return 0;
    long long P[55]; //P[i] = B_i - A_i 차이값
    for (int i = 0; i < N; i++){
        long long A, B;
        scanf("%lld %lld", &A, &B);
        P[i] = B - A;
    }

    qsort(P, N, sizeof(long long), compare);

    if (N % 2 == 1) {
        //홀수이면 유일한 중위값 하나
        printf("1\n");
    } else {
        //짝수이면 중간 두 값 사이의 정수 개수
        long long L = P[N/2 - 1];
        long long R = P[N/2];
        //R >= L (정렬되어 있으므로)
        printf("%lld\n", R - L + 1);
    }
}
