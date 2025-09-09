#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int temp;
    int max_w = 0;
    int max_h = 0;
    
    //가로가 항상 세로보다 길도록 (sizes[너비][높이])
    for (int i = 0; i < sizes_rows; i++){
        if(sizes[i][1] > sizes [i][0]){ //세로가 더 긴 경우 
            temp = sizes[i][1]; //temp에 세로를 넣고
            //세로와 가로를 바꿈 
            sizes[i][1] = sizes[i][0]; 
            sizes[i][0] = temp;
        }
    }
    
    //가로와 세로의 최대값 구하기
    for (int i = 0; i < sizes_rows; i++){
        if(sizes[i][0] > max_w)
            max_w = sizes[i][0];
        if(sizes[i][1] > max_h)
            max_h = sizes[i][1];
    }
    
    //지갑 크기 계산
    answer = max_w * max_h;
    
    return answer;
}