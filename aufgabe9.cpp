#include<iostream>
using namespace std;

class Date {
	int _day, _month, _year;
public:
    Date(int day = 0, int month = 0, int year = 0) : _day(day), _month(month), _year(year) {}
	Date operator+(int days) const {
        Date result = *this;

        result._day += days;

        while(result._day > 30) {
            result._day -= 30;
            result._month++;

            if(result._month > 12) {
                result._month = 1;
                result._year++;
            }
        }

        return result;
    }
	friend ostream & operator<<(ostream& os, const Date& d) {
        os << d._day << "." << d._month << "." << d._year;
        return os;
    }
};

int main(int argc, char *argv[])
{
    Date begin_task = Date(26,10,2023);
    cout << "Die Aufgabe beginnt am " << begin_task << endl;
    Date end_task = begin_task + 6;
    cout << "Die Aufgabe endet am " << end_task << endl;
    Date one_year_and_one_month_later = begin_task + 390;
    cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
    Date three_years_and_eleven_months_later = begin_task + 1410;
    cout << "Drei Jahre und 11 Monate nach Aufgabenbeginn ist der " << three_years_and_eleven_months_later << endl;
}