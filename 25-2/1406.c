#include <stdio.h>
#include <string.h>

#define MAX 600000

char left[MAX], right[MAX];   //커서 왼쪽, 오른쪽 스택
int l_top = 0, r_top = 0;     //각 스택의 top 인덱스

int main() {
    char init[MAX+1];
    int M;
    scanf("%s", init);
    scanf("%d", &M);

    //초기 문자열을 left 스택에 넣음
    l_top = strlen(init);
    for (int i = 0; i < l_top; i++) {
        left[i] = init[i];
    }

    for (int i = 0; i < M; i++) {
        char cmd;
        scanf(" %c", &cmd);

        if (cmd == 'L') {  //커서를 왼쪽으로
            if (l_top > 0) {
                right[r_top++] = left[--l_top];
            }
        }
        else if (cmd == 'D') {  //커서를 오른쪽으로
            if (r_top > 0) {
                left[l_top++] = right[--r_top];
            }
        }
        else if (cmd == 'B') {  //왼쪽 문자 삭제
            if (l_top > 0) {
                l_top--;
            }
        }
        else if (cmd == 'P') {  //문자 추가
            char x;
            scanf(" %c", &x);
            left[l_top++] = x;
        }
    }

    //최종 결과 출력: left + (right를 거꾸로)
    for (int i = 0; i < l_top; i++) {
        putchar(left[i]);
    }
    for (int i = r_top - 1; i >= 0; i--) {
        putchar(right[i]);
    }
    return 0;
}
