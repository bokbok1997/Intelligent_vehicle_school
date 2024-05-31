#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// 배열안의 값을 오름차순 정렬하는 함수를 구현하시오
void sort(int* arr); // 6개 방 배열의 값을 오름차순 정렬
int* make_lotto(); // 중복되지 않은 로또 번호 6개 배열방 return
int main(void){
    int* lotto = make_lotto();
    sort(lotto);
    printf("생성된 로또번호 : ");
    for(int idx=0 ; idx<6 ; idx++){
        printf("%d\t", lotto[idx]);
    }
}
int* make_lotto(){
    static int lotto[6];
    srand((unsigned int) time(NULL)); // 난수 초기화 
    // for(int i=0 ; i<6 ; i++){
    //     lotto[i] = rand()%45 +1;
    // }
    int i = 0;
    while(i<6){
        int temp = rand()%45 + 1; // 난수 뽑음
        int duplication_check = 1;
        for(int idx=0 ; idx<i ; idx++){ // 뽑은 난수가 중복된 게 있는지 확인
            if(temp == lotto[idx]){
                printf("%d번째에서 중복된 수(%d) 뽑아서 다시 뽑음\n", idx, temp);
                duplication_check = 0;
                break;
            }
        }//for - 중복확인
        if(duplication_check){
            lotto[i] = temp;
            i++;
        }//if
    }//while
    return lotto;
}
void sort(int* lotto){
    for(int i=0 ; i<5 ; i++){
        for(int j=i+1 ; j<6 ; j++){
            if(lotto[i] > lotto[j]){
                int temp = lotto[i];
                lotto[i] = lotto[j];
                lotto[j] = temp;
            }//if
        }//for - j
    }//for - i
} // sort