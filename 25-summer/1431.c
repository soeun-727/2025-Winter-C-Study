#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 51

int sum(const char *s){ //숫자합 구하는 함수 
	int sum = 0;
	for(int i = 0; s[i]; i++){
		if(isdigit(s[i])) //숫자인 경우
			sum += s[i] - '0';
	}
	return sum;
}

int compare(const void *a, const void *b){//비교 함수
	const char *s1 = *(const char **)a;
	const char *s2 = *(const char **)b;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if  (len1 != len2) //1. 길이 비교
		return len1 - len2;

	int sum1 = sum(s1);
	int sum2 = sum(s2);
	if(sum1 != sum2) //2. 합 비교
		return sum1 - sum2;
	
	return strcmp(s1, s2); //3. 사전순
}

int main(){
	int N;
	scanf("%d", &N);
	char arr[N][MAX];
	char *ptr[N]; //정렬을 위한 포인터 배열 
	
	for(int i = 0; i < N; i++){
		scanf("%s", arr[i]);
		ptr[i] = arr[i]; //입력 받고 포인터 배열에도 추가
	}
	
	qsort(ptr, N, sizeof(char *), compare); //정렬
	
	for(int i = 0; i < N; i++){
		printf("%s\n", ptr[i]); //정렬한 것 순서대로 출력
	}
}