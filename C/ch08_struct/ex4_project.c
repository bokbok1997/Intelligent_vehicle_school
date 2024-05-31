#include <stdio.h>
struct student
{
    int id;
    char name[20];
    int kor;
    int eng;
    int mat;
    int tot;
    double avg;
};
typedef struct student Student; 
void print_data(Student * ps);
void sort(Student* arr);
int main(void){
    Student students[3];
    for(int idx=0 ; idx<3 ; idx++){
        printf("학번 : ");
        scanf("%d", &students[idx].id);
        printf("이름 : ");
        scanf("%s", &students[idx].name, sizeof(students[idx].name));
        printf("국어 영어 수학 : ");
        scanf("%d %d %d", &students[idx].kor, &students[idx].eng, &students[idx].mat);
        students[idx].tot = students[idx].kor + students[idx].eng + students[idx].mat;
        students[idx].avg = students[idx].tot / 3.0;
    }
    printf("정렬전 \n");
    for(int idx=0; idx<3 ; idx++){
        print_data(&students[idx]);
    }
    sort(students);
    printf("정렬후 \n");
    for(int idx=0; idx<3 ; idx++){
        print_data(&students[idx]);
    }
}
void print_data(Student * ps){
    printf("%d\t%s\t%d\t%d\t%d\t%d\t%.1lf\n", 
            ps->id, ps->name, ps->kor, ps->eng, ps->mat, ps->tot, ps->avg);
}
void sort(Student* arr){
    Student temp;
    for(int i=0 ; i<2 ; i++){
        for(int j=i+1 ; j<3 ; j++){
            if(arr[i].tot < arr[j].tot){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }// if
        }//for-j
    }//for-i
}//sort함수