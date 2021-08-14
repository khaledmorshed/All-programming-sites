#include<bits/stdc++.h>
using namespace std;

void afterConvertingDecimaPutInVector(string s1, string s2);
string convertIntoDecimalAfterThatString(string part);
void print(string s1, string s2);
int cas = 1;

int main(){

    int T;

    cin>>T;

    cin.ignore();
    while(T){

        string s1, s2;

        getline(cin, s1);
        getline(cin, s2);

        afterConvertingDecimaPutInVector(s1, s2);

        T--;
    }

}


void afterConvertingDecimaPutInVector(string s1, string s2){

   // vector<string> v;

    string s3="";
    string  decimalValue;

    string part="";

    for(int i=0;i <s2.length(); i++){

        if(s2[i] == '.'){

          decimalValue = convertIntoDecimalAfterThatString(part);
          //v.push_back(decimalValue);
          s3 = s3 + decimalValue;
          s3 = s3 + s2[i];
          //string temp="";
          //temp.push_back(s2[i]);

         // v.push_back(temp);

          part="";

        }
        else{
            part.push_back(s2[i]);
        }
    }

     decimalValue = convertIntoDecimalAfterThatString(part);
     s3 = s3 + decimalValue;


     //cout<<"s3 "<<s3<<endl;

    print(s1, s3);
    //v.push_back(decimalValue);

}

string convertIntoDecimalAfterThatString(string part){

    int binary, partDecimal, fullDecimal, exponential = 0, sum = 0;
     string temp;

    //binary = stod(part);

    //cout<<binary<<endl;

    for(int i = part.length() - 1; i >= 0; i--){

        temp = part[i];
        partDecimal = stod(temp);

        if(partDecimal == 0){

            exponential++;
        }

        else{

            sum = sum + pow(2, exponential);
            exponential++;
        }
    }

   // cout<<sum<<endl;

    string str;

    str = to_string(sum);

    return str;
}


void  print(string s1, string s3){

    if(s1.compare(s3) == 0){

        cout<<"Case "<<cas++<<": Yes"<<endl;
    }

    else{

        cout<<"Case "<<cas++<<": No"<<endl;
    }

}
