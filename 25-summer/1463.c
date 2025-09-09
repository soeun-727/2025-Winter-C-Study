#include <stdio.h>

int dp[1000001];

int main() {
	int N;
	scanf("%d", &N);

//동적 프로그래밍 사용
	dp[1] = 0; //1인 경우 연산 X
	for (int i = 2; i <= N; i++) {
		//i를 만들기 위한 최소 연산 횟수는 i-1값 +1
		//1을 빼는 연산만 한 것을 가정한 값
		dp[i] = dp[i - 1] + 1; 
		
		//2로 나누어 떨어질 때 앞의 값과 비교하여 더 작은 값으로 갱신
		if (i % 2 == 0) dp[i] = dp[i] < dp[i / 2] + 1 ? dp[i] : dp[i / 2] + 1;
		//3으로 나누어 떨어지는 경우 동일하게
		if (i % 3 == 0) dp[i] = dp[i] < dp[i / 3] + 1 ? dp[i] : dp[i / 3] + 1;
	}

	printf("%d", dp[N]);
}
