#include<bits/stdc++.h>

using namespace std;

int main()
{

    string str;
    getline(cin, str);
    //cout<<str<<endl;
    stringstream ss(str);

    int len = str.length();

    vector<string> v;
    while(ss>>str){
		v.push_back(str);
    }

	for(int j=0; j<v[0].length(); j++){
		char  ch = v[0][j];
		for(int i=0; i<v.size(); i++){
			if(ch != v[i][j]){
				v[0][j] = '?';
			}
		}
	}

	cout<<v[0]<<endl;
	cout<<str<<endl;

}
