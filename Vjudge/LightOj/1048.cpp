#include<bits/stdc++.h>
using namespace std;

int n, k;

int f(int x, int ar[])
{

    int cnt = 1, currSum = 0;

    for(int i = 0; i < n; i++)
    {

        if(ar[i] > x) return k+100;

        else if(currSum+ar[i] <= x)
        {

            currSum+=ar[i];
        }
        else
        {
            cnt++;
            currSum = ar[i];

        }
    }
    return cnt;
}

int main()
{


    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {

        int sum = 0, ar[1003];
        scanf("%d %d", &n, &k);
        n++, k++;

        for(int i = 0; i < n; i++)
        {

            scanf("%d", &ar[i]);
            sum+=ar[i];
        }

        int low = 0, hi = sum;
        while(low < hi)
        {

            int x = (low + hi) / 2;

            if(f(x, ar) <= k) hi = x;
            else low = x + 1;
        }

        printf("Case %d: %d\n",t, hi);

        int cur = 0;
        for(int i = 0, j = 0, l = 0; j < k; i++)
        {

            if(i == n)
            {
                printf("%d\n", cur);
                break;
            }

            else if(cur+ar[i] <= hi)
            {

                // if(i < k)
                cur+=ar[i];

                if(i == k)
                {
                    printf("%d\n", cur);

                    for(int m = i+1; m < n; m++)
                    {

                        printf("%d\n", ar[m]);
                    }
                    break;

                    //cur+=ar[i];
                }
                else if(n - i == k - j){

                    printf("%d\n", cur);

                    for(int m = i+1; m < n; m++)
                    {

                        printf("%d\n", ar[m]);
                    }
                    break;
                }

            }
            else
            {
                printf("%d\n", cur);
                cur = ar[i];
                j++;
                l++;
            }
        }
    }

}
