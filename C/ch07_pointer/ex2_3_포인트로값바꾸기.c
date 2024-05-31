#include <stdio.h>
int main(void){
    int a = 1, b=2;
    int* pointer;
    pointer = &a;
    *pointer *= 3; // *pointer = *pointer * 3 (a 수정)
    pointer = &b;
    *pointer *= 3; // b수정
    printf("a변수 : %d\n", a);
    printf("b변수 : %d\n", b);
    printf("pointer변수가 가르키는 주소 : %p, 값:%d\n", pointer, *pointer);
    printf("a변수 주소 : %p\n", &a);
    printf("b변수 주소 : %p\n", &b);
}