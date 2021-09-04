#include<stdio.h>
#include<math.h>
int f(int n)
{
    int temp=0;
    while(n!=0){
        if((n%10)%2!=0){
            temp = (temp*10) + (n%10);
        }
        n/=10;
    }
    int rev=0;
    while(temp!=0){
        rev = (rev*10) + (temp%10);
        temp/=10;
    }
    return rev;
}
int isPrime(int n)
{
    int sqt = sqrt(n) + 2;
    int i;
    for(i=2;i<=sqt;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d. ",f(n));
    if(isPrime(f(n))){
        printf("Prime\n");
    }
    else{
        printf("Not prime\n");
    }
    return 0;
}
