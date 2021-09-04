#include<stdio.h>


int main(){
    int n, k = 0;
    scanf("%d", &n);
    int a[n], b[n*3+1];
    int endTime = 0;
    int waiting;

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    for(int i=0; i<n; i++){

        if(endTime == 0){
            b[k++] = 0;
            b[k++] = a[i];
            b[k++] = a[i] + 10;
            //printf("%d ", k);
            endTime = b[k-1];
        }
        else if(a[i] < endTime){
            b[k++] = endTime - a[i];
            b[k++] = endTime;
            b[k++] = endTime + 10;
            endTime = b[k-1];
        }
        else{
            b[k++] = 0;
            b[k++] = a[i];
            b[k++] = a[i] + 10;
            endTime = b[k-1];
        }

    }

    for(int i=0; i<n*3; i+=3){
        printf("%ds, %ds, %ds\n", b[i], b[i+1], b[i+2]);
    }
}
