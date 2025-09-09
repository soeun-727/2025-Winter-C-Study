#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d\n", &N);
    
    char input[1001]; 
    fgets(input, sizeof(input), stdin); //우선 한줄로 입력 받기

    int balloon[N];
    int index = 0;
    char *token = strtok(input, " "); //공백 제거
    while (token != NULL){
        balloon[index++] = atoi(token); //정수로 저장
        token = strtok(NULL, " ");
    }

    int visited[N]; //풍선이 터졌는지 여부
    memset(visited, 0, sizeof(visited));
    int current = 0; //현재 인덱스 
    int count = 0; //while문 위한 카운트

    while(count < N){
        printf("%d ", current + 1); //처음에는 1위치에
        visited[current] = 1; //방문 처리
        count++; 

        if (count == N) break; //마지막 풍선

        int move = balloon[current]; //풍선 안의 숫자만큼 이동
        int dir = move > 0 ? 1 : -1; //이동
        int step = abs(move);

        while (step > 0) {
            current = (current + dir + N) % N; //원형
            if (!visited[current]) step--;
        }
    }    
}