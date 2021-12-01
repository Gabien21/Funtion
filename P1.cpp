// VCT nhập n, k. Tính:
//S1 = 1 + 1/2 + … + 1/n
//S2 = 2/1! - 3/2! + 4/3! - 5/4! +…+ 2n/(2n-1)! - (2n+1)/2n!
//S3 = n! / k!(n-k)!   

#include <iostream>
using namespace std;
//Khai bao ham nhap n va k
void nhap(int& n, int& k);
//Khai bao ham tinh tong nghich dao tu 1 den n
double tongNghichDao(int n);
//Khai bao ham tinh giai thua
int tinhGiaiThua(int n);
//Khai bao ham tinh cau 2
double tinhCau2(int n);
//Khai bao ham tinh to hop chap k cua n
double toHop(int n, int k);

int main() 
{
	
	int n, k;
	nhap(n, k);
	//Cau 1: S1 = 1 + 1/2 + �c + 1/n
	cout << "Ket qua cau 1 la: " << tongNghichDao(n) << endl;
	//Cau 2: S2 = 2/1! - 3/2! + 4/3! - 5/4! + �c - (2n+1)/2n!
	cout << "Ket qua cau 2 la: " << tinhCau2(n) << endl;

	//Cau 3: S3 = n! / k!(n-k)!   
	cout << "Ket qua cau 3 la: " << toHop(n, k) << endl;
	return 0;
}

//Dinh nghia ham tinh tong nghich dao tu 1 den n
double tongNghichDao(int n)
{
    double tong = 0;
    for (int i = 1; i <= n; i++)         // Dung vong lap voi i chay tu 1 den n
    {
        //Xuat cac phep tinh ra man hinh
        if (n == i) cout << "1/" << i << endl;
        else cout << "1/" << i << " + ";
        //Truyen phep tinh 1/i vao tong
        tong += (float)1 / i;
    }
    return tong;
}
//Dinh nghia ham tinh giai thua
int tinhGiaiThua(int n)
{
    int giaithua = 1;
    for (int i = 1; i <= n; i++)
    {
        giaithua *= i;
    }
    return giaithua;
}
//Dinh nghia ham tinh cau 2
double tinhCau2(int n)
{
    double tong = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        int giaithua_i = tinhGiaiThua(i);    // Tinh giai thua cua i
        if (i % 2 == 1) //Neu i le thi thuc hien 
        {
            //Xuat cac phep tinh ra man hinh
            if (i == 1) cout << i + 1 << "/" << i << "!";
            else cout << " + " << i + 1 << "/" << i << "!";
            //truyen ket qua cua phep tinh (i + 1) / i! vao tong
            tong += (i + 1) / giaithua_i;
        }
        else //Nguoc lai, neu i chan thi thuc hien
        {
            //Xuat cac phep tinh ra man hinh
            cout << " - " << i + 1 << "/" << i << "!";
            //truyen ket qua cua phep tinh -(i + 1) / i! vao tong
            tong -= (i + 1) / giaithua_i;
        }
    }
    cout << endl;
    return tong;
}
//Dinh nghia ham tinh to hop chap k cua n
double toHop(int n, int k)
{
    cout << "(" << n << "!) / (" << k << "! * " << n - k << "!)" << endl;
    return tinhGiaiThua(n) / (tinhGiaiThua(k) * tinhGiaiThua(n - k));
}
//Dinh nghia ham nhap n va k
void nhap(int& n, int& k)
{
    cout << "Moi ban nhap so nguyen duong n: "; cin >> n;
    while (n < 0)
    {
        cout << "n nhap vao phai la mot so nguyen duong!" << endl;
        cout << "Moi ban nhap lai so nguyen duong n: "; cin >> n;
    }
    cout << "Moi ban nhap so nguyen duong k: "; cin >> k;
    while (k < 0 || k > n)
    {
        if (k < 0) cout << "k nhap vao phai la mot so nguyen duong" << endl;
        else cout << "k phai be hon n" << endl;
        cout << "Moi ban nhap lai so nguyen duong k: "; cin >> k;
    }
}
