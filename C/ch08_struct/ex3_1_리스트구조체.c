#include <stdio.h>
struct list{
    int num;
    struct list* next;
};
int main(void){
    struct list a = {10, 0}, b={20, 0}, c={30,0};
    struct list* head = &a;
    struct list* current;
    a.next = &b;
    b.next = &c;
    printf("전체 데이터 : ");
    current = head;
    while(current){
        printf("%d\t", current->num);
        current = current->next;
    }
}
