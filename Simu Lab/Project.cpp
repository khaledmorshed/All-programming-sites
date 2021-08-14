#include<bits/stdc++.h>
using namespace std;

vector<int> v;
//int a[1000000];
int student = 1;

//all taken function
void calculateInterArrival_and_ArrivalTime(int RdArrival);
void takeRdForService();
void calculate_ServiceTime_With_All(int RdService);
void print();

int main()
{

    cout<<" <----------------------------------------------------------------->"<<endl;
    //cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" <----------------------------------------------------------------->"<<endl;
    cout<<"                  Simulation of Queuing Systems"<<endl<<endl<<endl;
    cout<<"     Table 1 : Distribution of Time Between Arrival"<<endl;
    cout<<" _____________________           _______________________"<<endl;
    cout<<" Time between Arrivals           Random-Digit Assignment"<<endl;
    cout<<" _____________________           _______________________"<<endl;
    cout<<"         0                                 0    \n\n         1                              001-125\n\n         2                              126-250\n\n         3                              251-375\n\n         4                              376-500\n\n         5                              501-625\n\n         6                              626-750\n\n         7                              751-875\n\n         8                              876-1000\n";
    //cout<<" _____________________           _______________________"<<endl;
    cout<<endl<<endl<<"     Table 2 : Service Time Distribution"<<endl;
    cout<<" _____________________           _______________________"<<endl;
    cout<<"   Service time                  Random-Digit Assignment"<<endl;
    cout<<" _____________________           _______________________"<<endl;
    cout<<"         1                              01-10\n\n         2                              11-30\n\n         3                              31-60\n\n         4                              61-85\n\n         5                              86-95\n\n         6                              96-100"<<endl;

    int RdArrival;

    while(1)
    {
        cout<<endl<<endl<<endl<<endl<<" Enter a Random Digit for Arrival (enter -1 for exit)       : ";
        cin>>RdArrival;
        //cout<<endl<<endl;

        if(RdArrival >= 0 && RdArrival <= 1000)
        {
            v.push_back(student++);
            // cut from here
                if(v.size()-1 == 0)
                {
                    RdArrival = 0;
                    v.push_back(RdArrival);
                }
                else
                    v.push_back(RdArrival);
                    // to there
             //v.push_back(RdArrival); //after cutting put it
            calculateInterArrival_and_ArrivalTime(RdArrival);//close to 102 line
            takeRdForService();//close to 297 line
        }
        else if(RdArrival == -1)
        {
            break;
        }

        while(RdArrival < 0 || RdArrival > 1000)
        {
            cout<<endl<<" Enter a Random Digit between 0 to 1000 (enter -1 for exit) : ";
            cin>>RdArrival;

            if(RdArrival == -1)
            {
                break;
            }

            else if(RdArrival >= 0 && RdArrival <= 1000)
            {
                v.push_back(student++);
                // cut from here
                if(v.size()-1 == 0)
                {
                    RdArrival = 0;
                    v.push_back(RdArrival);
                }
                else
                    v.push_back(RdArrival);
                    // to there

                 //v.push_back(RdArrival); //after cutting put it

                calculateInterArrival_and_ArrivalTime(RdArrival);//close to 102 line
                takeRdForService();//close to 297 line
            }

        }

        if(RdArrival == -1)
        {
            break;
        }
    }
    return 0;
}

