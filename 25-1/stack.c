#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//스택(카운트 변수)를 통해 해결
bool solution(const char *s) {
    int count = 0;  // '(' 개수

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            count++;  // '('일 시 증가
        } else {
            count--;  // ')'일 시 감소
        }

        // ')'가 '('보다 많아지면(음수이면) false
        if (count < 0) {
            return false;
        }
    }

    // count가 0이면 true
    return count == 0;
}
