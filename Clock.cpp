#include<iostream>

using namespace std;



class twoFourHourTime;


//enum here is used to check if AM or PM
enum amOrPm {

	AM, PM

}

amOrPm;


class Time
{
public:   //figured out had to public to make these accesible and use virtual. Not sure I understand the virtual part, the compiler told me to use it. 

	int hour;
	int minute;
	int second;
	virtual void addOneHour() = 0;
	virtual void addOneMinute() = 0;
	virtual void addOneSecond() = 0;

};

// 

class twelveHourTime : public Time

{

	// methods below are used to adjust time for twelve hour 

public:

	twelveHourTime(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
		amOrPm = AM;
	}

	void addOneHour()
	{
		if (hour == 11) //method adjusts the integer for hours.
		{
			hour = 0;
			amOrPm = amOrPm == AM ? PM : AM;
		} else {
			hour += 1;
		}
	}

	void addOneMinute()//method adjusts the integer for minutes.
	{
		if (minute == 59) {
			minute = 0;
			addOneHour();
		} else {
			minute += 1;
		}
	}
	void addOneSecond() //method adjusts the integer for seconds.
	{
		if (second == 59) {
			second = 0;
			addOneMinute();
		} else {
			second += 1;
		}
	}

	void displayTime(const twelveHourTime&, const twoFourHourTime&);
};



class twoFourHourTime : public Time

{

	// methods below are used to adjust time for 24 hour 

public:

	twoFourHourTime(int h, int m, int s)

	{
		hour = h;
		minute = m;
		second = s;
	}

	void addOneHour()//method adjusts the integer for hours.
	{
		if (hour == 23) {
			hour = 0;
		} else {
			hour += 1;
		}
	}
	void addOneMinute()//method adjusts the integer for minutes.
	{
		if (minute == 59) {
			minute = 0;
			addOneHour();
		}
		else {
			minute += 1;
		}
	}

	void addOneSecond()//method adjusts the integer for seconds.
	{
		if (second == 59) {
			second = 0;
			addOneMinute();
		} else {
			second += 1;
		}
	}
	
	 void displayTime(const twelveHourTime&, const twoFourHourTime&);

};


// Here is the display function. It outputs strings for headers and then outputs for time based on the functions above
void displayTime(const twelveHourTime& time12, const twoFourHourTime& time24)

{

	cout << "*************************** ***************************\n";
	cout << "    *12-Hour Clock *             * 24-Hour Clock *\n";
	cout << "   * "; if (time12.hour < 10) cout << "0"; cout << time12.hour << ":";
	if (time12.minute < 10) cout << "0"; cout << time12.minute << ":";
	if (time12.second < 10) cout << "0"; cout << time12.second;
	if (amOrPm == AM) cout << " A M"; else cout << " P M";
	cout << " *                * ";
	if (time24.hour < 10) cout << "0"; cout << time24.hour << ":";
	if (time24.minute < 10) cout << "0"; cout << time24.minute << ":";
	if (time24.second < 10) cout << "0"; cout << time24.second;
	cout << " *\n";
	cout << "*************************** ***************************\n";

}


//Below is the main that runs the changing of the time
int main()

{
	twelveHourTime time_12_Clock(11, 59, 59);
	twoFourHourTime time_24_Clock(23, 59, 59);
	displayTime(time_12_Clock, time_24_Clock);
	while (true)
	{
		cout << "***************************\n";
		cout << "* 1 - Add One Hour *\n";
		cout << "* 2 - Add One Minute *\n";
		cout << "* 3 - Add One Second *\n";
		cout << "* 4 - Exit Program *\n";
		cout << "***************************\n";
		int choice;
		cin >> choice;

		// this switch statement is where the user makes a choice on how to adjust the time. 
		switch (choice)
		{

		case 1:
			time_12_Clock.addOneHour();
			time_24_Clock.addOneHour();
			displayTime(time_12_Clock, time_24_Clock);
			break;

		case 2:
			time_12_Clock.addOneMinute();
			time_24_Clock.addOneMinute();
			displayTime(time_12_Clock, time_24_Clock);
			break;

		case 3:
			time_12_Clock.addOneSecond();
			time_24_Clock.addOneSecond();
			displayTime(time_12_Clock, time_24_Clock);
			break;

		case 4:
			cout << "Thank You!";
			exit(1);
			break;

		default:
			cout << "Error! Invalid choice!\n";
			break;
		}

	}

}