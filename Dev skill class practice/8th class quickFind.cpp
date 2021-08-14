#include<bits/stdc++.h>
using namespace std;

int n, k, A[10004];

int rando(int a, int b)
{
    int sz = b - a + 1;
    return rand() % sz + a;
}

int _partition(int st, int ed, int pv)
{
    int i = st, j = ed-1;
    while(i < j)
    {
        if(A[i] < pv) i++;
        else if(A[j] >= pv) j--;
        else swap(A[i++], A[j]);
        //for(int k=0; k<n; k++) cout<<"  "<<A[k]; cout<<endl;
    }
    //cout<<endl<<endl;
    return j;
}

int quickFind(int st, int ed, int k)
{
    int posi = rando(st, ed-1);// To find a random positon
    //cout<<"random position =  "<<posi<<endl;
    swap(A[posi], A[ed-1]);// now pivot will be in last position

    int pv = A[ed-1];// last value of array
    int parti = _partition(st, ed, pv);

    swap(A[parti], A[ed-1]);

    /* cout << "pi: " << A[parti] << endl;
     cout << "after : ";
     for(int i=st; i<ed; i++) {
         if(i == parti) cout << "   |";
         printf(" %3d", A[i]);
     }
     cout << endl;*/

    int lftsize = parti-st;

    if(k < parti-st) return quickFind(st, parti, k);
    else if(k == parti-st) return A[parti];
    else return quickFind(parti+1, ed, k-lftsize-1);
}

int main()
{
    srand(time(NULL));
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)
    {
        //A[i] = rand() % 20 + 1;
        scanf("%d", &A[i]);
    }
    cout<<"By quick search = "<<quickFind(0, n, k)<<endl;
    nth_element(A, A+k, A+n);
    cout<<"By default = "<<A[k]<<endl;

}

/*****

10 4
18 13 3 12 10 4 10 8 9 16

*/

