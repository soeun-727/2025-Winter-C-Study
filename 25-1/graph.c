#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define OFFSET 100000      // 좌표 음수값을 처리하기 위해 큰 값으로 좌표를 이동시킴
#define SIZE 200001        // 좌표 전체 크기 (OFFSET * 2 + 1)
#define HASH_SIZE 1000003  // 해시 테이블 크기 (소수로 설정하여 충돌 최소화)

// 2차원 좌표를 나타내는 구조체
typedef struct Point {
    int x, y;
} Point;

// 간선을 나타내는 구조체 (사용 안 했지만 구조상 정의됨)
typedef struct Edge {
    Point from, to;
} Edge;

// 해시 테이블에 쓰일 연결 리스트 노드
typedef struct Node {
    unsigned long long key;  // 해시 키 (좌표나 간선을 표현한 숫자)
    struct Node* next;       // 다음 노드 포인터 (충돌 시 체이닝)
} Node;

Node* node_visited[HASH_SIZE];  // 방문한 점(좌표) 저장용 해시 테이블
Node* edge_visited[HASH_SIZE];  // 방문한 간선 저장용 해시 테이블

// 방향 벡터 (문제의 방향에 맞게 조정됨)
// 0: 위, 1: 오른쪽 위, 2: 오른쪽, 3: 오른쪽 아래, 4: 아래, 5: 왼쪽 아래, 6: 왼쪽, 7: 왼쪽 위
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

// 점 좌표 (x,y)를 하나의 64비트 숫자로 변환하여 고유 키 생성
unsigned long long hash_point(int x, int y) {
    return ((unsigned long long)(x + OFFSET)) * SIZE + (y + OFFSET);
}

// 두 점 좌표를 이용해 간선의 고유 키 생성
// 두 점 순서에 상관없이 같은 간선으로 인식하도록 작은 값을 왼쪽 32비트, 큰 값을 오른쪽 32비트에 저장
unsigned long long hash_edge(int x1, int y1, int x2, int y2) {
    unsigned long long a = hash_point(x1, y1);
    unsigned long long b = hash_point(x2, y2);
    return a < b ? (a << 32) | b : (b << 32) | a;
}

// 해시 테이블에서 key가 이미 방문했는지 확인
bool is_visited(Node** visited, unsigned long long key) {
    int index = key % HASH_SIZE;  // 해시 인덱스 계산
    Node* node = visited[index];
    while (node) {
        if (node->key == key) return true;  // 이미 방문한 키 발견
        node = node->next;
    }
    return false;  // 방문하지 않은 키
}

// 해시 테이블에 key를 방문 기록으로 추가
void add_visit(Node** visited, unsigned long long key) {
    int index = key % HASH_SIZE;
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = visited[index];  // 기존 체인 앞에 삽입
    visited[index] = new_node;
}

// 해시 테이블 메모리 해제 함수
void free_visited(Node** visited) {
    for (int i = 0; i < HASH_SIZE; ++i) {
        Node* node = visited[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
        visited[i] = NULL;
    }
}

// 문제 풀이 핵심 함수
int solution(int arrows[], size_t arrows_m) {
    int x = 0, y = 0;        // 시작점 (0,0)
    int answer = 0;          // 방 개수 카운트

    // 시작점 방문 기록 추가
    add_visit(node_visited, hash_point(x, y));

    // 화살표 방향 배열 순회
    for (size_t i = 0; i < arrows_m; ++i) {
        int dir = arrows[i];

        // 한 칸 이동을 2번으로 나누어 중간 좌표도 방문 처리 (교차점 처리용)
        for (int j = 0; j < 2; ++j) {
            int nx = x + dx[dir];  // 다음 점 x좌표
            int ny = y + dy[dir];  // 다음 점 y좌표

            // 현재 점과 다음 점을 잇는 간선의 해시 키
            unsigned long long edge = hash_edge(x, y, nx, ny);

            // 다음 점의 해시 키
            unsigned long long np = hash_point(nx, ny);

            // 이미 방문한 점인데, 새로운 간선을 처음 방문하는 경우 -> 새로운 방 생성 가능성 있으므로 answer 증가
            if (is_visited(node_visited, np) && !is_visited(edge_visited, edge)) {
                answer++;
            }

            // 방문하지 않은 점은 방문 기록 추가
            if (!is_visited(node_visited, np)) {
                add_visit(node_visited, np);
            }
            // 간선은 항상 방문 기록 추가(중복 추가 방지)
            if (!is_visited(edge_visited, edge)) {
                add_visit(edge_visited, edge);
            }

            // 좌표 업데이트
            x = nx;
            y = ny;
        }
    }

    // 사용한 메모리 해제
    free_visited(node_visited);
    free_visited(edge_visited);

    return answer;  // 방 개수 반환
}
