#include <bits/stdc++.h>
using namespace std;

int main(){

    //string A = "abcabd";
    vector<vector<int>>pos(3, vector<int>(3,14));
    
    cout<<"size = "<<pos.size()<<endl;
    
    for( int i = 0; i<pos.size(); i++ ) {
        for(int j=0; j<3; j++){
            cout<<pos[i][j]<<endl;
        }
        cout<<endl;
    }
    cout << endl;
    
}
