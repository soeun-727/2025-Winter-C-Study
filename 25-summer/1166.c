
#include <stdio.h>
#include <math.h>

int main() {
    long long N, L, W, H;
    scanf("%lld %lld %lld %lld", &N, &L, &W, &H);

    //이분탐색을 통해 A의 최대값 찾기
    //이분 탐색 범위 지정
    double left = 0, right = (double)(L > W ? (L > H ? L : H) : (W > H ? W : H));
    double mid, result = 0;

    //실수 이분 탐색
    for (int i = 0; i < 100; i++) {
        mid = (left + right) / 2.0; //중간값

        long long count = (long long)(L / mid) * (long long)(W / mid) * (long long)(H / mid);

        if (count >= N) { //더 시도
            result = mid;
            left = mid;
        } else { //A 줄이기
            right = mid;
        }
    }

    printf("%.10lf", result);
}
