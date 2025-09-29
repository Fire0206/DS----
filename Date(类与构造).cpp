#include<iostream>
#include<iomanip>
using namespace std;
class Date
{
    int year, month, day;
public:
    Date(); 
    Date(int y, int m, int d);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int y, int m, int d);
    void print(bool withNewLine = true); 
    void addOneDay();
};

Date::Date()
{
    year = 1900;
    month = 1;
    day = 1;
}

Date::Date(int inputYear, int inputMonth, int inputDay)
{
    year = inputYear;
    month = inputMonth;
    day = inputDay;
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

void Date::setDate(int inputYear, int inputMonth, int inputDay)
{
    year = inputYear;
    month = inputMonth;
    day = inputDay;
}
void Date::print(bool withNewLine)
{
    cout << setfill('0') << setw(4) << year << '/' << setw(2) << month << '/' << setw(2) << day ;
    if(withNewLine){
        cout<<endl;
    }
}

void Date::addOneDay()
{
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int a=0;
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        a=1;
    if (a)
        daysInMonth[2] = 29;
    day++;
    if (day > daysInMonth[month])
    {
        month++;
        day = 1;
    }
    if (month > 12)
    {
        year++;
        month = 1;
    }
}

int main()
{
    int t, inputYear, inputMonth, inputDay;
    cin >> t;
    Date currentDate;
    for(int i=1;i<=t;i++)
    {
        cin >> inputYear >> inputMonth >> inputDay;
        if(i%2==0){
            currentDate.setDate(inputYear, inputMonth, inputDay);
        }
        else{
            currentDate=Date(inputYear, inputMonth, inputDay);
        }
        cout << "Today is ";
        currentDate.print();
        currentDate.addOneDay();
        cout << "Tomorrow is ";
        if(i==t){
            currentDate.print(false); 
        }else{
            currentDate.print();
        }
    }
    return 0;
}
