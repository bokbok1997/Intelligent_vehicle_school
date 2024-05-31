#include <stdio.h>
int main(void){
    int j=1;
    // for(int i=1 ;  ; j++){
    //     printf("%d", i);
    // }
    while(1){
        printf("%d", j++);
        if(j==5){
            break;
        }
    }
}