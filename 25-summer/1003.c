#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

		//동적 프로그래밍 사용
    int dp[41][2]; // dp[n][0]: 0 출력 횟수, dp[n][1]: 1 출력 횟수

    // 기본값 설정
    dp[0][0] = 1; dp[0][1] = 0;
    dp[1][0] = 0; dp[1][1] = 1;
    // DP 테이블 채우기
    for (int i = 2; i <= 40; i++) {
		    // fibonacci(i)를 호출할 때 출력되는 0의 횟수는
		    // fibonacci(i-1)을 호출할 때 출력된 0의 횟수 + fibonacci(i-2)를 호출할 때 출력된 0의 횟수
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);
        printf("%d %d\n", dp[N][0], dp[N][1]);
    }
}
