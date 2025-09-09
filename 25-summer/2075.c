#include <stdio.h> 

typedef struct {
	int data;
} node;

typedef struct {
	node arr[1500 * 1500 + 1];
	int size;
} HEAP;

HEAP h;

void push(int data)
{
	int i = ++(h.size); //힙 사이즈 증가, 삽입할 위치 인덱스 설정

	//부모 노드와 비교하면서 위로 올라감
	while ((i != 1) && (data > h.arr[i / 2].data)) {
		h.arr[i].data = h.arr[i / 2].data; //부모를 자식으로 내림
		i /= 2; //부모로 이동
	}
	h.arr[i].data = data; //올바른 위치에 삽입
}

int pop()
{
	int root = h.arr[1].data; //루트(최댓값)를 저장
	int temp = h.arr[(h.size)--].data; // 마지막 원소 임시 저장, 사이즈 줄임

	int parent = 1;
	int child = 2;

	//temp 값을 아래로 내려가며 올바른 위치 찾기
	while (child <= h.size){
		//오른쪽 자식이 더 크면 오른쪽으로 이동
		if ((child < h.size) && (h.arr[child].data < h.arr[child + 1].data)) {
			child++;
		}

		//자식보다 크면 멈춤
		if (temp >= h.arr[child].data)
			break;

		//자식을 위로 올리고
		h.arr[parent].data = h.arr[child].data;
		parent = child;
		child *= 2; //다음 자식
	}
	h.arr[parent].data = temp; //올바른 위치에 temp 삽입

	return root; //제거된 루트 값 반환
}

int main(){
	int n;
	scanf("%d", &n); //N 입력

	h.size = 0; //힙 초기화

	int num;
	for (int i = 0; i < n * n; i++){
		scanf("%d", &num); 
		push(num); //힙에 삽입
	}

	//N번째 큰 수 찾기:
	while (h.size > n * n - n + 1){
		pop();
	}
	
	printf("%d", pop());//마지막으로 pop한 것
	return 0;
}
