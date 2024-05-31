#include <stdio.h>
// 배열안의 값을 오름차순 정렬하는 함수를 구현하시오
void sort(int* arr, int cnt); // 함수선언 (cnt:배열방의 갯수)
int main(void){
    int lotto[6] = {41, 1, 35, 20, 45, 10};
    printf("정렬전 : ");
    for(int idx=0 ; idx<6 ; idx++){
        printf("%d\t", lotto[idx]);
    }
    sort(lotto, 6);
    printf("\n정렬후 : ");
    for(int idx=0 ; idx<6 ; idx++){
        printf("%d\t", lotto[idx]);
    }
}
void sort(int* lotto, int cnt){
    for(int i=0 ; i<cnt-1 ; i++){
        for(int j=i+1 ; j<cnt ; j++){
            if(lotto[i] > lotto[j]){
                int temp = lotto[i];
                lotto[i] = lotto[j];
                lotto[j] = temp;
            }//if
        }//for - j
    }//for - i
} // sort