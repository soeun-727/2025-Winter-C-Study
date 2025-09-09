#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool graph[100][100]; //인접 행렬

//송전탑의 개수를 세는 dfs 구현
//node는 현재 탐색 중인 송전탑 번호, count는 송전탑 개수
int dfs(int node, bool* visited, int n){
    visited[node] = true; //현재 노드방문 처리 
    int count = 1;
    
    for (int i = 1; i <= n; i++) {
        if (graph[node][i] && !visited[i]) { //인접한 송전탑을 방문하여
            count += dfs(i, visited, n); //재귀호출
        }
    }
    return count;
}

// wires_rows는 2차원 배열 wires의 행 길이, wires_cols는 2차원 배열 wires의 열 길이입니다.
int solution(int n, int** wires, size_t wires_rows, size_t wires_cols) {
    int answer = n; //최대로 설정
    
    for(size_t i = 0; i < wires_rows; i++){
        memset(graph, false, sizeof(graph)); //그래프 초기화
        
        for (int j = 0; j < wires_rows; j++) {
            if (j == i) continue; // i번째 전선을 끊음
            int a = wires[j][0];
            int b = wires[j][1];
            graph[a][b] = graph[b][a] = true;//나머지 전선의 연결 상태 구성
        }
        
        // dfs로 한 쪽 송전탑 수 세기
        bool visited[101] = {false};
        int count = dfs(1, visited, n); //1번부터 한쪽을 셈
        int diff = abs(count - (n - count)); //다른 쪽은 전체에서 뺀 값
        if (diff < answer) //answer 최소값으로 갱신
            answer = diff;   
    }
    return answer;
}