#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//재귀함수를 통해 dfs 구현
void dfs(int k, int** dungeons, bool* visited, size_t dungeons_rows, int count, int* answer) {
    if (count > *answer) {
        *answer = count;
    }
    
    for (int i = 0; i < dungeons_rows; i++) {
        //탐색하지 않은 던전이고 피로도가 최소 필요보다 많은경우 
        if((visited[i] == false) && (dungeons[i][0] <= k)){
            visited[i] = true;
            //피로도 감소, count +1
            dfs(k - dungeons[i][1], dungeons, visited, dungeons_rows, count + 1, answer);
            visited[i] = false; //원상 복구
        }
    }
}

// dungeons_rows는 2차원 배열 dungeons의 행 길이, dungeons_cols는 2차원 배열 dungeons의 열 길이입니다.
int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    int answer = 0;
    bool visited[dungeons_rows]; //탐색한 던전을 나타내기위한 bool 배열
    //초기화
    for (size_t i = 0; i < dungeons_rows; i++){
        visited[i] = false;
    }
    
    //dfs
    dfs(k, dungeons, visited, dungeons_rows, 0, &answer);
    return answer;
}