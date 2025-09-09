#include <stdio.h>

//__int128 별칭
typedef __int128 i128;

//__int128 정수 출력 함수
void print_i128(i128 n) {
    if (n == 0) {
        putchar('0');
        return;
    }

    char buf[50];
    int idx = 0;

    //10진수 문자열로 변환
    while (n > 0) {
        buf[idx++] = (n % 10) + '0';  //마지막 자리 숫자를 문자로
        n /= 10;                      //다음 자리 숫자로
    }

    //버퍼에 저장된 역순 숫자 정방향 출력
    while (idx--) putchar(buf[idx]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m); 

    //조합 대칭 성질
    if (m > n - m) m = n - m;

    i128 result = 1;

    for (int i = 1; i <= m; i++) {
        result *= (i128)(n - i + 1); //분자 
        result /= i;                 //분모
    }

    print_i128(result);
}


/*
본래 아래같이 작성했는데 오버플로우 때문에 오답이 나옴

#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int top=1, bottom=1;
    for (int i = 0; i < m; i++){
        bottom *= (i+1);
        top *= (n-i);
    }
    int result;
    result = top/bottom;

    printf("%d", result);

}
*/