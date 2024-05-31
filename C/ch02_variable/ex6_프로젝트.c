#include <stdio.h>
//퀴즈 : 이름, 성별(남/여), 국어, 영어, 수학을 입력받아 이름, 성별, 국, 영, 수, 합, 평균(소숫점 2자리까지)을 출력하시오
int main(void) {
	char name[100], gender[3];
	int kor, eng, mat;
	int sum;
	double avg;

	printf("이름을 입력하세요 :");
	scanf_s("%s", name, (unsigned int)sizeof(name));


	printf("성별을 입력하세요(남/여) : ");
	scanf_s("%s", gender, (unsigned int)sizeof(gender));

	printf("국어 영어 수학 점수를 입력하세요 : ");
	scanf_s("%d %d %d", &kor, &eng, &mat);
	sum = kor + eng + mat;
	avg = sum / 3.0;

	printf("이름 : %s\n성별 : %s\n", name, gender);
	printf("국어 = %d\n", kor);
	printf("영어 = %d\n", eng);
	printf("수학 = %d\n", mat);
	printf("합계 = %d\n", sum);
	printf("평균 = %.2lf\n", avg);
}