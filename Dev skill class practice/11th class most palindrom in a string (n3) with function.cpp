#include<bits/stdc++.h>
using namespace std;

int stringLen = 0;

bool isPalindrom(string s, int j, int m){
    //cout<<"subStirnLen = "<<subStringlen<<endl;
    for(int k = j, l=m; k<=l; k++, l--)
    {
        if(s[k] == s[l])
        {
            //cout<<"Inside if = "<<s[k]<<" "<<s[l]<<endl;
            if(k == l)
            {
               return true;
            }
            else if(k == l - 1)
            {
                return true;
            }
        }
        else{
           break;
        }

    }
    return false;
}

int main()
{
    string s;
    cin>>s;
    int startIndex;
    int endIndex;
    //cout<<a<<endl;
    //abcdedcnmam
    for(int i=0; i<s.size(); i++)
    {
        for(int j=i, m=s.size()-1; j<=m; m--)
        {
            if(s[j] == s[m])
            {
                int subStringlen = m - j;
                if(isPalindrom(s, j+1, m-1)){
                    if(subStringlen > stringLen)
                    {
                        stringLen = subStringlen;
                        startIndex = j;
                        endIndex = m;
                    }
                }
            }
        }
    }

    cout<<endl<<"most palindrom substring = ";
    for(int i=startIndex; i<=endIndex; i++)
    {
        cout<<s[i];
    }
    //cout<<"most palindrom substring = "<<
    cout<<endl;
}

