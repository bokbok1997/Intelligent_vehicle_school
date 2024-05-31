#include <stdio.h>
struct GameInfo{
    char* name;
    int year;
    int price;
};
int main(void){
    struct GameInfo gameInfo1;
    gameInfo1.name = "사이버C";
    gameInfo1.year = 2024;
    gameInfo1.price = 33000;
    struct GameInfo* gamePtr = &gameInfo1;
    printf("게임정보(gameInfo1) 출력\n");
    printf("게임이름 : %s\n", gameInfo1.name);
    printf("출시연도 : %d\n", gameInfo1.year);
    printf("게임가격 : %d\n", gameInfo1.price);

    printf("게임정보(gamePtr포인터변수) 출력\n");
    printf("게임이름 : %s\n", (*gamePtr).name);
    printf("출시연도 : %d\n", (*gamePtr).year);
    printf("게임가격 : %d\n", (*gamePtr).price);

    printf("게임정보(gamePtr포인터변수) 출력\n");
    printf("게임이름 : %s\n", gamePtr->name);
    printf("출시연도 : %d\n", gamePtr->year);
    printf("게임가격 : %d\n", gamePtr->price);
}