#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void){
    srand((unsigned )time(NULL)); // 난수 초기화 
    int min = 1, max = 100;
    int answer; // 답변할 숫자를 저장할 변수
    int change = 5; // 답변 기회를 5번으로 설정. 답변할 때마다 1씩 차감
    int computerNumber = rand() % max + 1; // 1~100까지의 난수 
    printf("정답 : %d\n", computerNumber); // 실습이므로 정답 출력
    while(1){
        // 숫자입력받기
        printf("%d부터 %d 사이의 숫자를 맞춰 보세요(남은 기회 : %d번)", min, max, change--);
        scanf("%d", &answer);
        // 입력한 숫자에 따라 메세지 출력
        if(answer < min || answer > max){
            printf("수의 범위를 잘 보고 숫자를 입력하세요\n\n");
        }else if(answer>computerNumber){
            // 정답보다 입력한 숫자가 클 때 : DOWN ↓
            printf("DOWN ↓\n\n");
            max = answer-1;
        }else if(answer<computerNumber){
            // 정답보다 입력한 숫자가 작을 때 : UP ↑
            printf("UP ↑\n\n");
            min = answer+1;
        }else{
            printf("%d는 정답입니다. 축하합니다. %d번만에 성공\n\n", answer, 5-change);
            break;
        } // if - 정답비료
        if(change==0){
            // 실패 안내문구 : 모든 기회를 사용했어요. 아쉽게도 실패했습니다.
            printf("5번의 모든 기회를 사용했어요. 아쉽게도 실패했습니다\n\n");
            break;
        } // if - 5번 기회 여부
    } // while
}//main