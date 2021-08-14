#include<bits/stdc++.h>
#define pdd pair<double, double>
#define xx first
#define yy second
#define sqr(x) ( (x) * (x) )//iti called macro

using namespace std;

pdd calculate_A_point(pdd p1, pdd p2, double t){

    return {p1.xx+(p2.xx-p1.xx)*t, p1.yy+(p2.yy-p1.yy)*t};
    //return pdd(p1.xx+(p2.xx-p1.xx)*t, p1.yy+(p2.yy-p1.yy)*t); //same as above line
}

double _distance(pdd p1_2, pdd p){

    return sqrt(sqr(p1_2.xx-p.xx) + sqr(p1_2.yy-p.yy));
}

int main(){

    pdd p1, p2, p;
    //int x1, y1, x2, y2, x, y;
    scanf("%lf %lf %lf %lf %lf %lf", &p1.xx, &p1.yy, &p2.xx, &p2.yy, &p.xx, &p.yy);

    pdd low = p1, hi = p2;
    //cout<<p1<<" "<<p2<<endl;
    for(int i=0; i<=50; i++){

        pdd pt1 = calculate_A_point(low, hi, 1.0/3.0);//here we get a pt1 point in straight line where x and y are present int pt1
        pdd pt2 = calculate_A_point(low, hi, 2.0/3.0);//here we get a pt2 point in straight line

        if(_distance(pt1, p) > _distance(pt2, p)){

            low = pt1;
        }
        else hi = pt2;

    }

    pdd ans = low;
    printf("%.6f %.6f %.6f\n", ans.xx, ans.yy, _distance(ans, p));//ans.xx = x point and ans.yy = y point which will be midle in line

}

