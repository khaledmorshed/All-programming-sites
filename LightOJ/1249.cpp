#include<bits/stdc++.h>

using namespace std;
//int n;
//typedef pair<int, string> p;
int cas = 1;
void takeInput();
void insertionSort(pair<int, string> p[], int n);
void  print(pair<int, string> p[], int n);

int main(){

    int T;
    cin>>T;
    while(T){

        takeInput();
        T--;
    }
}

void takeInput(){

    int n;
    cin>>n;

    string studentName;
    int length,width,height, volume;

    //pair<string, int> p[n];
   // vector < p > v;



	pair<int, string> p[n];
    //vector<pair<int, string>> v[n];

    for(int i = 0; i < n; i++){

        cin>>studentName>>length>>width>>height;

        volume = length*width*height;

        p[i] = make_pair(volume, studentName);
        //v[i].push_back(p[i]);
    }

    insertionSort(p, n);

   // sort(p.begin(), p.end());


    /* for(int i = 0; i < n; i++) {
        cout<< p[i].second << ' ' << p[i].first << '\n'<<endl;
    }*/
}

void insertionSort(pair<int, string> p[], int n){


      int i, j, item;
      string itemSecond;
    //insert sort
    for(i = 0; i < n; i++){

        item = p[i].first;
        itemSecond = p[i].second;

        j = i - 1;

        while(j >= 0 && p[j].first > item){

            p[j+1].second = p[j].second;
            p[j+1].first = p[j].first;
            j = j - 1;
        }

        p[j+1].first = item;
        p[j+1].second = itemSecond;

    }


    /*for(int i = 0; i < n; i++){

        cout<<p[i].first<<" "<<p[i].second<<endl<<endl;
        //temp5 = p[i].first;
        //v.push_back(temp5);
    }*/

    print(p, n);


}


void  print(pair<int, string> p[], int n){

    if(p[0].first < p[1].first && p[n-1].first > p[n-2].first){

        cout<<"Case "<<cas++<<": "<<p[n-1].second<<" took chocolate from "<<p[0].second<<endl;
    }

    else{

        cout<<"Case "<<cas++<<": no thief"<<endl;
    }
}
