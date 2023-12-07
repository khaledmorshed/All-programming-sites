#include<bits/stdc++.h>
using namespace std;

int n, A[10004];

int rando(int a, int b)
{
    int sz = b - a + 1;
    return rand() % sz + a;
}

/*
10
8 6 8 11 20 7 16 20 16 11

*/
int _partition(int st, int ed, int pv)
{
    int i = st, j = ed-1;
    for(int i=st; i<ed; i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
    while(i < j)
    {
        if(A[i] < pv){
            cout<<"ai = "<<A[i]<<" pv = "<<pv<<endl;
            i++;
        }
        else if(A[j] >= pv){
            cout<<"aj = "<<A[j]<<" pv = "<<pv<<endl;
            j--;
        }
        else{
            cout<<"ai = "<<A[i]<<" aj = "<<A[j]<<" pv = "<<pv<<endl;
            swap(A[i++], A[j]);
        }

        //for(int k=0; k<n; k++) cout<<"  "<<A[k]; cout<<endl;
    }
    for(int i=st; i<ed; i++){
            cout<<A[i]<<" ";
        }
        cout<<endl<<endl;
    //cout<<endl<<endl;
    return j;
}

void quickSort(int st, int ed)
{
    if(st+1 >= ed) return; // if(st >= ed-1) return;

   // int posi = rando(st, ed-1);// To find a random positon
    //cout<<"random position =  "<<posi<<endl;
    //swap(A[posi], A[ed-1]);// now pivot will be in last position

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

    quickSort(st, parti);
    quickSort(parti+1, ed);
}

int main()
{
    srand(time(NULL));
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        //A[i] = rand() % 20 + 1;
        scanf("%d", &A[i]);
    }
    cout<<"Before sorting : ";
    for(int i=0; i<n; i++) cout<<"  "<<A[i];
    cout<<endl;
    quickSort(0, n);
    cout<<"After sorting : ";
    for(int i=0; i<n; i++) cout<<"  "<<A[i];
    cout<<endl;
}

/*****

10
18 13 3 12 10 4 10 8 9 16

*/
