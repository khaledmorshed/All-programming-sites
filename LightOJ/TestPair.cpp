#include<iostream>
#include<utility>

using namespace std;

int main(){


    pair <int, int > p[10];
    int j = 10;

    for(int i = 1; i <= 10; i++){


        p[i]=make_pair(i, j--);
    }

    for(int i = 1; i<=10; i++){

        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
}
