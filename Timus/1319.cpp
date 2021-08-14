#include<iostream>

using namespace std;

int main(){


    int n;
    cin>>n;
    int ar[n][n];

    int i,j,l=1,k,m,n2;


    for(i = 0, j = n-1; j!=-1; j--){

        for(i = 0, k = j; k!=n; k++){

            ar[i++][k] = l++;
        }
    }

    //l = l -1;

    for(i = 1, j = n-2; i < n; i++, j--){


        for(m = i,  n2 = 0, k = 0; k <= j; k++){

            ar[m++][n2++] = l++;
        }
    }




    for(i = 0; i<n; i++){

        for(j = 0; j < n; j++){

            cout<<ar[i][j]<<" ";
        }

        if(i == n-1 && j == n-1){
            break;
        }
       // cout<<endl;
    }

}
