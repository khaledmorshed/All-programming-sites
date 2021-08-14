#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void printVector(int n, vector<int> &v)
{

    cout << "Vector size :" <<v.size()<<endl;

   /* for(int i = 0; i < n; i++){

        cout<<v[i]<<endl;
    }*/


}

int main()
{
    int n;
    cin>>n;
    vector<int> v;

    for(int i = 0; i < n; i++){

        int num;
        cin>>num;
        v.push_back(num);
    }

       printVector(n, v);

    return 0;
}


