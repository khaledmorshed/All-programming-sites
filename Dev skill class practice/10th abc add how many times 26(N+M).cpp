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
        int in = lower_bound(pos[d].begin(), pos[d].end(), cur) - pos[d].begin();
        if (in >= pos[d].size()) {
            if (!cur) return -1;
            cur = 0;
            cnt++;
        } else {
            cur = pos[d][in]+1;
            i++;
        }
    }

    return cnt;
}

int g(string &A, string &B) {
    /*
        26(N+M)
        For each character in string A, we will store the next occurance of all characters from 'a' to 'z'.
        Then iterate over all characters in B and try to find it in the stored information.
    */

    vector<vector<int>> pos(A.size()+1, vector<int>(26, A.size()));
    for (int i = A.size()-1; i >= 0; i--) {
        pos[i] = pos[i+1];
        int d = A[i]-'a';
        pos[i][d] = i;
    }

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
    cout << f(A, B) << endl;
    cout << g(A, B) << endl;

    return 0;
}

