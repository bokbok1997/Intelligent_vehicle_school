#include <stdio.h>
#include <string.h>
int main(void){
    int i=10;
    int j=i;
    i = 99;
    printf("i=%d\tj=%d\n", i, j);
    char* str1 = "Hello";
    char* str2;// = str1; // str1의 주소를 str2에 할당(얕은 복사)
    strcpy(str2, str1); // str1의 문자열을 str2에 깊은 복사
    str1 = "Hi";// str1의 문자열이 바뀌면 str1의 기존문자 버리고 
                // 새로운 공간에 문자열 저장
    printf("str1=%s\t str2=%s\n", str1, str2);
}
