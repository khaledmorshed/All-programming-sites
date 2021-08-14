#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void printVector(int n, vector<int> v[])
{

    //cout << "Vector is :" << endl;

    for(int i = 0; i < n; i++){

        cout<<v[i][0]<<endl;
    }


}

int main()
{
    int n;
    cin>>n;
    vector<int> v[n];

    for(int i = 0; i < n; i++){

        int num;
        cin>>num;
        v[i].push_back(num);
    }

       printVector(n, v);

    return 0;
}

