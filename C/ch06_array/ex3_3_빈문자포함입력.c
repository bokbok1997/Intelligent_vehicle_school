#include <stdio.h>
// 주소(빈문자포함), 이름(빈문자불포함)을 입력받기
int main(void){
    // char* name; 입력받을 문자열이 저장될 공간이 확보되지 않음
    char name[128];
    char address[512];
    printf("주소 >>");
    // scanf("%s", address, sizeof(address));
    // gets(address); // 이 예제에서는 버퍼를 지울 필요 없음
    gets(address);
    printf("이름 >>");
    scanf("%s", name, sizeof(name));
    
    printf("입력한 이름 : %s\n", name);
    printf("입력한 주소 : %s\n", address);
}