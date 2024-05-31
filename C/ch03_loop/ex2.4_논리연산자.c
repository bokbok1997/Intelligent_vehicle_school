#include <stdio.h>
// 논리연산자 : &&(and), ||(or), !(not)
int main(void){
    int i=1, j=10, h=10;
    // &&연산의 경우 좌항이 false인 경우 우항은 실행하지 않고 결과를 false로
    printf("(i>j) && (++j>h) = %s\n", ((i>j) && (++j>h))? "true":"false");
    printf("j = %d\n", j);
    // ||연산의 경우 좌항이 true인 경우 우항은 실행하지 않고 결과를 true로
    printf("(i<j) || (++j>h) = %s\n", ((i<j) || (++j>h))? "true":"false");

    printf("j = %d\n", j);
}