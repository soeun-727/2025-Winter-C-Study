#include <stdio.h>

int main(){
    //입력 받기
    int N; 
    scanf("%d", &N);
    int arr[11];

    //서 있는 위치 넣을 배열
    int place[11];
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
        place[i] = 0;
    }

    for (int i = 0; i < N; i++) { //키가 작은 사람부터 (1 ~ N)
        int left = arr[i];  //자기보다 큰 사람 수
        for (int j = 0; j < N; j++) {
            if (place[j] == 0) { //빈자리
                if (left == 0) { //건너뛸 필요가 없으면 여기 배치
                    place[j] = i + 1;
                    break;
                }
                left--; //아직 건너뛰어야 함
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        printf("%d ", place[i]);
    }

}