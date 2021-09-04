
/*
Given string A and B of length N and M,
you can concate string A together for x times and get the string B
as a subsequence of the concatenated string. Minimize x and return it's value.
If there is no solution, then return -1.
example:
A: abcabd
B: abdcbaacd
if you concate A 4 times, it becomes (ab)cab(d)ab(c)a(b)d(a)bc(a)bdab(c)ab(d)
*/

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
    //cout<<"A..size = "<<A.size()<<endl;
    int cur = 0, cnt = 1, i = 0;
    while (i < B.size()) {
        int d = B[i]-'a';
        //cout<<"B_ar = "<<d<<endl;
        //auto it = lower_bound(pos[d].begin(), pos[d].end(), cur);
        //cout<<"it = "<<*it<<endl;
        int in = lower_bound(pos[d].begin(), pos[d].end(), cur) - pos[d].begin();
        //cout<<"low_pos(in) = "<<in<<endl;
        //cout<<"pos[d].size = "<<pos[d].size()<<endl;
        //if(in > pos[d].size()) return -1;
        if (in >= pos[d].size()) {
                cout<<"Again cur = "<<cur<<endl;
            if (!cur) return -1;
            cur = 0;
            cnt++;
            //cout<<"cnt = "<<cnt<<endl;
        } else {
            cur = pos[d][in]+1;
            //cout<<"cur = "<<cur<<endl;
            i++;
        }
        //getchar();
    }

    return cnt;
}


int main() {
    string B = "abfdcbaacd";
    string A = "abcabd";
    cout << f(A, B) << endl;

    return 0;
}

