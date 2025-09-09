#include <stdio.h>

int main(){
	int N, M;
	char rec[50][51]; //문자열로 받기 위해 열을 51로, 행은 50 
	scanf("%d %d", &N, &M);
	
	for(int i = 0; i < N; i++){
		scanf("%s", rec[i]);
	}
	
	int max = 1; //최대 크기는 최소 1
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++) {
	    //최대 변 길이: 끝까지 안 벗어나게
      for(int l = 1; i + l < N && j + l < M; l++){
	      // 네 꼭짓점 비교
        if(rec[i][j] == rec[i][j + l] &&
	        rec[i][j] == rec[i + l][j] &&
          rec[i][j] == rec[i + l][j + l]){
          int square = (l + 1) * (l + 1);
          if (square > max)
          max = square;
      }
    }
		printf("%d", max);
}