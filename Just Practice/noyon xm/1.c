#include<stdio.h>
int hello(arg1)
{
    if(arg1%2!=0){
        arg1++;
    }
    else{
        arg1+=3;
    }
    if(arg1>=15){
        return 99;
    }
    else{
        printf("%d\n",hello(arg1));
    }
    return arg1;
}
int main()
{
    int last_digit = 3;
    hello(last_digit);
    return 0;
}
