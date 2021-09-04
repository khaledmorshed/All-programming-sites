#include <bits/stdc++.h>
using namespace std;

int f(string &A, string &B) {
    vector<int> pos[26];
    for (int i = 0; i < A.size(); i++) {
        pos[A[i]-'a'].push_back(i);
    }
    cout<<"a = "<<66<<endl;

}


int main() {
    string B = "abdcbaacd";
    string A = "abcabd";
    cout << f(A, B) << endl;

    return 0;
}

