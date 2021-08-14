#include<bits/stdc++.h>
using namespace std;


int main(){

   // int shorter = 0, taller = 0;

    long long ladyHeight;
    int N;
    char shorterString='x', tallerString = 'X';
    cin>>N;
    vector<long long int> ladyChimp[N+1];

    for(int i = 1; i <= N; i++){
        cin>>ladyHeight;
        ladyChimp[i].push_back(ladyHeight);
    }

    ladyChimp[0].push_back(-10);
    auto shorter = ladyChimp[0].begin();

    long long int luchuHeight;
    int Q;
    cin>>Q;
    vector<long long int> luchu[Q];

    for(int i = 0; i < Q; i++){
        cin>>luchuHeight;
        luchu[i].push_back(luchuHeight);
    }


    //nested loop
    for(int i = 0; i < Q; i++){
        //auto shorter = ladyChimp[0].begin();
        //find shorter value
        for(int j = 1; j <= N;  j++){
            if(luchu[i] == ladyChimp[j] || luchu[i] < ladyChimp[j]){
                  shorter = ladyChimp[j-1].begin();
                if(*shorter == -10){
                    shorterString = 'X';
                    break;
                }
                break;
            }
            else if(luchu[i] > ladyChimp[N]){
                shorter = ladyChimp[N].begin();
                break;
            }
        }


        //find taller value
        auto taller = ladyChimp[0].begin();
        for(int j = 1; j <= N;  j++){
            if(luchu[i] < ladyChimp[j]){
                taller = ladyChimp[j].begin();
                break;
            }
        }


        //print function
        if(*shorter > 0 && *taller > 0){
           cout<<*shorter<<" "<<*taller<<endl;
        }

        else if(*shorter > 0 && tallerString =='X'){
             cout<<*shorter<<" "<<tallerString<<endl;
        }

        else if(*taller > 0 && shorterString =='X'){
            cout<<shorterString<<" "<<*taller<<endl;
        }

    }
    //nested finished up at }

}
