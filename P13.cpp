//VCT nhập vào số nguyên n và thực hiện:
//Xuất ra màn hình tam giác có chiều cao n có tính chất sau: hàng i gồm i số đầu tiên của chuỗi Fibonaci (có hai giá trị đầu là 1 và 1)
//Xuất ra tam giác Pascal chiều cao n.

#include <iostream>
using namespace std;

//Khai bao ham xuat tam giac Fibonaccy
void XuatTamGiacFibonacci(int h);

//Khai bao ham xuat tam giac Pascal
void XuatTamGiacPascal(int h);

//Khai bao ham tinh so fibonaccy thu k
int Fibonacci(int k);

//Khai bao ham tinh giai thua
int GiaiThua(int n);

//Khai bao ham tinh to hop chap k cua n phan tu
int ToHop(int k, int n);

//Khai bao ham nhap chieu cao h cua tam giac
void NhapChieuCao(int& h);

int main()
{
    int h;
    NhapChieuCao(h);            //Nhap vao chieu cao cua tam giac
    XuatTamGiacFibonacci(h);    //Xuat tam giac Fibonaccy
    XuatTamGiacPascal(h);       //Xuat tam giac Pascal
    return 0;
}

//Dinh nghia ham xuat tam giac Fibonaccy
void XuatTamGiacFibonacci(int h)
{
    cout << "Tam giac Fibonacci co chieu cao " << h << ": " << endl;
    for (int i = 0; i < h; i++)     //Xuat chieu cao h dong cua tam giac
    {
        for (int j = h - 1; j > i; j--) cout << " ";    //Xuat cac khoang trang theo thu tu giam tu h-1 xuong 0
        for (int j = 0; j <= i; j++)
        {
            cout << Fibonacci(j) << " ";                //Xuat cac so fibonaccy trong 1 dong
        }
        cout << endl;
    }
    cout << endl;
}

//Dinh nghia ham xuat tam giac Pascal
void XuatTamGiacPascal(int h)
{
    cout << "Tam giac Pascal co chieu cao " << h << ": " << endl;
    for (int i = 0; i < h; i++)     //Xuat chieu cao h dong cua tam giac
    {
        for (int j = h - 1; j > i; j--) cout << " ";        //Xuat cac khoang trang theo thu tu giam tu h-1 xuong 0
        for (int j = 0; j <= i; j++)
        {
            cout << ToHop(j, i) << " ";                     //Xuat cac so to hop chap j cua i phan tu trong 1 dong
        }
        cout << endl;
    }
    cout << endl;
}

//Dinh nghia ham tinh so fibonaccy thu k
int Fibonacci(int k)
{
    int f = 0, f0 = 0, f1 = 1;
    if (k == 0) f = 0;			//Neu k = 0 thi f = f0 = 0 theo gia thiet de bai cho
    else if (k == 1) f = 1;		//Neu k = 1 thi f = f1 = 1 theo gia thiet de bai cho
    else		//Neu k khac 0 va khac 1 thi thuc hien vong lap
    {
        for (int i = 2; i <= k; i++)
        {
            f = f0 + f1;		//Cho f = f0 + f1
            f0 = f1;			//Truyen gia tri f1 cho f0
            f1 = f;				//Truyen gia tri f1 cho f
        }
    }
    return f;
}

//Dinh nghia ham tinh giai thua
int GiaiThua(int n)
{
    if (n == 0) return 1;
    int giaiThua = 1;
    for (int i = 1; i <= n; i++)
    {
        giaiThua *= i;
    }
    return giaiThua;
}

//Dinh nghia ham tinh to hop chap k cua n phan tu
int ToHop(int k, int n)
{
    return GiaiThua(n) / (GiaiThua(k) * GiaiThua(n - k));
}

//Dinh nghia ham nhap chieu cao h cua tam giac
void NhapChieuCao(int& h)
{
    cout << "Nhap chieu cao cua tam giac: "; cin >> h;
    while (h <= 0)
    {
        cout << "Chieu cao phai la mot so nguyen duong!" << endl;
        cout << "Nhap chieu cao cua tam giac: "; cin >> h;
    }
}
