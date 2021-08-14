#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, n;
     int result1, result2;
    cin>>T;

    for(int i = 0; i < T; i++){
        cin>>n;
        bitset<38> b(n);
        result1 = b.count();

        bitset<38> bnext(++n);
        result2 = bnext.count();

        while(result1 != result2){

             bitset<38> bnext(++n);
             result2 = bnext.count();
        }

        cout<<"Case "<<i+1<<": "<<n<<endl;
    }

}
