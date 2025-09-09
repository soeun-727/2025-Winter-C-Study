	#include <stdio.h> 
	#include <math.h>
	
	int inside(int x, int y, int cx, int cy, int r){
		//출발점과 도착점이 원 내부에 있는지 계산하는 함수
		int dx = cx - x;
		int dy = cy - y;
		return dx * dx + dy * dy < r * r; //피타고라스식으로 확인
	}
	
	int main(){
		int T;
		scanf("%d", &T);
		while(T--){
			int x1, x2, y1, y2, n;
			int count = 0;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2); //출발점과 도착점
			scanf("%d", &n); //행성의 개수
			
			for(int i = 0; i < n; i++){
				int cx, cy, r; //원의 중점과 반지름
				scanf("%d %d %d", &cx, &cy, &r);
				
				//출발점 혹은 도착점이 해당 원 내에 있는 경우에만 통과해서 감
				int start = inside(x1, y1, cx, cy, r);
				int end = inside(x2, y2, cx, cy, r);
				//만일 출발점과 도착점이 모두 같은 원 내에 있으면 통과하지 않음
				if(start != end)
					count++;
			}
			printf("%d\n", count);		
		}
	}