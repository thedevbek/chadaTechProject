#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

void displayMenu(){
    cout << "************************"<<endl; //print out the menu to change time
    cout << "* 1 - Add One Hour     *"<<endl;
    cout << "* 2 - Add One Minute   *"<<endl;
    cout << "* 3 - Add One Second   *"<<endl;
    cout << "* 4 - Exit Program     *"<<endl;
    cout << "************************"<<endl;
}

void setTime(int hh,int mm,int ss){

    int h12;
    string ampm;


    ampm = (hh >= 12) ? ampm =  " PM" : ampm = " AM"; //a ternary to get the am and pm
    if (hh == 0)
        h12 = 12;
    else if (hh <= 12)
        h12 = hh;
    else
        h12 = hh - 12;

    cout<<"***************"<<endl;
    cout<<"12-Hour Clock "<<endl; //this is the 12-hour clock
    cout<< setfill('0')<<setw(2) <<h12<< ":" <<setfill('0')<<setw(2)<< mm << ":" << setfill('0')<<setw(2)<<ss<< ampm <<endl;
    cout<<"***************"<<endl;


    cout<<"***************"<<endl;
    cout<<"24-Hour Clock"<<endl; //this is the 24-hour clock
    cout<<setfill('0')<<setw(2)<<hh<< ":" <<setfill('0')<<setw(2)<< mm << ":" <<setfill('0')<<setw(2)<< ss <<endl;
    cout<<"***************"<<endl;//use setw() and setill() to format the nums correct
}

int main() {

    int hh, mm, ss;

    time_t new_time;//to read time
    tm *t_info;//to store it in structure format
               //char timeStr[9];//to get a formatted time string

    time(&new_time);
    t_info = localtime(&new_time);

    hh =  t_info->tm_hour; // hh is set here
    mm =  t_info->tm_min;  // mm, is set here
    ss =  t_info->tm_sec;  // ss is set here



    char userChoice='1';

    while(userChoice != '4') {

        setTime(hh, mm, ss);

        displayMenu();

        cout<<"Please, choose a number from display menu to change time."<<endl;
        cin>>userChoice;

        switch(userChoice) { //the switch is where you change the time on clocks.
            case '1': hh++;
                break;
            case '2': mm++;
                break;
            case '3': ss++;
                break;
            case '4':
                break;
        }
        if (ss >= 60) {
            ss = 0;
            mm++;
        }

        if (mm >= 60) {
            mm = 0;
            hh++;
        }

        if (hh >= 24) {
            hh = 0;
        }
    }
    return 0;
}
