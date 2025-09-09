#include <stdio.h>
#include <stdbool.h>

//x가 소수인지 판별하는 함수
bool prime(int x){
	//1로 나누어 떨어지는 경우 무시
	if(x < 2) return false;
	//i*i로 간단하게 표시
	for(int i = 2; i * i <= x; i++){ 
		if(x % i == 0) //나누어 떨어지는 경우 소수 아님
			return false; //아닌 경우 반복
	}
	return true;
}

int main(){
	int M, N;
	scanf("%d %d", &M, &N);
	
	for(int i = M; i <= N; i++){
		if(prime(i))
			printf("%d\n", i);
	}
}