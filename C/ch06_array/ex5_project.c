#include <stdio.h>
/*유수민, 김현식, 땅땅이, 새대갈, 슘당이의 키를 입력받아 
    출력사항 : 평균 : 170.50
              최장 : 김현식 190
              최단 : 슘당이 120
*/
int main(){
    char* names[] = {"유수민","김현식","땅땅이","새대갈","슘당이"};
    int arrHeight[5];  // 친구들 키 입력 배열
    int totHeight = 0; // 키 누적변수
    int idxMin, minHeight=999; // 최단신을 구하기 위한 변수들(index, 키값)
    int idxMax, maxHeight=-1; // 최장신을 구하기 위한 변수들(index, 키값)
    // 키 입력받아 totHeight에 누적하기
    for(int idx=0 ; idx<5 ; idx++){
        printf("%s의 키는 ? ", names[idx]);
        scanf("%d", &arrHeight[idx]);
        if(arrHeight[idx]<minHeight || arrHeight[idx]>maxHeight){
            printf("키를 잘못 입력하신 것 같습니다. 다시 입력해주세요.\n");
            idx--;
            continue;
        }
        totHeight += arrHeight[idx]; // 누적
    }
    printf("\n- 평균키 : %.2lf\n", totHeight/5.0);
    for(int idx=0 ; idx<5 ; idx++){
        if(arrHeight[idx] > maxHeight){
            maxHeight = arrHeight[idx];
            idxMin = idx;
        }// if - 최대값
        if(arrHeight[idx] < minHeight){
            minHeight = arrHeight[idx];
            idxMax = idx;
        } // if - 최소값
    } // for
    printf("- 최장신 : %s\t%d\n", names[idxMax], maxHeight);
    printf("- 최단신 :  %s\t%d\n\n", names[idxMin], minHeight);
}