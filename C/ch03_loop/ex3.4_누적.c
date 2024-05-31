#include <stdio.h>
// 누적합은 55
// 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = 55
int main(void){
    int tot = 0; // 누적변수
    for(int i=1 ; i<11 ; i++){
        if(i!=10){
            printf("%d + ", i);
        }else{
            printf("%d", i);
        }        
        tot += i;
    }
    printf(" = %d\n", tot);
}