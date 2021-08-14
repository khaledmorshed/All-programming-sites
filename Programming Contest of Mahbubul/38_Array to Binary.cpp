#include<bits/stdc++.h>

using namespace std;

int main(){

    char ar[100],i;

    double sum = 0;
    gets(ar);
    double res;
    float li;
    int len = strlen(ar);
    len = len -1;


   /* for(i = 0; i < len; i++){

        cin>>ar[i];


    }*/

    while(ar[i] != '.'){

            res = pow(2,len);
            li = std::copy(ar,ar+len,li);
            sum = sum + (li * res);
            len--;
    }
    cout<<sum<<endl;

}
