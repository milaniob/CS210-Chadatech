#pragma once
#include<iostream>
using namespace std;
//Craete a class Time
class Clock {
	//Member variables
private:
	int hours;
	int minutes;
	int seconds;
	//Member functions
public:
	Clock();
	Clock(int hrs, int mnts, int secs);
	void setHours(int hrs);
	void setMinutes(int mnts);
	void setSeconds(int secs);
	int getHrs();
	int getMinutes();
	int getSeconds();
	void display24format();
	void display12format();
	void incrementHr();
	void incrementMinute();
	void incrementSec();
};