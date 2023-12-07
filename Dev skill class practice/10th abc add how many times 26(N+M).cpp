#include <bits/stdc++.h>
using namespace std;
int g(string &A, string &B) {
    /*
        26(N+M)
        For each character in string A, we will store the next occurance of all characters
         from 'a' to 'z'.
        Then iterate over all characters in B and try to find it in the stored information.
    */

    vector<vector<int>> pos(A.size()+1, vector<int>(26, A.size()));
    //vector<vector<int>> vec( n , vector<int> (m, 0)); // m = 4, n = 3
//    for(int i=0; i<pos.size(); i++){
//        for(int j=0; j<pos[i].size(); j++){
//            cout<<pos[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    for (int i = A.size()-1; i >= 0; i--) {
        pos[i] = pos[i+1];
       // cout<<"pos[i] = "<<pos[i][i]<<endl;
//        for(int j=0; j<=i; j++){
//            cout<<"i = "<<pos[i][j]<<endl;
//        }
        int d = A[i]-'a';
        pos[i][d] = i;
        cout<<"pos[i][d] = "<<pos[i][d]<<" i = "<<i<<" d = "<<d<<endl;
    }

    /*for( int i = 0; i<pos.size(); i++ ) {
        for(int j=0; j<26; j++){
            cout<<pos[i][j]<<endl;
        }
        cout<<endl;
    }
    cout << endl;    */

    int cur = 0, cnt = 1, i = 0;
    while (i < B.size()) {
        int d = B[i]-'a';
        int p = pos[cur][d];
        if (p >= A.size()) {
            if (!cur) return -1;
            cur = 0;
            cnt++;
        } else {
            cur = p+1;
            i++;
        }
    }

    return cnt;
}

int main() {
    string A = "abcabd";
    string B = "abdcbaacd";
    cout << g(A, B) << endl;

    return 0;
}
