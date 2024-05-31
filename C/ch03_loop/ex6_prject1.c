#include <stdio.h>
int main(void){
    int from=2, to=7;
    for(int i=1 ; i<10 ; i++){
        for(int dansu=from ; dansu<=to ; dansu++){
            printf("%d x %d = %d\t", dansu, i, dansu*i);
        }
        printf("\n");
    }
}