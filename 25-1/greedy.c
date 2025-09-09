#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* number, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(number);
    char* answer = (char*)malloc(sizeof(char)*(len+1));
    int top = -1; int remove = 0;
    
    //스택처럼 구현하여 앞에보다 큰 수가 나온 경우 앞의 수를 pop
    for(int i = 0; i < len; i++){
        //만약 앞에 나온 수보다 큰 경우, k개보다 적게 뺐을 경우
        while(top >=0 && answer[top] < number[i] && remove < k){ 
            top--; //top값을 감소시켜 이전값에 덮어쓰도록
            remove++; //해당 수 제거 카운트
        }
        answer[++top] = number[i]; //작은 수 제거 후 남은 수 넣기
    }
    // 아직 제거 못한 수가 남았다면 뒤에서 제거
    top = top - (k - remove);
    
    answer[top+1] = '\0'; //값이 있는 만큼 자르기
    return answer;
}