#include <stdio.h>
struct vision{
    double left; 
    double right;
};
typedef struct vision Vision; // struct vision을 Vision으로 타입으로
Vision exchange(Vision robot); // 함수
int main(void){
    Vision robot;
    printf("좌 우 시력>>");
    scanf("%lf %lf", &robot.left, &robot.right);
    printf("입력된 좌우 시력 : %lf\t %lf\n", robot.left, robot.right);
    robot = exchange(robot);
    printf("좌우가 바뀐 시력 : %lf\t %lf\n", robot.left, robot.right);
}
Vision exchange(Vision robot){
    // 매개변수 robot의 left와 right exchange
    double temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;
    return robot;
}
