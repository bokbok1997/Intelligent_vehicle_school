#include <stdio.h>
//구조체 : 여러 형태의 데이터를 하나의 단일 자료형으로 
struct student { // 구조체를 정의
    int num;      // 학번(student 구조체 멤버)
    double grade; // 학점(student 구조체 멤버)
};
int main(void){
    int i;
    struct student s1;
    i = 1;
    s1.num = 101;
    s1.grade = 4.43;
    printf("학번 = %d, 학점 = %.2lf\n", s1.num, s1.grade);
}