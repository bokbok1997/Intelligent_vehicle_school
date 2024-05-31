#include <stdio.h>

int main(void){
    int floor = 4 ;
    printf("몇단 피라미드를 쌓을까요(5~20)?");
    scanf("%d", &floor);
    for(int i=0 ; i<floor ; i++){
        for(int j=i ; j<floor ; j++){
            printf(" "); //빈칸 출력
        }
        for(int k=0 ; k<i*2+1 ; k++){
            printf("*");
        }
        printf("\n");
    }
}