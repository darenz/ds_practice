#include<iostream>
#include<sstream>
#include<string>
using namespace std;

bool isRunnian(int year)
{
    if( year%400 == 0)
        return true;
    else if(year%4 == 0)
        return true;
    else 
        return false;
}

string getDate(int n)
{
    n++;
    int i = 0;
    int days = 0;
    int idays = 0;
    while(days<n)
    {
        int f = isRunnian(2000+i);
        if(f == true)
        {
            idays = 366; 
            days += idays;
        }
        else 
        {
            idays = 365;
            days += idays;
        }
        i++;
    }
    i--;
    days -= idays;
    int left_days = n-days;
    int date_year = 2000+i; 
    int date_month = 0;
    int date_day= 1;
    int t_days = 0;
    int add_days = 0;
    while(t_days < left_days)
    {
        date_month++;
        switch(date_month)
        {
            case 1:
                add_days = 31;
                break;
            case 2:
                if(isRunnian(date_year))
                    add_days = 29;
                else
                    add_days = 28;
                break;
            case 3:
                add_days = 31;
                break;
            case 4:
                add_days = 30;
                break;
            case 5:
                add_days = 31;
                break;
            case 6:
                add_days = 30;
                break;
            case 7:
                add_days = 31;
                break;
            case 8:
                add_days = 31;
                break;
            case 9:
                add_days = 30;
                break;
            case 10:
                add_days = 31;
                break;
            case 11:
                add_days = 30;
                break;
            case 12:
                add_days = 31;
                break;
            default :
                return 0;
        }
        t_days += add_days;
    }
    t_days -= add_days;
    date_day = left_days - t_days;
    stringstream ss_year;
    ss_year<<date_year;
    stringstream ss_month;
    ss_month<<date_month;
    stringstream ss_day;
    ss_day<<date_day;

    int dd = (n-1)%7;
    string ddd;
    switch(dd)
    {
        case 0:
            ddd = "Sat.";
            break;
        case 1:
            ddd = "Sun.";
            break;
        case 2:
            ddd = "Mon";
            break;
        case 3:
            ddd = "Tues";
            break;
        case 4:
            ddd = "wens";
            break;
        case 5:
            ddd = "Thu";
            break;
        case 6:
            ddd = "Fri";
            break;
        default :
            return 0;
    }
    
    string s;
    s = ss_year.str() + " " + ss_month.str() + " "+ ss_day.str() + " " + ddd;
    return s;
}

int main()
{
    string s;
    int n;
    cin>>n;
    s = getDate(n);
    cout<<s<<endl;
    return 0;
}
