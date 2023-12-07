#include<bits/stdc++.h>

using namespace std;

//int A[9]= {15,5,24,8,1,3,16,10,20}, t[100005], l = 1, inverse=0;

/**
/// sort( A[st...ed) )
///

0 1 2 3 4 5 6 7
_______ _______
a b c d e f g h
sort(0, 8)
sort(0, 4)
sort(4, 8)

*/

int A[100005], t[100005], l = 1, inverse=0;

void mergesort(int st, int ed)
{
    int mid = (st+ed)/2;
    int i=st, j=mid, k=0;
    while(i<mid && j<ed)
    {
        if(A[i] <= A[j])
        {
            t[k++] = A[i++];
        }
        else{
            t[k++] = A[j++];
        }
    }
    while(i<mid) t[k++] = A[i++];
    while(j<ed) t[k++] = A[j++];

    for(int p=st, q=0; p<ed; p++,q++)
    {
        A[p] = t[q];

    }
    cout<<"array = ";
    for(int i=st; i<ed; i++) cout<<A[i]<<" ";
    cout<<endl;
}

void merges(int st, int ed)
{
    cout<<" ha "<<endl;
    if(st == ed-1)
    {
        //cout<<st<<" st ed "<<ed<<" return "<<endl;
        return;
    }

    //cout<<st<<"  "<<ed<<endl;
    int md = (st+ed)/2;
    // ed = md;

    //cout<<" merge1(st, md)  "<<" merge1( "<<st<<", "<<md<<")"<<endl;
    merges(st, md);
    cout<<"I am here"<<endl;
    //cout<<" merge2(md, ed)  "<<" merge2( "<<md<<", "<<ed<<")"<<endl;
    merges(md, ed);
    cout<<"I am here 2"<<endl;
    //cout<<" mergesort(st, ed)  "<<" mergesort( "<<st<<", "<<ed<<")"<<endl;
    mergesort(st, ed);
    //cout<<" ses "<<endl;


    //cout<<l++<<" first = "<<st<<" "<<md<<endl;
    //cout<<" mid1 = "<<md<<endl;

    //cout<<l++<<" second = "<<st<<" "<<ed<<endl;
    //cout<<" mid = "<<md<<endl;

    //cout<<l++<<" second = "<<st<<" "<<ed<<endl;
}

int main()
{

    srand(time(NULL));
    int n;
    cin>>n;
    //n = 9;

    for(int i=0; i<n; i++)
    {   A[i] = rand() % 20 + 1;
        //cin>>A[i];

    }
    for(int i=0; i<n; i++) cout<<A[i]<<" ";
    cout<<endl;
    merges(0, n);
    for(int i=0; i<n; i++) cout<<A[i]<<" ";
    cout<<endl;
}
