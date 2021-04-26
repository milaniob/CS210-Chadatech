/*
Program to display time in 12 and 24 format
*/
#include <cstdlib>
#include<ctime>
#include<Windows.h>
#include "clockHeader.h"

//Function prototypes
void display(Clock clock);
int menu();

int main()
{
    //Clear screen
    system("CLS");
    //Current time
    time_t now = time(0);
    //Get seconds,minutes and hour
    struct tm timeSplitter;
    timeSplitter = *localtime(&now);
    //Create object
    Clock clock(timeSplitter.tm_hour, timeSplitter.tm_min, timeSplitter.tm_sec);
    //Display formatted time
    display(clock);
    //Sleep and clear screen
    Sleep(1000);
    system("CLS");

    //Display menu
    int opt = menu();
    //Loop until exit
    while (opt != 4) {
        //Each option
        if (opt == 1) {
            clock.incrementHr();
            display(clock);
        }
        else if (opt == 2) {
            clock.incrementMinute();
            display(clock);
        }
        else if (opt == 3) {
            clock.incrementSec();
            display(clock);
        }
        //Sleep and clear after 1 second
        Sleep(1000);
        system("CLS");
        opt = menu();
    }
    return 0;
}

//Function to display time in 2 time format
void display(Clock clock) {
    cout << "****************************** ******************************\n"
        << " *     12 - Hour Clock       * *        24 - Hour Clock     *\n"
        << " *       ";
    clock.display12format();
    cout << "         * *             ";
    clock.display24format();
    cout << "       *\n"
        << " ***************************** ******************************\n";
}
//User options and return menu
int menu() {
    int opt;
    cout << "\n******************************\n"
        << "* 1 - Add One Hour   *\n"
        << "* 2 - Add One Minute *\n"
        << "* 3 - Add One Second *\n"
        << "* 4 - Exit Program   *\n"
        << "******************************\n";
    cin >> opt;
    return opt;
}