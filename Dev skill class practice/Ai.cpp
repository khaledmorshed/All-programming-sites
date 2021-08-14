
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int P1;
    int p2;
    int p3;
    int p4;

    double Probi,Ex,Sum,Avg;
    //scanf("%d %d %d %d",&p1,&p2,&p3,&p4);
    //printf("%d %d %d %d",x,y,z,a);
    cin>>p1>>p2>>p3>>p4;

    Sum=(P1+P2+P3+P4)*1.0;
    Avg=Sum/4.0;
    Probi=(P1*1.0)/Sum;
    Ex=(P1*1.0)/Avg;

    printf("p1 = %d\n p2 = %d\n p3 = %d\n p4 = %d\n sum = %lf\n avg = %lf\n probi = %lf\n exC = %lf\n",P1,P2,P3,P4,Sum,Avg,Probi,Ex);

    return 0;


}
