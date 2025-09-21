#include <stdio.h>

double triangle (int x1,int y1,int x2,int y2,int x3,int y3){
    //삼각형 넓이 구하는 신발끈 공식
    //이 부분 타입 때문에 틀렸었음
    long long sums1 = (long long)x1*y2 + (long long)x2*y3 + (long long)x3*y1;
    long long sums2 = (long long)y1*x2 + (long long)y2*x3 + (long long)y3*x1;
    double result = (double)(sums1 - sums2) / 2.0;
    if (result < 0) result = -result;
    return result;
}

int main(){
    int N; 
    scanf("%d", &N);

    int x[35]; //x좌표
    int y[35]; //y좌표

    for(int i = 0; i < N; i++){
        scanf("%d %d", &x[i], &y[i]);
    }

    double max = 0;

    //좌표 세개를 골랐을 때 삼각형의 넓이가 젤 큰 넓이 구하기
    for(int i = 0; i < N-2; i++){
        for(int j = i+1; j < N-1; j++){
            for(int k = j+1; k < N; k++){
              //좌표 세개 i, j, k를 구해서 넓이 구하기
              double size = triangle(x[i], y[i], x[j], y[j], x[k], y[k]);
              if (size > max) max = size;
            }
        }
    }

    printf("%.9f", max);
}