//calculation of Inter arrival time for specific Random digit
void calculateInterArrival_and_ArrivalTime(int RdArrival)
{

    int InterArrivalTime;

    //cut v.size()-1 == 1
    if(RdArrival == 0 || v.size()-1 == 1)
    {

        InterArrivalTime = 0;
        v.push_back(InterArrivalTime);

        int index = v.size()-1;
        int arrivalTime = InterArrivalTime;


        if(index == 2)
        {

            v.push_back(arrivalTime);
        }

        else
        {
            v.push_back(v.at(index - 10) + InterArrivalTime);
        }
    }
    else if(RdArrival >=1  && RdArrival <= 125)
    {

        InterArrivalTime = 1;
        v.push_back(InterArrivalTime);

        int index = v.size()-1;
        int arrivalTime = InterArrivalTime;

        if(index == 2)
        {

            v.push_back(arrivalTime);
        }

        else
        {
            v.push_back(v.at(index - 10) + InterArrivalTime);
        }
    }

    else if(RdArrival >=126  && RdArrival <= 250)
    {

        InterArrivalTime = 2;
        v.push_back(InterArrivalTime);

        int index = v.size()-1;
        int arrivalTime = InterArrivalTime;

        if(index == 2)
        {

            v.push_back(arrivalTime);
        }

        else
        {
            v.push_back(v.at(index - 10) + InterArrivalTime);
        }
    }
    else if(RdArrival >=251  && RdArrival <= 375)
    {

        InterArrivalTime = 3;
        v.push_back(InterArrivalTime);

        int index = v.size()-1;
        int arrivalTime = InterArrivalTime;

        if(index == 2)
        {

            v.push_back(arrivalTime);
        }

        else
        {
            v.push_back(v.at(index - 10) + InterArrivalTime);
        }
    }
    else if(RdArrival >= 376  && RdArrival <= 500)
    {

        InterArrivalTime = 4;
        v.push_back(InterArrivalTime);

        int index = v.size()-1;
        int arrivalTime = InterArrivalTime;

        if(index == 2)
        {

            v.push_back(arrivalTime);
        }

        else
        {
            v.push_back(v.at(index - 10) + InterArrivalTime);
        }
    }
    else if(RdArrival >= 501  && RdArrival <= 625)
    {

        InterArrivalTime = 5;
        v.push_back(InterArrivalTime);

        int index = v.size()-1;
        int arrivalTime = InterArrivalTime;

        if(index == 2)
        {

            v.push_back(arrivalTime);
        }

        else
        {
            v.push_back(v.at(index - 10) + InterArrivalTime);
        }
    }
    else if(RdArrival >= 626  && RdArrival <= 750)
    {

        InterArrivalTime = 6;
        v.push_back(InterArrivalTime);

        int index = v.size()-1;
        int arrivalTime = InterArrivalTime;

        if(index == 2)
        {

            v.push_back(arrivalTime);
        }

        else
        {
            v.push_back(v.at(index - 10) + InterArrivalTime);
        }
    }
    else if(RdArrival >= 751  && RdArrival <= 875)
    {

        InterArrivalTime = 7;
        v.push_back(InterArrivalTime);

        int index = v.size()-1;
        int arrivalTime = InterArrivalTime;

        if(index == 2)
        {

            v.push_back(arrivalTime);
        }

        else
        {
            v.push_back(v.at(index - 10) + InterArrivalTime);
        }


    }
    else if(RdArrival >= 876  && RdArrival <= 1000)
    {

        InterArrivalTime = 8;
        v.push_back(InterArrivalTime);

        int index = v.size()-1;
        int arrivalTime = InterArrivalTime;

        if(index == 2)
        {

            v.push_back(arrivalTime);
        }

        else
        {
            v.push_back(v.at(index - 10) + InterArrivalTime);
        }
    }


}

//input taken Random digit for service
void takeRdForService()
{
    int RdService;

    cout<<endl<<" Enter a Random Digit for Service                           : ";
    cin>>RdService;

    if(RdService >= 1 && RdService <= 100)
    {
        v.push_back(RdService);
        calculate_ServiceTime_With_All(RdService);//close to 332 line
    }

    while(RdService < 1 || RdService > 100)
    {
        cout<<endl<<" Enter a Random Digit between 1 to 100                      : ";
        cin>>RdService;

        if(RdService >= 1 && RdService <= 100)
        {
            v.push_back(RdService);
            calculate_ServiceTime_With_All(RdService);//close to 332 line
            break;
        }
        else if(RdService < 1 || RdService > 100)
        {
            continue;

        }

    }


}

