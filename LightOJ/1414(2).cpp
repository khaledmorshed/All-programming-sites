#include<bits/stdc++.h>

using namespace std;

int cas =1;
int  leapYearCommon(int yearFirst, string secondStringMonth, int daySecond, int yearSecond);
int  calculateLeapYear(int yearFirst, string secondStringMonth, int daySecond, int yearSecond);

int main()
{

    string s1, s2, firstStringMonth, secondStringMonth;
    char ch1, ch2;
    long long int dayFirst, daySecond, yearFirst, yearSecond;


    int T;
    cin>>T;

    cin.ignore();

    while(T)
    {
        int leapYear1, leapYear2;
        int check = 0;

        getline(cin, s1);
        getline(cin, s2);

        string part="";

        //first string s1 extract
        for(int i = 0; i  < s1.length(); i++){

            if(s1[i] == ' ' && check == 0){

                firstStringMonth = part;
                part = "";
                check = 1;
            }
            else if(s1[i] == ','){

                dayFirst = stod(part);
                part="";
            }
            else if(s1[i] == ' ' && check == 1){

                continue;
            }
            else{

                part.push_back(s1[i]);
            }

        }

        yearFirst = stod(part);
        part="";
        check = 0;

        //second string extract
         for(int i = 0; i  < s2.length(); i++){

            if(s2[i] == ' ' && check == 0){

                secondStringMonth = part;
                part = "";
                check = 1;
            }
            else if(s2[i] == ','){

                daySecond = stod(part);
                part="";
            }
            else if(s2[i] == ' ' && check == 1){

                continue;
            }
            else{

                part.push_back(s2[i]);
            }

        }

        yearSecond = stod(part);


        //cout<<"Time "<<T<<' '<<firstStringMonth<<' '<<dayFirst<<' '<<yearFirst<<endl;
        //cout<<"Time "<<T<<" "<<secondStringMonth<<" "<<daySecond<<" "<<yearSecond<<endl;

        if(((yearFirst % 4 == 0 || yearFirst % 400 == 0) && yearFirst % 100 != 0) &&
           (firstStringMonth == "January" || firstStringMonth == "February")){

            leapYear1 = calculateLeapYear(yearFirst, secondStringMonth, daySecond, yearSecond);
            //yearFirst = yearFirst + 1;
             cout<<"Case "<<cas++<<": "<<leapYear1<<endl;
           }
            else{
                yearFirst = yearFirst + 1;
                cout<<yearFirst<<endl;
                leapYear2 = leapYearCommon(yearFirst, secondStringMonth, daySecond, yearSecond);
                //leapYear2 = leapYear1 + leapYear2;

            cout<<"Case "<<cas++<<": "<<leapYear2<<endl;

            }


        T--;
    }

}

int  leapYearCommon(int yearFirst, string secondStringMonth, int daySecond, int yearSecond){

    int leapYear4;

    while(yearFirst <= yearSecond){


            if((yearFirst % 4 == 0 || yearFirst % 400 == 0) && yearFirst % 100 != 0){

                   return leapYear4 = calculateLeapYear(yearFirst, secondStringMonth, daySecond, yearSecond);
                   //break;
           }

        yearFirst = yearFirst + 1;
    }

    return 0;
}


int  calculateLeapYear(int yearFirst, string secondStringMonth, int daySecond, int yearSecond){

    int leapYear5 = 0;

     while(yearFirst < yearSecond){

        //
       /* if(yearFirst == yearSecond){


             if(((yearFirst % 4 == 0 || yearFirst % 400 == 0) && yearFirst % 100 != 0) &&
                (secondStringMonth == "February" && daySecond == 29)){

                 leapYear5++;
           }

           else if(((yearFirst % 4 == 0 || yearFirst % 400 == 0) && yearFirst % 100 != 0) &&
                (secondStringMonth != "January" || secondStringMonth != "February")){

                  leapYear5++;

           }

            return leapYear5;
        }

        else{

             if((yearFirst % 4 == 0 || yearFirst % 400 == 0) && yearFirst % 100 != 0){

                leapYear5++;


           }
        }*/



        if((yearFirst % 4 == 0 || yearFirst % 400 == 0) && yearFirst % 100 != 0){

                leapYear5++;
               // cout<<"fir1 "<<yearFirst<<endl;
        }
            //leapYear5++;
            //cout<<"fir2 "<<yearFirst<<endl;
            yearFirst = yearFirst + 4;


     }


     if(yearFirst == yearSecond){


             if(((yearFirst % 4 == 0 || yearFirst % 400 == 0) && yearFirst % 100 != 0) &&
                (secondStringMonth == "February" && daySecond == 29)){

                //cout<<"fir3 "<<yearFirst<<endl;
                 leapYear5++;
           }

           else if(((yearFirst % 4 == 0 || yearFirst % 400 == 0) && yearFirst % 100 != 0) &&
                (secondStringMonth != "January" && secondStringMonth != "February")){

                //cout<<"fir4 "<<yearFirst<<endl;
                  leapYear5++;

           }

             // return leapYear5;
        }



    return leapYear5;
}
