//VCT nhập các số thực cho đến khi gặp số 0.
//Xác định số lớn nhất.
//Xác định số thực dương nhỏ nhất.
//Xác định số thực âm gần với -123.45 nhất.

#include <iostream>
#include <cmath>
using namespace std;

//Khai bao ham tim so lon hon trong hai so
double timSoLonHon(double a, double b);

//Khai bao ham tim so nho hon trong hai so
double timSoNhoHon(double a, double b);

//Khai bao ham tim khoang cach giua so n va -123.45
double khoangCachCuaN(double n);

//Khai bao ham nhap n
void nhap(double& n);

int main()
{
    double n = 1;   //Tao bien n = 1 den khoi chay vong lap
    double max = -9999999999;
    double min = 9999999999;
    double min2 = 9999999999;
    double a = 0;
    bool flag1 = false, flag2 = false;
    while (n != 0)   //Vong lap ket thuc khi n = 0
    {
        nhap(n);    //Nhap n
        max = timSoLonHon(max, n);    //Neu tim duoc n nao lon hon max thi truyen n do vao max
        if (n > 0) min = timSoNhoHon(min, n);   ////Neu tim duoc n nao nho hon min thi truyen n do vao min
        //Tim so thuc am gan nhat voi so -123.45
        if (n < 0 && khoangCachCuaN(n) < min2)
        {
            a = n;
            min2 = khoangCachCuaN(n);
        }
        //Kiem tra trong cac so vua nhap co so thuc am hay so thuc duong khong
        if (n > 0) flag1 = true;    //Neu co n > 0 thi flag1 = true
        if (n < 0) flag2 = true;    //Neu co n > 0 thi flag2 = true
    }
    cout << "So lon nhat trong cac so vua nhap la: " << max << endl;
    if (flag1 == true) cout << "So thuc duong nho nhat trong cac so vua nhap la: " << min << endl;
    else cout << "Trong cac so vua nhap, khong co so thuc duong nao!" << endl;
    if (flag2 == true) cout << "So thuc am gan voi -123.45 nhat la: " << a << endl;
    else cout << "Trong cac so vua nhap, khong co so thuc am nao!" << endl;
    return 0;
}

//Dinh nghia ham tim so lon hon trong hai so
double timSoLonHon(double a, double b)
{
    if (a > b) return a;
    else return b;
}

//Dinh nghia ham tim so nho hon trong hai so
double timSoNhoHon(double a, double b)
{
    if (a < b) return a;
    else return b;
}

//Dinh nghia ham tim khoang cach giua so n va -123.45
double khoangCachCuaN(double n)
{
    return abs(n + 123.45);
}

//Dinh nghia ham nhap n
void nhap(double& n)
{
    cout << "Nhap so thuc n: "; cin >> n;
}
