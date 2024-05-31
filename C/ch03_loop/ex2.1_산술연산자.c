#include <stdio.h>
// 산술연산자 : + - / * %
int main(void){
    int n1 = 33, n2=10;
    printf("산술연산 결과입니다\n");
    printf("%d %c %d = %d\n", n1, '/', n2, n1/n2);
    // 형변환 : 묵시적형변환 int i = 3.2
    //          명시적형변환 (double)n1
    printf("%d %c %d = %.3lf\n", n1, '/', n2, (double)n1/n2);
    printf("%d %c %d = %d\n", n1, '%', n2, n1%n2);
    // 나머지 연산자 : 그룹을 나눌때
    if(n1%2 == 0){
        printf("n1은 짝수\n");
    }else{
        printf("n1은 홀수\n");
    }
}