#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//두 수를 조합 해 더 큰 수 리턴
int compare(const void* a, const void* b){
    char num1[10], num2[10]; //조합 1, 2
    sprintf(num1, "%d%d", *(int*)a, *(int*)b);
    sprintf(num2, "%d%d", *(int*)b, *(int*)a);
    
    return strcmp(num2, num1);
}

char* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*numbers_len*4);
    answer[0] = '\0';
    
    //qsort로 정렬
    qsort(numbers, numbers_len, sizeof(int), compare);
    
    //모든 값이 0일 때
    if (numbers[0] == 0) {
        return strdup("0");
    }
    
    //answer에 정렬된 값 저장
    for(int i = 0; i < numbers_len; i++){
        char temp[5]; 
        sprintf(temp, "%d", numbers[i]); //우선 temp에 저장
        strcat(answer, temp); //\0인 answer에 이어붙여 문자열로 저장
    }
    
    return answer;
}