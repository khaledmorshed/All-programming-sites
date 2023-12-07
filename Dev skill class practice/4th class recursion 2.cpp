#include<bits/stdc++.h>
using namespace std;

int fRecursion(int n){
	if(n<=1) return n;
	return fRecursion(n-1)+fRecursion(n-2);

}

int main(){

	int n;
	cin>>n;
	int m = fRecursion(n);
	cout<<m<<endl;
}

/*
#include<bits/stdc++.h>
using namespace std;

void fRecursion(int n){
	//cout<<n<<endl;
	int temp1=2, temp2;
	if(n==0){
		temp1 = 0;
	}
	if(n==1){
		temp2 = 1;
	}
//	if(n<=1){
//		 cout<<endl;
//		return n;
//	}
	if(temp1){
		fRecursion(n-1);
		//+fRecursion(n-2);
	}
	cout<<n<<endl;

}

int main(){

	int n;
	cin>>n;
	//int m =
	fRecursion(n);
	//cout<<m<<endl;
}


*/
