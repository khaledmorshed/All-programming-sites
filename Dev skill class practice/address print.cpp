#include<bits/stdc++.h>
using namespace std;

int main(){
    char ch1='A', ch2='B';
    int n1 = 100, n2 = 1000;

    printf("value of ch1 = %c,\t",ch1);
    printf("Address of ch1 = %p\n", &ch1);

    int a[5] = {50,60,70,80,90};
    //printf("Address of aray is %p\n", a);
    printf("Addrsss of a[0] is %p\n", &a[0]);
    printf("Addrsss of a[1] is %p\n", &a[1]);
    printf("Addrsss of a[2] is %p\n", &a[2]);
}

