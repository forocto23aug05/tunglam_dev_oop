#include <iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

bool isLeapyear(int year)
{
    return (year%4==0&&year%100!=0 ||year%400==0);
}

void Nhap(Date &x)
{
    cout<<"Nhap ngay theo dinh dang dd mm yy";
    cin>>x.day;
    cin>>x.month;
    cin>>x.year;
}

int DaysInMonth(int month, int year)
{
  switch (month){
  case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
  case 4: case 6: case 9: case 11: return 30;
  case 2:
    return isLeapyear(year)? 29: 28;
  default:
    return 0;

  }
}

void Xuat(Date x)
{
    cout<<x.day<<"/"<<x.month<<"/"<<x.year;
}

Date getDateAfter(int x, Date &current)
{   Date DateAfter=current;
    DateAfter.day+=x;
    while (DateAfter.day>DaysInMonth(DateAfter.month,DateAfter.year)){
        x=x-(DaysInMonth(DateAfter.month,DateAfter.year)-current.day); cout<<x;
        DateAfter.month++;
        DateAfter.day=x;
    }
    DateAfter.day+=x;
    while (DateAfter.month>12){
        int res=DateAfter.month;
        DateAfter.month=DateAfter.month%12;
        DateAfter.year+=res/12;
    }
    return DateAfter;
}
int main()
{
    Date today;

    cout<<"Nhap ngay (dd mm yyyy): ";
    cin>>today.day>>today.month>>today.year;

    if (today.month<1 || today.month>12 || today.day<1||today.day>DaysInMonth(today.month,today.year)){
        cout<<"Ngay khong hop le"<<endl;
        return 1;
    }
    int x;
    cout<<"Nhap x ";
    cin>>x;
    Date dateafter=getDateAfter(x,today);
    cout<<"Sau "<<x<<" ngay la ngay "<<dateafter.day<<"/"<<dateafter.month<<"/"<<dateafter.year;
    return 0;
}
