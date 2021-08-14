#include<iostream>
#include<vector>


using namespace std;

 void binary(long long int, long long int);
 void oddEven(int,long long int);

 int main(){

    int n;

    cin>>n;

    vector <long long int> vec(n);

    for(int i = 0; i < n; i++){

        cin>>vec[i];
        binary(vec[i], i+1);
    }
}

void binary(long long int num, long long int i){

    long long int rest=0;

    int cont=0;

    while(num != 0){

        rest = num % 2;
        num /= 2;

        if(rest == 1){

            cont++;
        }

    }

    oddEven(cont,i);
}

void oddEven(int cont, long long i){

    //int i = 1;

    if(cont % 2 == 0){

        cout<<"Case "<<i<<": even"<<endl;
    }
    else{

         cout<<"Case "<<i<<": odd"<<endl;

    }

}


