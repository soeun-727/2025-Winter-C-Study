#include <stdio.h>

//dp로 구현
int main() {
    int n;
    int box[1001]; //상자 크기 저장 배열
    int dp[1001]; //i번째 상자를 마지막으로 하는 최대 상자 개수
    int max = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &box[i]);
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 1; //자기 자신만 선택했을 경우 최소 1
        for (int j = 0; j < i; j++) {
            //j번 상자를 i번째에 넣을 수 있는 경우
            if (box[j] < box[i] && dp[j] + 1 > dp[i]) { //모든 상자에 대해 그 앞 상자 검사
                dp[i] = dp[j] + 1; //갱신
            }
        }
        if (dp[i] > max) max = dp[i];
    }

    printf("%d\n", max);
    return 0;
}
