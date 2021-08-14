#include <bits/stdc++.h>

using namespace std;
// Driver code
int main()
{
    // Input vector
    vector<int> v{ 10, 20, 30, 30, 30, 40, 50 };

    // Print vector
    cout << "Vector contains :";
    for (unsigned int i = 0; i < v.size(); i++)
        cout << " " << v[i];
    cout << "\n";

    vector<int>::iterator low1, low2, low3;

    // std :: lower_bound
    low1 = lower_bound(v.begin(), v.end(), 30);
    low2 = lower_bound(v.begin(), v.end(), 40);
    low3 = lower_bound(v.begin(), v.end(), 55);

    // Printing the lower bounds

         cout<< "\nlower_bound for element 30 at position : "
        << (low1 - v.begin())<<" = "<<*low1<<endl;

        cout<< "\nlower_bound for element 40 at position : "
        << (low2 - v.begin())<<" = "<<*low2<<endl;

        cout<< "\nlower_bound for element 5 at position : "
        << (low3 - v.begin())<<" = "<<*low3<<endl;

        std::vector<int>::iterator upper1, upper2, upper3;

    // std :: upper_bound
    upper1 = std::upper_bound(v.begin(), v.end(), 30);
    upper2 = std::upper_bound(v.begin(), v.end(), 40);
    upper3 = std::upper_bound(v.begin(), v.end(), 55);


    std::cout << "\nupper_bound for element 30 is at position : "
              << (upper1 - v.begin())<<" = "<<*upper1;
    std::cout << "\nupper_bound for element 40 is at position : "
              << (upper2 - v.begin())<<" = "<<*upper2;

    std::cout << "\nupper_bound for element 5 is at position : "
              << (upper3 - v.begin())<<" = "<<*upper3;


       /* for(auto it = v.begin(); it != v.end(); it++){

            cout<<it<<endl;
        }*/

    return 0;
}
