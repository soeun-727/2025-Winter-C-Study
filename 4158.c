#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(){
  int N, M;
  while(1){
    scanf("%d %d", &N, &M); //CD의 개수
    if (N == 0 && M == 0) break; //종료 조건

    //CD의 번호를 입력받을 배열
    int *arr1 = (int *)malloc(N * sizeof(int));
    int *arr2 = (int *)malloc(M * sizeof(int));

    //각 배열에 CD 번호 저장
    for (int i = 0; i < N; i++){
      scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < M; i++){
      scanf("%d", &arr2[i]);
    }  

    //arr1의 번호를 arr2에서 찾고 일치하는 CD의 개수만큼 result 증가
    int i = 0, j = 0, result = 0;
    while (i < N && j < M) {
      if (arr1[i] == arr2[j]) {  // 같은 CD 발견
        result++;
        i++;
        j++;
      } else if (arr1[i] < arr2[j]) {
        i++;  // arr1[i]가 작으면 arr1 포인터 증가
      } else {
        j++;  // arr2[j]가 작으면 arr2 포인터 증가
      }
    }

    free(arr1);
    free(arr2);
    

    printf("%d\n", result); //result의 값 출력
  }
  return 0;
}
