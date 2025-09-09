#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*prices_len);
    
    for (int i = 0; i < prices_len; i++){
        int sec = 0; //떨어지지 않은 기간 (계속 초기화)
        for (int j = i + 1; j < prices_len; j++){
            sec++; //1초 증가
            if(prices[i] > prices[j]){ //주가가 감소한 경우 반복문 탈출
                break;
            }
        }
        answer[i] = sec; //sec 값 answer 배열에 저장
    }
    
    return answer;
}