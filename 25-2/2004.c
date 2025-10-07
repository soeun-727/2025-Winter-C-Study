#include <stdio.h>


long long count_factor(long long n, int factor) {
    long long count = 0;
    while (n >= factor) {
        count += n / factor;
        n /= factor;
    }
    return count;
}

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);

    //끝자리 0의 개수는 2와 5의 짝의 개수로 정해짐
    //count_2 = f2(n) - f2(m) - f2(n-m)
    //count_5 = f5(n) - f5(m) - f5(n-m)
    long long twos = count_factor(n, 2) - count_factor(m, 2) - count_factor(n - m, 2);
    long long fives = count_factor(n, 5) - count_factor(m, 5) - count_factor(n - m, 5);

    long long result = (twos < fives) ? twos : fives;
    printf("%lld\n", result);
    return 0;
}
