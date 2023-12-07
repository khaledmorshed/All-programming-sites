#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long int
using namespace std;

struct info{
    int x, y;
    info(){}
    info(int xx, int yy){
        x = xx;
        y = yy;
    }
};

bool operator < (const info &a, const info &b){
   // return a.x > b.x;
    return a.y > b.y;

}

int main(){
    priority_queue<info>pq;
    for(int i=0; i<5;i++){
        int x = rand() % 20;
        int y = rand() % 20;
        cout<<x<<"  "<<y<<endl;
        pq.push({x, y});
    }
    cout<<endl;
    for(int i=0; i<5; i++){
        info top = pq.top();
        pq.pop();
        cout<<top.x<<"  "<<top.y<<endl;
    }
}
