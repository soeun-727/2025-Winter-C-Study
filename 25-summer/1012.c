#include <stdio.h>
#include <string.h>
#define MAX 50

int field[MAX][MAX];     //밭
int visited[MAX][MAX];   //방문 여부
int dx[] = {0, 0, -1, 1}; //상하좌우 이동
int dy[] = {-1, 1, 0, 0};

int M, N;

void dfs(int x, int y) {
    visited[y][x] = 1; //현재 위치 방문 처리

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; //다음 x좌표
        int ny = y + dy[i]; //다음 y좌표

        // 범위 내에 있고, 배추가 있으며 아직 방문하지 않았다면 DFS 계속
        if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
            if (field[ny][nx] == 1 && !visited[ny][nx]) {
                dfs(nx, ny);
            }
        }
    }
}

int main(){
	int T, K;
	scanf("%d", &T); //테스트케이스 개수
	
	while(T--){
		scanf("%d %d %d", &M, &N, &K);//가로, 세로, 배추 개수
		// 초기화
    memset(field, 0, sizeof(field));
    memset(visited, 0, sizeof(visited));

		for(int i = 0; i < K; i++){
			int X, Y;
			scanf("%d %d", &X, &Y); //각 배추의 위치
			field[Y][X] = 1; //배추가 있는 곳은 1
		}
		
		int count = 0; //필요한 지렁이 수
		
		//한 배추에 대해 X좌표가 같거나 Y좌표가 같은 경우 인접한 것
		for (int i = 0; i < N; i++) {
	    for (int j = 0; j < M; j++) {
				// 배추가 있고 아직 방문하지 않은 경우
				if (field[i][j] == 1 && !visited[i][j]) {
	        dfs(j, i); // 그 배추에서 DFS 시작
					count++; // 새 그룹 발견 → 지렁이 한 마리 추가
        }
	    }
		}
		printf("%d\n", count);		
	}
}