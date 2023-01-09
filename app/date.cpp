#include <iostream>
#include <string>

using namespace std;

class Date {
    private:
        int month, day, year;
        string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    public:
        //constructors
        Date();
        Date(int, int, int);
        //destructor
        ~Date(){};

        void setDay(int);
        void setMonth(int);
        void setYear(int);
        int getDay();
        int getMonth();
        int getYear();
        void displayDate();
};

Date::Date()
{
    month = 0, day = 0, year = 0;
}

Date::Date(int Month, int Day, int Year) {
    month = Month;
    day = Day;
    year = Year;
}

void Date::setDay(int d) {
    if (d < 1 || d > 31) cout << "Invalid day" << endl;
    else day = d;
}

void Date::setMonth(int m) {
    if (m < 1 || m > 12) cout << "Invalid month" << endl;
    else month = m;
}

void Date::setYear(int y) {
    if (y > 2022) cout << "Invalid year" << endl;
    else year = y;
}

int Date::getDay() {
	return day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

void Date::displayDate() {
    cout << month << " /" << day << " /" << year << endl;
}