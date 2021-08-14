#include<bits/stdc++.h>
using namespace std;
long long int shortBinarySearch(int long long luchuH, vector<long long int> &ladyChimp){
    if(luchuH == ladyChimp[0]){
            return -1;
        }
    long long int left, right, mid;
   left = 0;
   right = ladyChimp.size() - 1;
   //cout<<"Right "<<right<<endl;

   while(left <= right){
        mid = (left + right) / 2;

        if(left == right){

             if(luchuH == ladyChimp[mid]){

                while(luchuH == ladyChimp[mid]){

                    mid--;
                    if(mid == -1){

                        return -1;
                    }

                    ladyChimp[mid];
                }

                return ladyChimp[mid];
            }

            else if(luchuH < ladyChimp[mid]){

                while(luchuH < ladyChimp[mid]){

                    mid--;
                    if(mid == -1){

                        return -1;
                    }
                    ladyChimp[mid];
                }


                return ladyChimp[mid];
            }

            return ladyChimp[mid];

        }

        if(luchuH <= ladyChimp[mid]){
            right = mid - 1;
        }
        else if(luchuH > ladyChimp[mid])
            left = mid + 1;
        }

    return ladyChimp[mid-1];
}

long long int tallerBinarySearch(int long long luchuH, vector<long long int> &ladyChimp){

  long long int left, right, mid;
   left = 0;
   right = ladyChimp.size() - 1;
   //cout<<"Right "<<right<<endl;

   while(left <= right){
        mid = (left + right) / 2;

        if(left == right){

             if(luchuH == ladyChimp[mid]){

                while(luchuH >= ladyChimp[mid]){

                    mid++;
                    if(mid >= ladyChimp.size()){

                        return -1;
                    }
                    //ladyChimp[mid];
                }

                return ladyChimp[mid];
                //return -1;
            }

            else if(luchuH > ladyChimp[mid]){

                while(luchuH >= ladyChimp[mid]){

                    mid++;
                    if(mid >= ladyChimp.size()){

                        return -1;
                    }
                    //ladyChimp[mid];
                }

                return ladyChimp[mid];
                //return -1;
            }

            return ladyChimp[mid];
            //return -1;
        }

        if(luchuH < ladyChimp[mid]){
            right = mid - 1;
        }
        else if(luchuH == ladyChimp[mid]){
            left = mid + 1;
        }
        else if(luchuH > ladyChimp[mid])
            left = mid + 1;
        }

   return ladyChimp[mid];
}

int main(){

   // int shorter = 0, taller = 0;

    long long int ladyHeight;
    //long long int shorter;
    int N;
    char shorterString='x', tallerString = 'X';
    cin>>N;
    vector<long long int> ladyChimp;

    for(int i = 0; i < N; i++){
        cin>>ladyHeight;
        ladyChimp.push_back(ladyHeight);
    }

    //ladyChimp[0].push_back(-10);
    //auto shorter = ladyChimp[0].begin();

    long long int luchuHeight;
    int Q;
    cin>>Q;
    vector<long long int> luchu;

    for(int i = 0; i < Q; i++){
        cin>>luchuHeight;
        luchu.push_back(luchuHeight);
    }



    for(int i = 0; i < Q; i++){

        int long long luchuHeig = luchu[i];
        long long int catchShorter = shortBinarySearch(luchuHeig, ladyChimp);
        long long int catchTaller = tallerBinarySearch(luchuHeig, ladyChimp);

        if(catchShorter == -1 && catchTaller > 0){

            cout<<"X "<<catchTaller<<endl;
        }
        else if(catchTaller == -1 && catchShorter > 0){

            cout<<catchShorter<<" X"<<endl;
        }
        else if(catchShorter > 0 && catchTaller > 0){
            cout<<catchShorter<<" "<<catchTaller<<endl;
        }
        else{

            cout<<"X"<<" "<<"X"<<endl;
        }


    }

    return 0;
}

