#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

//ei rokom kora jai but hocce na..amra ekhane priority_queue er functionality change korte chailcilam
/*bool operator < (const pii &a, pii &b){
    return a < b;
}*/

void main2();
int main(){
    // by default return first value of priority queue;
    priority_queue<pii> pq;
    for(int i=0; i<10; i++){
        int x = rand() % 20;
        int y = rand() % 20;
        cout<<x<<" "<<y<<endl;
        pq.push({x,y});
    }
    cout<<endl;
    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        cout<<u.first<<" "<<u.second<<endl;
    }
    cout<<endl;
    main2();
}

void main2(){
    //by setting from small to large choosing first value of priority queue;
    cout<<"small to large : "<<endl;
     priority_queue<pii, vector<pii>, greater<pii>> pq2;
    for(int i=0; i<10; i++){
        int x = rand() % 20;
        int y = rand() % 20;
        cout<<x<<" "<<y<<endl;
        pq2.push({x,y});
    }
    cout<<endl;
    while(!pq2.empty()){
        pii u = pq2.top();
        pq2.pop();
        cout<<u.first<<" "<<u.second<<endl;
    }
    cout<<endl;
}
