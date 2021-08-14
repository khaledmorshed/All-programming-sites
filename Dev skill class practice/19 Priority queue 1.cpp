#include<bits/stdc++.h>

using namespace std;

/*bool operator < (const int &a, int &b){
    return a < b;
}*/

void main2();
int main(){
    //by default from greater to less arranging
    priority_queue<int> pq;// this primitive int will not change with above bool operator but we can change
                            // it by creating our own data type such as stucture
    for(int i=0; i<5; i++){
        int x = rand() % 20;
        cout<<x<<" ";
        pq.push(x);
    }
    cout<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    main2();
}

void main2(){
    //by setting from small to large arranging
    cout<<"small to large : "<<endl;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<5; i++){
        int x = rand() % 20;
        cout<<x<<" ";
        pq.push(x);
    }
    cout<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}
