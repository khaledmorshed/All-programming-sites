#include<bits/stdc++.h>
#include<string>

using namespace std;

const double PI = 3.14159265358979323846;

int mass[20];

int main()
{
    int n, sum1, sum2, ans = 1e9, left, right;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> mass[i];
    }


    for(int i = 0; i < n; i++)
    {
        sort(mass, mass + n);

        sum1 = 0, sum2 = 0, left = 0, right = i;

        while(left < i)
        {
            //cout << mass[left] << " ";
            sum1 += mass[left];
            left++;
        }

        while(right < n)
        {
            //cout << mass[right] << " ";
            sum2 += mass[right];
            right++;
        }

        //cout << endl;
        ans = min(ans, abs(sum1 - sum2));

        for(int j = 0; j < i; j++)
        {

            for(int k = i; k < n; k++)
            {
                sum1 = 0, sum2 = 0, left = 0, right = i;

                swap(mass[j], mass[k]);

                while(left < i)
                {
                    //cout << mass[left] << " ";
                    sum1 += mass[left];
                    left++;
                }

                while(right < n)
                {
                    //cout << mass[right] << " ";
                    sum2 += mass[right];
                    right++;
                }
                //cout << endl;
                ans = min(ans, abs(sum1 - sum2));

                swap(mass[j], mass[k]);
            }
        }
    }

        cout << ans;


       return 0;
}


/*#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    long long int value, smalDiff, largdiff;

    cin>>n;
    set<int> v;

    for(int i = 0; i < n; i++){

        cin>>value;
        v.insert(value);
    }

    //sort(v.begin(), v.end());

    //smalDiff = v[1] - v[0];

    for(auto i = v.begin(); i != v.end(); i++){

        cout<<*i<<endl;

    }
    /*smalDiff = abs(smalDiff);

    for(int i = 2; i < n; i++){

        largdiff = v[i-1] - v[i];
        largdiff = abs(largdiff);

        if(smalDiff > largdiff){

            smalDiff = largdiff;
        }
    }

    //cout<<smalDiff<<endl;

}*/

