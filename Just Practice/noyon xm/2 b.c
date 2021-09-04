#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    for(int i=0; i<n; i++){
        //printf("%d ", a[i]);
        if(a[i] <= 100){
            printf("Roadside\n");
        }
        else if(a[i] >= 250 && a[i] < 350){
            printf("Fast Food\n");
        }
        else if(a[i] >= 350){
            printf("Kacchi\n");
        }
        else{
            printf("BFC\n");
        }
    }


}
