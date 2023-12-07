#include<bits/stdc++.h>
#define sqr(x) ( (x) * (x) )//its called macro

using namespace std;
int cas=1;
double dis[10];

void f1(double a[], double b[], double t){

    //return {p1.xx+(p2.xx-p1.xx)*t, p1.yy+(p2.yy-p1.yy)*t};
    dis[0] = a[0] + (b[0] - a[0])*t;
    dis[1] = a[1] + (b[1] - a[1])*t;
    dis[2] = a[2] + (b[2] - a[2])*t;
    //cout<<"dis[0] = "<<dis[0]<<" dis[1] = "<<dis[1]<<" dis[2] = "<<dis[2]<<endl;

}

void f2(double a[], double b[], double t){

    //return {p1.xx+(p2.xx-p1.xx)*t, p1.yy+(p2.yy-p1.yy)*t};

    dis[3] = a[0] + (b[0] - a[0])*t;
    dis[4] = a[1] + (b[1] - a[1])*t;
    dis[5] = a[2] + (b[2] - a[2])*t;

    //cout<<"dis[3] = "<<dis[3]<<" dis[4] = "<<dis[4]<<" dis[5] = "<<dis[5]<<endl;
}

double distanc1(double p[]){

    //return sqrt(sqr(p1_2.xx-p.xx) + sqr(p1_2.yy-p.yy));
    //printf(" distance 1 = %.10f",sqrt(sqr(p[0] - dis[0]) + sqr(p[1] - dis[1]) + sqr(p[2] - dis[2])));
    return sqrt(sqr(p[0] - dis[0]) + sqr(p[1] - dis[1]) + sqr(p[2] - dis[2]));
}

double distanc2(double p[]){

    //return sqrt(sqr(p1_2.xx-p.xx) + sqr(p1_2.yy-p.yy));
    //printf(" distance 2 = %.10f\n",sqrt(sqr(p[0] - dis[3]) + sqr(p[1] - dis[4]) + sqr(p[2] - dis[5])));

    return sqrt(sqr(p[0] - dis[3]) + sqr(p[1] - dis[4]) + sqr(p[2] - dis[5]));

}

int main(){

    int T;
    double a[10];
    double b[10];
    double p[10];

    cin>>T;

    while(T--){

        int a1,a2,a3,b1,b2,b3,p1,p2,p3;
        cin>>a1>>a2>>a3>>b1>>b2>>b3>>p1>>p2>>p3;

        a[0] = a1;
        a[1] = a2;
        a[2] = a3;

        b[0] = b1;
        b[1] = b2;
        b[2] = b3;

        p[0] = p1;
        p[1] = p2;
        p[2] = p3;

        for(int i=0; i<=50; i++){

            f1(a,b,1/3.0);
            f2(a,b,2/3.0);

            if(distanc1(p) > distanc2(p)){

                a[0] = dis[0];
                a[1] = dis[1];
                a[2] = dis[2];
                //cout<<endl<<"cond 1"<<endl;
            }
            else{
                b[0] = dis[3];
                b[1] = dis[4];
                b[2] = dis[5];
                //cout<<endl<<"cond 2"<<endl;
            }
            //getchar();

        }

        //cout<<"Case "<<cas++<<": "<<distanc2(p)<<endl;
        printf("Case %d: %.10f\n",cas++,distanc2(p));

    }

}
