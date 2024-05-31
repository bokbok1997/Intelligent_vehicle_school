#include <stdio.h>
int* returnArray(int* ptr); // 선언
int main(void){
    int arr[] = {10,20,30};
    int* afterArr = returnArray(arr);
    printf("수정전 : ");
    for(int idx=0 ;idx<3 ; idx++){
        printf("arr[%d] = %d\t", idx, arr[idx]);
    }
    printf("\n수정후 : ");
    for(int idx=0 ;idx<3 ; idx++){
        //printf("afterArr[%d] = %d\t", idx, afterArr[idx]);
        printf("afterArr[%d] = %d\t", idx, *(afterArr+idx));
    }
}
int* returnArray(int* ptr){
    static int resultArr[3];
    for(int idx=0 ; idx<3 ; idx++){
        resultArr[idx] = ptr[idx];
    }
    resultArr[1] = 99;
    return resultArr;
}