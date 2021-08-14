#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initialisation of a bitset
    bitset<38> b1(9999999999);
    bitset<8> b2(27);

    // Function to count the
    // number of set bits in b1
    int result1 = b1.count();
    cout << b1 << " has " << result1
         << " set bit\n";

    // Function to count the
    // number of set bits in b2
    int result2 = b2.count();
    cout << b2 << " has " << result2
         << " set bit"<<endl;

    int i = 10, n = 10;
    while(i--){

            n++;
        }
         cout<<"Case "<<i+1<<": "<<n<<endl;

    return 0;
}
