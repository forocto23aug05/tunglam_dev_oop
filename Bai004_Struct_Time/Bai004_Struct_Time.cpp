#include <iostream>
using namespace std;

struct time{
 int hour;
 int minute;
 int second;
};

void nhap(time &tg){
  cin>>tg.hour;
  cin>>tg.minute;
  cin>>tg.second;
}

void xuat(time tg){
  cout<<"Thoi gian sau la "<< tg.hour<<":"<<tg.minute<<":"<<tg.second;
}

bool check(time tg){
if (tg.hour>23 || tg.hour<0 || tg.minute<0 || tg.minute>=60 || tg.second<0 || tg.second>=60) return false;
return true;
}

time ThoiGianSau(time current, time after){
    time timeafter=current;
    timeafter.second+=after.second;
    timeafter.minute+=after.minute;
    timeafter.hour+=after.hour;
    if (timeafter.second>=60){
        int res=timeafter.second/60;
        timeafter.second=timeafter.second%60;
        timeafter.minute+=res;
    }

    if (timeafter.minute>=60){
        int res=timeafter.minute/60;
        timeafter.minute=timeafter.minute%60;
        timeafter.hour+=res;
    }

    while (timeafter.hour>=24){
        timeafter.hour=timeafter.hour%24;
    }
    return timeafter;
}



int main()
{
   time t1, t2, t3;
   cout<<"Nhap thoi gian ban dau "; nhap(t1);
   cout<<"Nhap thoi gian muon thay doi "; nhap(t2);
   if (!check(t1) || t2.minute<0 || t2.minute>=60 || t2.second<0 || t2.second>=60){
        cout<<"Thoi gian da nhap khong hop le ";
        return 0;
   }
   t3=ThoiGianSau(t1, t2);
   xuat(t3);

    return 0;
}
