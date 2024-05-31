#include <stdio.h>
void swap(int a, int b); // 함수(call by value) 선언
int main(void){
    int a = 10, b=20;
    printf("swap() 호출 전 a주소=%p, a값=%d, b주소=%p, b=%d\n", &a, a, &b, b);
    swap(a, b); // 함수호출
    printf("swap() 호출 후 a주소=%p, a값=%d, b주소=%p, b=%d\n", &a, a, &b, b);
}
// 함수 구현(=함수 정의)
void swap(int a, int b){
    printf("함수안 a주소=%p, a값=%d, b주소=%p, b=%d\n", &a, a, &b, b);
    int temp = a;
    a = b;
    b = temp;
    printf("함수안 a주소=%p, a값=%d, b주소=%p, b=%d\n", &a, a, &b, b);
}