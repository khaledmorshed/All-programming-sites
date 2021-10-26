#include<bits/stdc++.h>
using namespace std;

int stringLen = 0;

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
                //cout<<"outside if = "<<s[j]<<" "<<s[m]<<endl;
                int subStringlen = m - j;
                //cout<<"subStirnLen = "<<subStringlen<<endl;
                for(int k = j+1, l=m-1; k<=l; k++, l--)
                {
                    if(s[k] == s[l])
                    {
                        //cout<<"Inside if = "<<s[k]<<" "<<s[l]<<endl;
                        if(k == l)
                        {
                            if(subStringlen > stringLen)
                            {
                                stringLen = subStringlen;
                                startIndex = j;
                                endIndex = m;
                            }
                        }
                        else if(k == l - 1)
                        {
                            if(subStringlen > stringLen)
                            {
                                stringLen = subStringlen;
                                startIndex = j;
                                endIndex = m;
                            }
                        }
                    }
                    else{
                       //cout<<"Inside else = "<<s[k]<<" "<<s[l]<<endl;
                       break;
                    } 

                }
            }
            else
            {
                //cout<<"outside esle = "<<s[j]<<" "<<s[m]<<endl;
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
