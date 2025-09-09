#include <stdio.h>

#define MOD 15746

int main() {
    int N;
    scanf("%d", &N);

    int dp[1000001];  //최대
    dp[1] = 1;
    dp[2] = 2;

    //피보나치 수열 변형
    //맨 앞 1 나머지는 길이 N-1짜리 수열
    //맨 앞 00 나머지는 길이 N-2짜리 수열
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    printf("%d", dp[N]);
    return 0;
}
