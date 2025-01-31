#include <iostream>
using namespace std;

struct PhanSo
{
    int tuso;
    int mauso;
};

void Nhap(PhanSo &x)
{
    cout<<"Nhap tu so: ";
    cin>>x.tuso;
    cout<<"Nhap mau so: ";
    cin>>x.mauso;
}

void Xuat (PhanSo x)
{
    cout<<x.tuso<<"/"<<x.mauso<<endl;
}

int findGCD(int a,int b)
{
    while (b!=0){
        int du=a%b;
        a=b;
        b=du;
    }
    return abs(a);
}

void RutGonPhanSo(PhanSo &ps)
{
    int gcd=findGCD(ps.tuso, ps.mauso);
    ps.tuso/=gcd;
    ps.mauso/=gcd;
    if (ps.mauso<0){
        ps.tuso=-ps.tuso;
        ps.mauso=-ps.mauso;
    }
}
PhanSo tongPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo PhanSoTong;
    PhanSoTong.tuso=ps1.tuso*ps2.mauso+ps2.tuso*ps1.mauso;
    PhanSoTong.mauso=ps1.mauso*ps2.mauso;

    RutGonPhanSo(PhanSoTong);
    return PhanSoTong;
}

PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo PhanSoHieu;
    PhanSoHieu.tuso=ps1.tuso*ps2.mauso-ps2.tuso*ps1.mauso;
    PhanSoHieu.mauso=ps1.mauso*ps2.mauso;

    RutGonPhanSo(PhanSoHieu);
    return PhanSoHieu;
}

PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo PhanSotich;
    PhanSotich.mauso=ps1.mauso*ps2.mauso;
    PhanSotich.tuso=ps1.tuso*ps2.tuso;

    RutGonPhanSo (PhanSotich);
    return PhanSotich;
}

PhanSo chiaPhanSo (PhanSo ps1, PhanSo ps2)
{
    PhanSo PhanSothuong;
    PhanSothuong.tuso=ps1.tuso*ps2.mauso;
    PhanSothuong.mauso=ps1.mauso*ps2.tuso;

    RutGonPhanSo (PhanSothuong);
    return PhanSothuong;
}
int main()
{
    PhanSo ps1, ps2;
    cout<< "Nhap phan so thu 1"<<endl;
    Nhap(ps1);
    cout<< "Nhap phan so thu 2"<<endl;
    Nhap(ps2);
    cout<<"Hai phan so vua nhap la: "<<endl;
    Xuat(ps1);
    Xuat(ps2);
    cout<<"Tong hai phan so vua nhap la: ";
    Xuat(tongPhanSo(ps1,ps2));
    cout<<"Tich hai phan so vua nhap la: ";
    Xuat(tichPhanSo(ps1,ps2));

    cout<<"Thuong hai phan so vua nhap la: ";
    Xuat(chiaPhanSo(ps1,ps2));

    cout<<"Hieu hai phan so vua nhap la: ";
    Xuat(hieuPhanSo(ps1,ps2));


    return 0;
}
