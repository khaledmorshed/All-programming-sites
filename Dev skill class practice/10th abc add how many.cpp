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

/*
//good coding instead of above
#include<bits/stdc++.h>
using namespace std;

int main(){
    //a = abcbadc
    //b = cab
    string a, b;
    cin>>a>>b;

    int len1 = a.length();
    int len2 = b.length();
    int i = 0, j = 0;
    int cnt=0;
    bool check;
    while(i<len1){
        check = false;
        for(int j=0; j<len2; j++){
            if(a[i] == b[j]){
                i++;
                check = true;
            }
        }
        if(check == false){
            cout<<"not possible"<<endl;
            break;
        }
        cnt++;
    }
    if(check)
    cout<<cnt<<endl;
}

*/
