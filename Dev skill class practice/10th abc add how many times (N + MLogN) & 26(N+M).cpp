
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

//     for(int i = 0; i < A.size()+1; i++)
//    {
//        for(int j = 0; j < 26; j++)
//        {
//            cout << pos[i][j] << " ";
//        }
//        cout<< endl;
//    }

    for (int i = A.size()-1; i >= 0; i--) {
        pos[i] = pos[i+1];
        int d = A[i]-'a';
        cout<<"i = "<<i<<", d = "<<d<<endl;
        pos[i][d] = i;
    }


    for(int i=0; i<=A.size(); i++){
        for(int j=0; j<26; j++){
            cout<<pos[i][j]<<" ";
        }
        cout<<endl;
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
    string A = "abcabdm";
    string B = "abdcbaacdm";
    cout << f(A, B) << endl;
    cout << g(A, B) << endl;

    return 0;
}

int main1()
{
	int gfg[] = { 5, 5, 5, 6, 6, 6, 7, 7 };

	vector<int> v(gfg, gfg + 8); // 5 5 5 6 6 6 7 7

	//vector<int>::iterator lower, upper;
	int lower = lower_bound(v.begin(), v.end(), 6) - v.begin();
	int upper = upper_bound(v.begin(), v.end(), 6)- v.begin();

	cout << "lower_bound for 6 at index "
		<< lower << '\n';
	cout << "upper_bound for 6 at index "
		<< upper << '\n';

	return 0;
}
