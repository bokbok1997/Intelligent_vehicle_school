#include <stdio.h>
// 출력을 원하는 구구단 수를 입력(scanf)받아 해당 구구단 출력
int main(void){
    int dansu;
    printf("몇단 구구단을 출력할까요 >>");
    scanf("%d", &dansu);
    printf("%d단 구구단입니다");
    for(int i=1 ; i<10 ; i++){
        printf("%d x %d = %d\n", dansu, i, dansu*i);
    }
}