#include <bits/stdc++.h>

using namespace std;

int f(string &A, string &B) {
    /*
        N + MLogN
        We will store all position of all characters in string A. Then we will iterate over string B
        and look for the next character in the remaining suffix of A by doing a binary search in the
        position array of that character.
    */
    vector<int> pos[26];
    for (int i = 0; i < A.size(); i++) {
        pos[A[i]-'a'].push_back(i);
    }

    int cur = 0, cnt = 1, i = 0;
    while (i < B.size()) {
        int d = B[i]-'a';
        //in is position
        int in = lower_bound(pos[d].begin(), pos[d].end(), cur) - pos[d].begin();
        cout<<"i = "<<i<<endl;
        if (in >= pos[d].size()) {
            if (!cur) return -1;
            cur = 0;
            cnt++;
        } else {
            cur = pos[d][in]+1;
            i++;
        }
        cout<<"d = "<<d<<" in = "<<in<<" cur = "<<cur<<" cnt = "<<cnt<<endl;
        getchar();
    }

    return cnt;
}

int main() {
    string A = "abcabb";
    string B = "abcbaacbcd";
    cout << f(A, B) << endl;


    return 0;
}
