#include<iostream>
#include<utility>
#include<vector>

using namespace std;

 vector<int> v;
 pair <int, int > p[10001];

void ordering();
void print();

int main(){


    ordering();
    print();

return 0;
 }

void print(){

 int T, n, i = 1;
    cin>>T;

    while(T>0){

        cin>>n;
        cout<<"Case "<<i++<<": "<<p[n].first<<endl;
        T--;
    }


 }

void ordering(){


    //pair <int, int > p[1000];


    int k=0, l = 0, temp, temp2, index_min;

    for(int m = 1000; m >= 1; m--){

        for(int n = 1; n <=  m; n++){

            if(m % n == 0){

                l++;
            }
        }

        p[m] = make_pair(m,l);
       // v.push_back(1);
        l = 0;
    }

    /*for(auto it = v.begin(); it!=v.end(); it++){

        cout<<*it<<endl;
    }*/

    int i, j, item, itemFirst;
    //insert sort
    for(i = 1; i <= 1000; i++){

        item = p[i].second;
        itemFirst = p[i].first;

        j = i - 1;

        while(j >= 0 && p[j].second > item){

            p[j+1].second = p[j].second;
            p[j+1].first = p[j].first;
            j = j - 1;
        }

        p[j+1].second = item;
        p[j+1].first = itemFirst;

    }


    int a, b, temp3, temp4, index;

    for(a = 1; a <= 1000; a++){

        for(b = 1; b <= 1000; b++){

            if(p[a].second == p[b].second && p[a].first > p[b].first){

                temp3 = p[a].first;
                p[a].first = p[b].first;
                p[b].first = temp3;

                temp4 = p[a].second;
                p[a].second = p[b].second;
                p[b].second = temp4;
            }
        }
    }

   /* int temp5;

    for(int i = 1; i <= 1000; i++){

        cout<<p[i].first<<" "<<p[i].second<<endl;
        //temp5 = p[i].first;
        //v.push_back(temp5);
    }

    //print(v);

    /*int o = 1;
    for(auto it = v.begin(); it!=v.end(); it++){

        cout<<*it<<endl;
    }*/



}


