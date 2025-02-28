#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int main(){
  int T, N,M;
  scanf("%d", &T);

  while (T--) { // T개의 테스트 케이스
    scanf("%d", &N); // 수첩1에 적혀 있는 정수 개수 입력

    int *arr1 = (int *)malloc(N * sizeof(int)); // 수첩1 배열 동적 할당
    for (int i = 0; i < N; i++) {
      scanf("%d", &arr1[i]); // 수첩1의 정수 입력
    }

    scanf("%d", &M); // 수첩2에 적혀 있는 정수 개수 입력
    int *arr2 = (int *)malloc(M * sizeof(int)); // 수첩2 배열 동적 할당
    for (int i = 0; i < M; i++) {
      scanf("%d", &arr2[i]); // 수첩2의 정수 입력
    }

    int *set = (int *)calloc(1000001, sizeof(int)); //집합으로 비교
    
    for (int i = 0; i < N; i++) { //있을 시 1로 표시
      set[arr1[i]] = 1;
    }
    
    for (int i = 0; i < M; i++) { // 있는지 확인하고 1/0 출력
      if (set[arr2[i]] == 1) {
        printf("1\n"); 
      } else {
        printf("0\n");  
      }
    }
    free(arr1);
    free(arr2);
    free(set);
  }
  return 0;
}
