#include <stdio.h>
// 비트연산자 : &(and), |(or), ^(XOR;같으면0,다르면1)
int main(void){
    int n1 = 10; // 0 ~ 0 1 0 1 0 (8+2)
    int n2 = 6;  // 0 ~ 0 0 1 1 0 (4+2)
    //  n1 & n2  :  0 ~ 0 0 0 1 0 (2)
    //  n1 | n2  :  0 ~ 0 1 1 1 0 (14)
    //  n1 ^ n2  :  0   0 1 1 0 0 (12)
    printf("n1&n2 = %d\n", n1&n2);
    printf("n1|n2 = %d\n", n1|n2);
    printf("n1^n2 = %d\n", n1^n2);
    printf("n2 << 1 = %d\n", n2<<1); // 0 ~ 0 0 1 1 0 0  (1 shift는 2배)
    printf("n2 >> 1 = %d\n", n2>>1);
}