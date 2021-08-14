#include<bits/stdc++.h>

using namespace std;

int cas = 1;

void print(int numberOflie){

cout<<"Case "<<cas++<<": "<<numberOflie<<endl;
}

void  calculatingLieNumber(int n, vector<int> &v){

    int N;

    for(int i = 0; i < n; i++){

        cin>>N;
        v.push_back(N);
    }


        int dif_number, sum = 0, lie;

            dif_number = v[0] - 2;

            if(dif_number == 0){

                sum = sum + 0;
            }
            else if(dif_number > 5){

                lie = dif_number / 5;

                if(dif_number % 5 == 0){

                    sum = sum + lie;
                }
                else{
                    sum = sum + lie + 1;
                }
            }

            else{
                sum = sum + 1;
            }


    for(int i = 1; i < n; i++){


            dif_number = v[i] - v[i-1];

            if(dif_number == 0){

                continue;
            }
            else if(dif_number > 5){

                lie = dif_number / 5;

                if(dif_number % 5 == 0){

                    sum = sum + lie;
                }
                else{
                    sum = sum + lie + 1;
                }
            }

            else{
                sum = sum + 1;
            }
    }


    print(sum);

}

int main(){

    int T, n;

    cin>>T;

    while(T){

        cin>>n;
        vector<int> v;

        calculatingLieNumber(n, v);

        T--;
    }

}
