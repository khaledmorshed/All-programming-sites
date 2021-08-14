#include<bits/stdc++.h>

using namespace std;

int cas = 1;

void multiply(int* a, int D, int n){

    for(int i = 0; i < n; i++){

        a[i] = a[i] * D;
    }

}

void Addition(int* a, int D, int n){

    for(int i = 0; i < n; i++){

        a[i] = a[i] + D;
    }

}

void division(int* a, int K, int n){

    for(int i = 0; i < n; i++){

            a[i] = a[i] / K;
    }
}

void prinAray(int* a, int n){

     int i, j=1;
     cout<<"Case "<<cas++<<":"<<endl;
     for(i = 0; i < n-1; i++){

        cout<<a[i]<<" ";
     }

     cout<<a[n-1]<<endl;

 }

int main(){

    char ch;
    int T;



    cin>>T;

    while(T>0){

            int  n, m;

        cin>>n>>m;

        int *a = (int*)malloc(n*sizeof(int));

        for(int i = 0; i < n; i++){

            cin>>a[i];
        }




        for(int i = 0; i < m; i++){

                int D,M,Y,Z,K;

                  cin>>ch;

            if(ch == 'P'){

                cin>>Y>>Z;
                swap(a[Y],a[Z]);
               // prinAray(a,n);
            }

            else if(ch == 'M'){

                cin>>D;
                multiply(a, D, n);
                //prinAray(a,n);
            }

            else if(ch == 'S'){
                cin>>D;
                Addition(a, D, n);
                //prinAray(a,n);
            }

            else if(ch == 'D'){

                cin>>K;
                division(a, K, n);
                //prinAray(a,n);
            }

            else if(ch == 'R'){

                reverse(a, a + n);
                //prinAray(a,n);
            }
        }

        prinAray(a,n);
        T--;
    }

}


