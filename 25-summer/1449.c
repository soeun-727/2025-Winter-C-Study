#include <stdio.h>
#include <stdlib.h>

//비교함수
int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    int N, L;
    scanf("%d %d", &N, &L);
    int arr[1001];
    
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]); //위치 입력받기
    }

    //위치 정렬
    qsort(arr, N, sizeof(int), compare); //순서대로 정렬
    
    int count = 0; //테이프 수 
    double end = 0.0; //테이프 끝

    for (int i = 0; i < N; i++) {
        //현재 테이프 범위 안에 있으면 건너뜀
        if (arr[i] <= end) continue;

        //새 테이프
        count++;

        //왼쪽 0.5부터 덮기 시작. L 길이 덮음
        end = arr[i] - 0.5 + L;
    }

    printf("%d", count);
}