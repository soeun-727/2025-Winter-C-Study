#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	
	long long arr[N+1][2]; //자리수,  마지막 자리가 0이거나 1
	
	arr[1][0] = 0; //한자리인 경우 0으로 시작할 수 없음
	arr[1][1] = 1; //한자리인 경우 '1' 1개
	
	for(int i = 2; i <= N; i++){
		//마지막 자리가 0이면 그 앞에 0과 1이 올 수 있음(개수 합하기) 
		arr[i][0] = arr[i-1][0] + arr[i-1][1]; //(점화식)
		//마지막이 1이면 그 앞은 0만 가능 (그 개수만 셈)
		arr[i][1] = arr[i-1][0];
	}
	printf("%lld", arr[N][0] + arr[N][1]);
}