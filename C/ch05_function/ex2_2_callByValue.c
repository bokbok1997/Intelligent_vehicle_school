#include <stdio.h>
// Call By Value
int sum(int from, int to); // 함수 선언
int main(void){
    int a=1, b=100; 
    int tot = sum(a, b);// sum(a, b)호출
    printf("%d부터 %d까지 누적합은 %d\n", a, b, tot);
    a = 10; b=100;
    tot = sum(a, b);
    printf("%d부터 %d까지 누적합은 %d\n", a, b, tot);
}
int sum(int from, int to){ // 함수 정의
    int result = 0;
    for(int i=from ; i<=to ; i++){
        result += i;
    }
    return result;
}