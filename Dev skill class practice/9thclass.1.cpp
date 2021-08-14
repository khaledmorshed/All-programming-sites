#include<bits/stdc++.h>
#define pdd pair<double, double>
#define xx first
#define yy second
#define sqr(x) ( (x) * (x) )//iti called macro

using namespace std;

pdd g(pdd p1, pdd p2, double t){

    return {p1.xx+(p2.xx-p1.xx)*t, p1.yy+(p2.yy-p1.yy)*t};
    //return pdd(p1.xx+(p2.xx-p1.xx)*t, p1.yy+(p2.yy-p1.yy)*t); //same as above line
}

double _distance(pdd p1_2, pdd p){

    return sqrt(sqr(p1_2.xx-p.xx) + sqr(p1_2.yy-p.yy));
}

int main(){

    pdd p1, p2, p;
    int x1, y1, x2, y2, x, y;
    scanf("%lf %lf %lf %lf %lf %lf", &p1.xx, &p1.yy, &p2.xx, &p2.yy, &p.xx, &p.yy);

    double low = 0, hi = 1;
    for(int i=0; i<=50; i++){

        double t1 = (low+hi)*1.0/3;
        double t2 = (low+hi)*2.0/3;

        pdd pt1 = g(p1, p2, t1);//here we get a pt1 point in straight line where x and y are present int pt1
        pdd pt2 = g(p1, p2, t2);//here we get a pt2 point in straight line

        if(_distance(pt1, p) > _distance(pt2, p)){

            low = t1;
        }
        else hi = t2;

    }

    pdd ans = g(p1, p2, hi);
    printf("%.6f %.6f %.6f\n", ans.xx, ans.yy, _distance(ans, p));//ans.xx = x point and ans.yy = y point which will be midle in line

}
