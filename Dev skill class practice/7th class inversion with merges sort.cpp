#include<bits/stdc++.h>

using namespace std;

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
            inverse = inverse + mid - i;
        }
    }
    while(i<mid) t[k++] = A[i++];
    while(j<ed) t[k++] = A[j++];

    for(int p=st, q=0; p<ed; p++,q++)
    {
        A[p] = t[q];

    }
}

void merges(int st, int ed)
{
    if(st == ed-1)
    {
        return;
    }
    int md = (st+ed)/2;
    merges(st, md);
    merges(md, ed);
    mergesort(st, ed);
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
    cout<<inverse<<endl;
}


