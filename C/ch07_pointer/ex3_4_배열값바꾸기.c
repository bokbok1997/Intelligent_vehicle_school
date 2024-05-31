#include <stdio.h>
//void changeArray(int ptr[3]);
void changeArray(int* ptr);
int main(void){
    int arr[3] = {10,20,30};
    changeArray(arr);
    for(int idx=0 ; idx<3 ; idx++){
        printf("arr[%d] = %d\n", idx, *(arr+idx));
    }
    printf("%p\n", arr);
}
void changeArray(int* ptr){
    ptr[1] = 99;
    *(ptr+1) = 99;
}