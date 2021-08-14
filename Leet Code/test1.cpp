#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int golbalInversion=0;

    void _merge(int start, int end, vector<int>& A){

        int temp[end-start+1];

        int mid = (start+end)/2;
        int i=start, j=mid, k=0;

        while(i<mid && j<end){

            if(A[i]<=A[j]){
                temp[k++]=A[i++];
            }
            else{
                temp[k++]=A[j++];
                golbalInversion++;
            }

        }
        while(i<mid)
            temp[k++] = A[i++];
        while(j<end)
            temp[k++] = A[j++];

        for(int cnt=start,an=0;cnt<end;cnt++,an++)
            A[cnt]=temp[an];

    }


    void mergeSort(int start, int end, vector<int>& A){

        if(start+1==end)
            return;
        int mid = (start+end)/2;
        mergeSort(start,mid,A);
        mergeSort(mid,end,A);
        _merge(start,end, A);

    }


    bool isIdealPermutation(vector<int>& A) {

        int len = A.size(), localInversion=0;

        //At first count the localInversion, becasue after calling mergeSort the array wil changed to a sorted array

        for(int i=0;i<len-1;i++){
            if(A[i]>A[i+1])
                localInversion++;
        }

        mergeSort(0,len,A);

        //cout<<golbalInversion<<" "<<localInversion<<endl;

        if(localInversion==golbalInversion)
             return true;
        else
            return false;

    }
};

int main() {

	Solution s;
	vector<int>vec = {1,2,0,3};

	cout<<s.isIdealPermutation(vec)<<endl;

	return 0;
}
