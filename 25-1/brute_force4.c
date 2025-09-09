#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* word) {
    int answer = 0;
    switch(word[0]){
        case 'A': answer++; break;
        case 'E': answer=(1+5+25+125+625)+1; break;
        case 'I': answer=2*(1+5+25+125+625)+1; break;
        case 'O': answer=3*(1+5+25+125+625)+1; break;
        case 'U': answer=4*(1+5+25+125+625)+1; break;
    }
    switch(word[1]){
        case '\0': break;
        case 'A': answer++; break;
        case 'E': answer+=(1+5+25+125)+1; break;
        case 'I': answer+=2*(1+5+25+125)+1; break;
        case 'O': answer+=3*(1+5+25+125)+1; break;
        case 'U': answer+=4*(1+5+25+125)+1; break;
    }
    switch(word[2]){
        case '\0': break;
        case 'A': answer++; break;
        case 'E': answer+=(1+5+25)+1; break;
        case 'I': answer+=2*(1+5+25)+1; break;
        case 'O': answer+=3*(1+5+25)+1; break;
        case 'U': answer+=4*(1+5+25)+1; break;
    }
    switch(word[3]){
        case '\0': break;
        case 'A': answer++; break;
        case 'E': answer+=(1+5)+1; break;
        case 'I': answer+=2*(1+5)+1; break;
        case 'O': answer+=3*(1+5)+1; break;
        case 'U': answer+=4*(1+5)+1; break;
    }
    switch(word[4]){
        case '\0': break;
        case 'A': answer++; break;
        case 'E': answer+=(1)+1; break;
        case 'I': answer+=2*(1)+1; break;
        case 'O': answer+=3*(1)+1; break;
        case 'U': answer+=4*(1)+1; break;
    }
    
    return answer;
}