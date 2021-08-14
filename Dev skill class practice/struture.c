#include <stdio.h>
#include <string.h>
int s = 1;
struct student{

    int id;
    string str;
    double gpa;
};
int main(){

        struct student st[1000];
        int n;
        printf("Enter value for n : ");
        scanf("%d", &n);

        for(int i = 0; i < n*n; i){
            scanf("%d %s %lf", &st[i].id, &st[i+1].str, &st[i+2].gpa);
            i = i+3;
        }

        for(int i = 0; i<n*n; i){
            printf("student : %d\n id : %d\n Name : %s\n Gpa : %.5lf\n\n", s++, st[i].id, st[i+1].str, st[i+2].gpa);
            i = i + 3;
        }
}
