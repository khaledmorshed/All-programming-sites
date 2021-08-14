#include<bits/stdc++.h>
using namespace std;

int main()
{
    string A, B;
    cin>>A>>B;
    int cnt=0;
    int i = 0, k = 0, j = 0;
    while(i < A.size())
    {
        k = i;
        j = 0;
        while(j < B.size())
        {
            if(A[i] == B[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }


        if(i == k && j == B.size()){
            cout<<"j = "<<j<<" B.siz = "<<B.size()<<endl;
            cout<<"NO subsequence"<<endl;
            break;
        }

        cnt++;
        if(i == A.size()){
            cout<<"Added "<<cnt<<" times"<<endl;
            break;
        }

    }

    //cout<<"Added "<<cnt<<" times"<<endl;
}
