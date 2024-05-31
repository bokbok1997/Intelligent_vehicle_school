#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2) ;
int main(void){
    srand((unsigned int) time(NULL)); // 난수 초기화 
    int answer;
    int level;
    for(level=1 ; level<=3 ; level++){
        int num1 = getRandomNumber(level);
        int num2 = getRandomNumber(level);
        showQuestion(level, num1, num2);
        scanf("%d", &answer); 
         if(answer == num1*num2){
            printf("%d단계 정답입니다\n", level);
        }else{
            printf("%d단계 오답입니다. 실패 종료입니다\n\n", level);
            break;
        } // if
    }// for
    if(level>3){
        printf("3단계까지 잘 오셨습니다. 성공입니다\n\n");
    }
}
int getRandomNumber(int level){
    //1레벨은 1~4/2레벨은 5~8/3레벨은 9~12
    return (rand()% 4 +1) + (level-1)*4;
}
void showQuestion(int level, int num1, int num2){
    printf("\n%d레벨 구구단을 외자~\n", level);
    printf("힌트 : %d x %d >>  ", num1, num2);
}