void calculate_ServiceTime_With_All(int RdService)
{

    if(RdService >= 1 && RdService <= 10)
    {

        int serviceTime = 1;
        v.push_back(serviceTime);

        int index = v.size()-1;//index of service time
        // if student comes first in queue
        if(index == 5)
        {

            int serviceBegin = v.at(3);//first arrival time
            v.push_back(serviceBegin);
            int waitInQueue = serviceBegin - v.at(v.size() - 4);//v.at(v.size() - 3) = arrival time of same row with service begin
            int serviceEnd = serviceTime + serviceBegin;
            v.push_back(serviceEnd);
            v.push_back(waitInQueue);
            v.push_back(0);//server idle time
            int Time_spent = serviceTime+waitInQueue;
            v.push_back(Time_spent);

        }
        else
        {
            //from above value is pushed in vector till service time
            int arrivalTime = v.at(v.size() - 3);// v.size is position of service time and -3 is value of arrival time index
            int prevoiusServiceEnd = v.at(v.size() - 10);//here v.size() is calculate the position of service time and -7 is value of previous service end

            if(prevoiusServiceEnd <= arrivalTime)
            {

                int serviceBegin = arrivalTime;
                v.push_back(serviceBegin);
                int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
                int serviceEnd2 = serviceBegin + serviceTime;
                v.push_back(serviceEnd2);
                v.push_back(waitInQueue);
                //v.size()-1 is in wait in queue in present row
                int serviceIdleTime = v.at(v.size() - 13)/*previous service end*/ - v.at(v.size() - 6)/*arrival time of present row*/;
                if(serviceIdleTime < 0)
                {
                    v.push_back(abs(serviceIdleTime));
                }
                else
                {
                    v.push_back(0);
                }
                int Time_spent = serviceTime+waitInQueue;
                v.push_back(Time_spent);
            }
            else//previous end fact
            {

                int serviceBegin = prevoiusServiceEnd;
                v.push_back(serviceBegin);
                int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed v.size()-4 is arrival time
                int serviceEnd3 = serviceBegin + serviceTime;
                v.push_back(serviceEnd3);
                v.push_back(waitInQueue);

                //v.size()-1 is in wait in queue in present row
                int serviceIdleTime = v.at(v.size() - 13)/*previous service end*/ - v.at(v.size() - 6)/*arrival time of present row*/;
                if(serviceIdleTime < 0)
                {
                    v.push_back(abs(serviceIdleTime));
                }
                else
                {
                    v.push_back(0);
                }
                int Time_spent = serviceTime+waitInQueue;
                v.push_back(Time_spent);
            }
        }
    }
    else if(RdService >= 11 && RdService <= 30)
    {

        int serviceTime = 2;
        v.push_back(serviceTime);

        int index = v.size()-1;
        // if student comes first in queue
        if(index == 5)
        {

            int serviceBegin = v.at(3);//first arrival time
            v.push_back(serviceBegin);
            int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
            int serviceEnd = serviceTime + serviceBegin;
            v.push_back(serviceEnd);
            v.push_back(waitInQueue);
            v.push_back(0);//server idle time
            int Time_spent = serviceTime + waitInQueue;
            v.push_back(Time_spent);
        }
        else
        {
            //from above value is pushed in vector till service time
            int arrivalTime = v.at(v.size() - 3);// v.size is position of service time and -3 is value of arrival time index
            int prevoiusServiceEnd = v.at(v.size() - 10);//here v.size() is calculate the position of service time and -7 is value of previous service end

            if(prevoiusServiceEnd <= arrivalTime)
            {

                int serviceBegin = arrivalTime;
                v.push_back(serviceBegin);
                int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
                int serviceEnd2 = serviceBegin + serviceTime;
                v.push_back(serviceEnd2);
                v.push_back(waitInQueue);
                //v.size()-1 is in wait in queue in present row
                int serviceIdleTime = v.at(v.size() - 13)/*previous service end*/ - v.at(v.size() - 6)/*arrival time of present row*/;
                if(serviceIdleTime < 0)
                {
                    v.push_back(abs(serviceIdleTime));
                }
                else
                {
                    v.push_back(0);
                }
                int Time_spent = serviceTime+waitInQueue;
                v.push_back(Time_spent);
            }
            else
            {

                int serviceBegin = prevoiusServiceEnd;
                v.push_back(serviceBegin);
                int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
                int serviceEnd3 = serviceBegin + serviceTime;
                v.push_back(serviceEnd3);
                v.push_back(waitInQueue);
                //v.size()-1 is in wait in queue in present row
                int serviceIdleTime = v.at(v.size() - 13)/*previous service end*/ - v.at(v.size() - 6)/*arrival time of present row*/;
                if(serviceIdleTime < 0)
                {
                    v.push_back(abs(serviceIdleTime));
                }
                else
                {
                    v.push_back(0);
                }
                int Time_spent = serviceTime+waitInQueue;
                v.push_back(Time_spent);
            }
        }
    }
    else if(RdService >= 31 && RdService <= 60)
    {

        int serviceTime = 3;
        v.push_back(serviceTime);

        int index = v.size()-1;
        // if student comes first in queue
        if(index == 5)
        {

            int serviceBegin = v.at(3);//first arrival time
            v.push_back(serviceBegin);
            int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
            int serviceEnd = serviceTime + serviceBegin;
            v.push_back(serviceEnd);
            v.push_back(waitInQueue);
            v.push_back(0);//server idle time
            int Time_spent = serviceTime+waitInQueue;
            v.push_back(Time_spent);
        }
        else
        {
            //from above value is pushed in vector till service time
            int arrivalTime = v.at(v.size() - 3);// v.size is position of service time and -3 is value of arrival time index
            int prevoiusServiceEnd = v.at(v.size() - 10);//here v.size() is calculate the position of service time and -7 is value of previous service end

            if(prevoiusServiceEnd <= arrivalTime)
            {

                int serviceBegin = arrivalTime;
                v.push_back(serviceBegin);
                int waitInQueue = serviceBegin - v.at(v.size() - 4);
                int serviceEnd2 = serviceBegin + serviceTime;
                v.push_back(serviceEnd2);
                v.push_back(waitInQueue);
                //v.size()-1 is in wait in queue in present row
                int serviceIdleTime = v.at(v.size() - 13)/*previous service end*/ - v.at(v.size() - 6)/*arrival time of present row*/;
                if(serviceIdleTime < 0)
                {
                    v.push_back(abs(serviceIdleTime));
                }
                else
                {
                    v.push_back(0);
                }
                int Time_spent = serviceTime+waitInQueue;
                v.push_back(Time_spent);
            }
            else
            {

                int serviceBegin = prevoiusServiceEnd;
                v.push_back(serviceBegin);
                int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
                int serviceEnd3 = serviceBegin + serviceTime;
                v.push_back(serviceEnd3);
                v.push_back(waitInQueue);
                //v.size()-1 is in wait in queue in present row
                int serviceIdleTime = v.at(v.size() - 13)/*previous service end*/ - v.at(v.size() - 6)/*arrival time of present row*/;
                if(serviceIdleTime < 0)
                {
                    v.push_back(abs(serviceIdleTime));
                }
                else
                {
                    v.push_back(0);
                }
                int Time_spent = serviceTime+waitInQueue;
                v.push_back(Time_spent);
            }
        }
    }
    else if(RdService >= 61 && RdService <= 85)
    {

        int serviceTime = 4;
        v.push_back(serviceTime);

        int index = v.size()-1;
        // if student comes first in queue
        if(index == 5)
        {

            int serviceBegin = v.at(3);//first arrival time
            v.push_back(serviceBegin);
            int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
            int serviceEnd = serviceTime + serviceBegin;
            v.push_back(serviceEnd);
            v.push_back(waitInQueue);
            v.push_back(0);//server idle time
            int Time_spent = serviceTime+waitInQueue;
            v.push_back(Time_spent);
        }
        else
        {
            //from above value is pushed in vector till service time
            int arrivalTime = v.at(v.size() - 3);// v.size is position of service time and -3 is value of arrival time index
            int prevoiusServiceEnd = v.at(v.size() - 10);//here v.size() is calculate the position of service time and -7 is value of previous service end

            if(prevoiusServiceEnd <= arrivalTime)
            {

                int serviceBegin = arrivalTime;
                v.push_back(serviceBegin);
                int waitInQueue = serviceBegin - v.at(v.size() - 4);
                int serviceEnd2 = serviceBegin + serviceTime;
                v.push_back(serviceEnd2);
                v.push_back(waitInQueue);
                //v.size()-1 is in wait in queue in present row
                int serviceIdleTime = v.at(v.size() - 13)/*previous service end*/ - v.at(v.size() - 6)/*arrival time of present row*/;
                if(serviceIdleTime < 0)
                {
                    v.push_back(abs(serviceIdleTime));
                }
                else
                {
                    v.push_back(0);
                }
                int Time_spent = serviceTime+waitInQueue;
                v.push_back(Time_spent);
            }
            else
            {

                int serviceBegin = prevoiusServiceEnd;
                v.push_back(serviceBegin);
                int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
                int serviceEnd3 = serviceBegin + serviceTime;
                v.push_back(serviceEnd3);
                v.push_back(waitInQueue);
                //v.size()-1 is in wait in queue in present row
                int serviceIdleTime = v.at(v.size() - 13)/*previous service end*/ - v.at(v.size() - 6)/*arrival time of present row*/;
                if(serviceIdleTime < 0)
                {
                    v.push_back(abs(serviceIdleTime));
                }
                else
                {
                    v.push_back(0);
                }
                int Time_spent = serviceTime+waitInQueue;
                v.push_back(Time_spent);
            }
        }
    }
    else if(RdService >= 86 && RdService <= 95)
    {

        int serviceTime = 5;
        v.push_back(serviceTime);

        int index = v.size()-1;
        // if student comes first in queue
        if(index == 5)
        {

            int serviceBegin = v.at(3);//first arrival time
            v.push_back(serviceBegin);
            int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
            int serviceEnd = serviceTime + serviceBegin;
            v.push_back(serviceEnd);
            v.push_back(waitInQueue);
            v.push_back(0);//server idle time
            int Time_spent = serviceTime+waitInQueue;
            v.push_back(Time_spent);
        }
        else
        {
            //from above value is pushed in vector till service time
            int arrivalTime = v.at(v.size() - 3);// v.size is position of service time and -3 is value of arrival time index
            int prevoiusServiceEnd = v.at(v.size() - 10);//here v.size() is calculate the position of service time and -7 is value of previous service end

            if(prevoiusServiceEnd <= arrivalTime)
            {

                int serviceBegin = arrivalTime;
                v.push_back(serviceBegin);
                int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
                int serviceEnd2 = serviceBegin + serviceTime;
                v.push_back(serviceEnd2);
                v.push_back(waitInQueue);
                //v.size()-1 is in wait in queue in present row
                int serviceIdleTime = v.at(v.size() - 13)/*previous service end*/ - v.at(v.size() - 6)/*arrival time of present row*/;
                if(serviceIdleTime < 0)
                {
                    v.push_back(abs(serviceIdleTime));
                }
                else
                {
                    v.push_back(0);
                }
                int Time_spent = serviceTime+waitInQueue;
                v.push_back(Time_spent);
            }
            else
            {

                int serviceBegin = prevoiusServiceEnd;
                v.push_back(serviceBegin);
                int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
                int serviceEnd3 = serviceBegin + serviceTime;
                v.push_back(serviceEnd3);
                v.push_back(waitInQueue);
                //v.size()-1 is in wait in queue in present row
                int serviceIdleTime = v.at(v.size() - 13)/*previous service end*/ - v.at(v.size() - 6)/*arrival time of present row*/;
                if(serviceIdleTime < 0)
                {
                    v.push_back(abs(serviceIdleTime));
                }
                else
                {
                    v.push_back(0);
                }
                int Time_spent = serviceTime+waitInQueue;
                v.push_back(Time_spent);
            }
        }
    }
    else if(RdService >= 96 && RdService <= 100)
    {

        int serviceTime = 6;
        v.push_back(serviceTime);

        int index = v.size()-1;
        // if student comes first in queue
        if(index == 5)
        {

            int serviceBegin = v.at(3);//first arrival time
            v.push_back(serviceBegin);
            int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
            int serviceEnd = serviceTime + serviceBegin;
            v.push_back(serviceEnd);
            v.push_back(waitInQueue);
            v.push_back(0);//server idle time
            int Time_spent = serviceTime+waitInQueue;
            v.push_back(Time_spent);
        }
        else
        {
            //from above value is pushed in vector till service time
            int arrivalTime = v.at(v.size() - 3);// v.size is position of service time and -3 is value of arrival time index
            int prevoiusServiceEnd = v.at(v.size() - 10);//here v.size() is calculate the position of service time and -7 is value of previous service end

            if(prevoiusServiceEnd <= arrivalTime)
            {

                int serviceBegin = arrivalTime;
                v.push_back(serviceBegin);
                int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
                int serviceEnd2 = serviceBegin + serviceTime;
                v.push_back(serviceEnd2);
                v.push_back(waitInQueue);
                //v.size()-1 is in wait in queue in present row
                int serviceIdleTime = v.at(v.size() - 13)/*previous service end*/ - v.at(v.size() - 6)/*arrival time of present row*/;
                if(serviceIdleTime < 0)
                {
                    v.push_back(abs(serviceIdleTime));
                }
                else
                {
                    v.push_back(0);
                }
                int Time_spent = serviceTime+waitInQueue;
                v.push_back(Time_spent);
            }
            else
            {

                int serviceBegin = prevoiusServiceEnd;
                v.push_back(serviceBegin);
                int waitInQueue = serviceBegin - v.at(v.size() - 4);// here 4 is fixed
                int serviceEnd3 = serviceBegin + serviceTime;
                v.push_back(serviceEnd3);
                v.push_back(waitInQueue);
                //v.size()-1 is in wait in queue in present row
                int serviceIdleTime = v.at(v.size() - 13)/*previous service end*/ - v.at(v.size() - 6)/*arrival time of present row*/;
                if(serviceIdleTime < 0)
                {
                    v.push_back(abs(serviceIdleTime));
                }
                else
                {
                    v.push_back(0);
                }
                int Time_spent = serviceTime+waitInQueue;
                v.push_back(Time_spent);
            }
        }
    }

    print();
}

