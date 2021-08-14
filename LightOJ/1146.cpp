#include<bits/stdc++.h>
#define pdd pair<double, double>
#define x first
#define y second
#define sqr(x) ( (x) * (x) )//iti called macro

using namespace std;

int cas=1;

pdd calculate_A(pdd A, pdd B, double t)
{

    return {A.x+(B.x-A.x)*t, A.y+(B.y-A.y)*t};
}

pdd calculate_B(pdd A, pdd B, double t)
{

    return {A.x+(B.x-A.x)*t, A.y+(B.y-A.y)*t};
}

pdd calculate_C(pdd C, pdd D, double t)
{

    return {C.x+(D.x-C.x)*t, C.y+(D.y-C.y)*t};
}

pdd calculate_D(pdd C, pdd D, double t)
{

    return {C.x+(D.x-C.x)*t, C.y+(D.y-C.y)*t};
}

double distance_AC(pdd A, pdd C){

    //return sqrt(sqr(p1_2.xx-p.xx) + sqr(p1_2.yy-p.yy));
    return sqrt(sqr(A.x-C.x) + sqr(A.y-C.y));
}

double distance_BD(pdd B, pdd D){

    return sqrt(sqr(B.x-D.x) + sqr(B.y-D.y));
}


int main()
{

    int T;
    pdd point_A, point_C;
    cin>>T;

    while(T--)
    {

        pdd A, B, C, D;
        cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>D.x>>D.y;

        pdd low1 = A, hi1 = B;
        pdd low2 = C, hi2 = D;

        for(int i=0; i<=100; i++)
        {

            point_A = calculate_A(low1, hi1, 1.0/3.0);
            pdd point_B = calculate_B(low1, hi1, 2.0/3.0);

            point_C = calculate_C(low2, hi2, 1.0/3.0);
            pdd point_D = calculate_D(low2, hi2, 2.0/3.0);

            if(distance_AC(point_A, point_C) > distance_BD(point_B, point_D))
            {

                low1 = point_A;
                low2 = point_C;
            }
            else
            {
                hi1 = point_B;
                hi2 = point_D;
            }


        }

        //pdd ans = distance_AC(point_A, point_C);

        printf("Case %d: %.10f\n",cas++, distance_AC(point_A, point_C));
    }

}
