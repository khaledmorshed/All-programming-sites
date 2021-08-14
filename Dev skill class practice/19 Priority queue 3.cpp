
#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

/*bool operator < (const pii &a, pii &b){
    return a < b;
}*/

struct info{
    int x, y;
    info(){}
    info(int xx, int yy){
        x = xx;
        y = yy;
    }
};

bool operator < (const info &a, const info &b){
    //return (a.x == b.x && a.y > b.y) || a.x > b.x;//a.x > b.x lekha jai puratar jonno
    return (a.y == b.y && a.x > b.x) || a.y > b.y;//a.y > b.y lekha jai puratar jonno
}


int main(){
    priority_queue<info> pq;
    for(int i=0; i<10; i++){
        int x = rand() % 20;
        int y = rand() % 20;
        cout<<x<<" "<<y<<endl;
        pq.push({x,y});
    }
    cout<<endl;
    while(!pq.empty()){
        info u = pq.top();
        pq.pop();
        cout<<u.x<<" "<<u.y<<endl;
    }
    cout<<endl;
}
