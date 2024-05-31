#include <stdio.h>
// 배열(array) : 동일 자료형의 집합
int main(void){
    // 배열 선언과 초기화를 한번
    // 배열의 크기를 생략하지 않으면 그 방 갯수만큼 메모리 잡힘
    int subway[10] = {30,40,50}; // 나머지 공간에는 0으로
    for(int idx=0 ; idx<10 ; idx++){
        printf("subway[%d]=%d\n", idx, subway[idx]);
    }
}