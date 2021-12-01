//VCT thực hiện:
//Xây dựng hàm Power(x,n) để tính lũy thừa xn của số thực x bất kỳ. (n > 0)
//Sử dụng hàm Power tính:
//S=1.5^8−(x+1)/1^2 + (x+2)^2/2^2 − (x+3)^3/3^2 + ... + (−1)^n*(x+n)^n/n^2

#include <iostream>
using namespace std;

//Khai bao ham tinh phep tinh yeu cau
double Tinh(double x, int n);

//Khai bao ham tinh luy thua
double LuyThua(double x, int n);

//Khai bao ham xuat cac phep tinh
void XuatPhepTinh(double x, int n);

//Khai bao ham nhap x, n
void Nhap(double& x, int& n);

int main()
{
    int n;
    double x;
    Nhap(x, n);     //Goi ham nhap x, n
    XuatPhepTinh(x, n); //Goi ham xuat cac phep tinh
    cout << "\nKet qua la: " << Tinh(x, n);     //Xuat ra ket qua
}

//Dinh nghia ham tinh phep tinh yeu cau
double Tinh(double x, int n)
{
    double s = 0;
    for (int i = 1; i <= n; i++)
    {
        s += LuyThua(-1, i) * LuyThua(x + i, i) / LuyThua(i, 2);
    }
    return LuyThua(1.5, 8) + s;
}

//Dinh nghia ham tinh luy thua
double LuyThua(double x, int n)
{
    double tich = 1;
    for (int i = 1; i <= n; i++)
    {
        tich *= x;  //Nhan x voi x n lan
    }
    return tich;
}

//Dinh nghia ham xuat cac phep tinh
void XuatPhepTinh(double x, int n)
{
    cout << "1.5^8";
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            cout << " - " << x + i << "^" << i << "/" << i << "^2";
        }
        else
        {
            cout << " + " << x + i << "^" << i << "/" << i << "^2";
        }
    }
}

//Dinh nghia ham nhap x, n
void Nhap(double& x, int& n)
{
    cout << "Nhap x: "; cin >> x;
    cout << "Nhap n: "; cin >> n;
    while (n < 0)
    {
        cout << "n phai lon hon 0" << endl;
        cout << "Nhap n: "; cin >> n;
    }
}
