#include<bits/stdc++.h>
#define pdd pair<double, double>
#define x first
#define y second
#define sqr(x) ((x) * (x)) // it is called macro

using namespace std;

pdd calculatedPoint(pdd P, pdd Q, double t){
	return {P.x+(Q.x-P.x)*t, P.y+(Q.y-P.y)*t};
}

double _distance(pdd P, pdd Q){
	return sqrt(sqr(P.x - Q.x) + sqr(P.y- Q.y));
}

int main(){

	int T;
	cin>>T;
	pdd lo1, lo2, hi1, hi2;
	for(int t=1; t<=T; t++){
		pdd A,B,C,D;
		cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>D.x>>D.y;
		lo1 = A, hi1 = B;
		lo2 = C, hi2 = D;

		for(int i=0; i<100; i++){
			pdd point1 = calculatedPoint(lo1, hi1, 1.0/3.0);
			pdd point2 = calculatedPoint(lo1, hi1, 2.0/3.0);

			pdd point3 = calculatedPoint(lo2, hi2, 1.0/3.0);
			pdd point4 = calculatedPoint(lo2, hi2, 2.0/3.0);


			if(_distance(point1, point3) > _distance(point2, point4)){
				lo1 = point1;
				lo2 = point3;
			}
			else{
				hi1 = point2;
				hi2 = point4;
			}

			}
		//cout<<"Case "<<t<<": "<<_distance(lo1, lo2)<<endl;
		printf("Case %d: %.10f\n",t, _distance(lo1, lo2));
	}
}


