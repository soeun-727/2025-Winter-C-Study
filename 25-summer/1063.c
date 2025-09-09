#include <stdio.h>
#include <string.h>

//입력값에 맞게 이동시키는 함수 
void update(char King[3], char Rock[3], const char Move[3]){
    //int값으로 변경
    int x = King[0] - 'A';
    int y = King[1] - '1';
    int rx = Rock[0] - 'A';
    int ry = Rock[1] - '1';
    if (strcmp(Move, "R") == 0) x++;
    else if (strcmp(Move, "L") == 0) x--;
    else if (strcmp(Move, "B") == 0) y--;
    else if (strcmp(Move, "T") == 0) y++;
    else if (strcmp(Move, "RT") == 0) { x++; y++; }
    else if (strcmp(Move, "LT") == 0) { x--; y++; }
    else if (strcmp(Move, "RB") == 0) { x++; y--; }
    else if (strcmp(Move, "LB") == 0) { x--; y--; }

    //킹이 체스판 넘어가지 않는지 확인
    if (x >= 0 && x < 8 && y >= 0 && y < 8){ 
        //돌이랑 같은 위치인 경우
        if (x==rx && y==ry){
            //돌을 동일한 방향으로 이동시키기
            if (strcmp(Move, "R") == 0) rx++;
            else if (strcmp(Move, "L") == 0) rx--;
            else if (strcmp(Move, "B") == 0) ry--;
            else if (strcmp(Move, "T") == 0) ry++;
            else if (strcmp(Move, "RT") == 0) { rx++; ry++; }
            else if (strcmp(Move, "LT") == 0) { rx--; ry++; }
            else if (strcmp(Move, "RB") == 0) { rx++; ry--; }
            else if (strcmp(Move, "LB") == 0) { rx--; ry--; }
            
            //돌이 체스판 넘어가지 않는지 확인
            if (rx >= 0 && rx < 8 && ry >= 0 && ry < 8){
                Rock[0] = rx + 'A'; 
                Rock[1] = ry + '1';  
                King[0] = x + 'A'; 
                King[1] = y + '1'; 
            }
        } else { //돌과 겹치지 않는 경우 킹만 이동
            King[0] = x + 'A'; 
            King[1] = y + '1'; 
        }
    }
}

int main(){
    char king[3], rock[3]; //초기 위치
    int N; //이동 횟수
    scanf("%s %s %d", king, rock, &N);

    while(N--){ //이동 횟수만큼 이동 방향 입력받기
        char move[3];
        scanf("%s", move);
        update(king, rock, move); //이동시키기
    }

    printf("%s\n%s\n", king, rock);
}