#include <iostream>
#include <math.h>
using namespace std;

struct DaThucBac2{
  int hso[5]={0,0,0,0,0};
};

DaThucBac2 TongHaiDaThuc(DaThucBac2 dt1, DaThucBac2 dt2){
 DaThucBac2 DaThucTong;
 for (int i=0;i<=2;i++)
    DaThucTong.hso[i]=dt1.hso[i]+dt2.hso[i];
 return DaThucTong;
}

DaThucBac2 HieuHaiDaThuc(DaThucBac2 dt1, DaThucBac2 dt2){
 DaThucBac2 DaThucHieu;
 for (int i=0;i<=2;i++)
    DaThucHieu.hso[i]=dt1.hso[i]-dt2.hso[i];
 return DaThucHieu;
}

DaThucBac2 TichHaiDaThuc (DaThucBac2 dt1, DaThucBac2 dt2){
 DaThucBac2 DaThucTich;
 for (int i=0;i<=2;i++)
    for (int j=0;j<=2;j++)
    DaThucTich.hso[i+j]+=dt1.hso[i]*dt2.hso[j];
 return DaThucTich;
}

int GiaTriDaThuc (int x, DaThucBac2 dt){
  int giatri=0;
  for (int i=0;i<=2;i++)
    giatri=dt.hso[i]*pow(x,i);
  return giatri;
}

void nhap(DaThucBac2 &dt){
  for (int i=0;i<=2;i++){
    cout<<"Nhap he so bac "<<i<<" ";
    cin>>dt.hso[i];
  }
}

void xuat(DaThucBac2 dt){
  cout<<dt.hso[0];
  for (int i=1;i<=5;i++){
    if (dt.hso[i]>0) cout<<"+"<<dt.hso[i]<<"x^"<<i;
     else if (dt.hso[i]<0) cout<<dt.hso[i]<<"x^"<<i;
  }
}

int main()
{   DaThucBac2 dathuc1, dathuc2;
    cout<<"Nhap da thuc thu nhat"<<endl;
    nhap(dathuc1);
    cout<<"Nhap da thuc thu hai"<<endl;
    nhap(dathuc2);
    cout<<"Tong hai da thuc "<<endl;
    xuat(TongHaiDaThuc(dathuc1, dathuc2));
    cout<<endl;
    cout<<"Hieu hai da thuc "<<endl;
    xuat(HieuHaiDaThuc(dathuc1, dathuc2));
    cout<<endl;
    cout<<"Tich hai da thuc "<<endl;
    xuat(TichHaiDaThuc(dathuc1,dathuc2));
    cout<<endl;
    cout<<"Gia tri cua da thuc F(0) la "<<GiaTriDaThuc(0,dathuc1);
    return 0;
}