void print()
{
    cout<<endl<<endl;
    cout<<"______________________________________________________________________________________________________________________________________________________________________";
    printf("\n Student     RD_Arrival     Inter_Arrival_Time     Arrival_Time    RD_Service    Ser_Time     Ser_Begin     Ser_End     Wait_in_Queue     Ser_Idle_Time     Time_Spent\n");
    //cout<<" ----------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"______________________________________________________________________________________________________________________________________________________________________";


    cout<<endl;
    for(auto i = v.begin(); i != v.end(); ++i)
    {
        cout<<"  ";
        cout.width(15);
        cout<<left<<*i;
        //cout<<"   "<<*i<<"            ";
        cout.width(18);
        cout<<left<<*++i;
        cout.width(20);
        cout<<left<<*++i;
        cout.width(15);
        cout<<left<<*++i;
        cout.width(14);
        cout<<left<<*++i;
        cout.width(13);
        cout<<left<<*++i;
        cout.width(14);
        cout<<left<<*++i;
        cout.width(14);
        cout<<left<<*++i;
        cout.width(18);
        cout<<left<<*++i;
        cout.width(16);
        cout<<left<<*++i;
        //cout.width(15);

        cout<<*++i;
        //cout<<"vector lenght = "<<v.size()<<endl;

        cout<<endl;
        cout<<"______________________________________________________________________________________________________________________________________________________________________";
        //cout<<" ----------------------------------------------------------------------------------------------------------------------------------------------------------------------";
        cout<<endl;
    }

}


