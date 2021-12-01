//VCT nhập vào 1 số nguyên dương, kiểm tra xem tổng các chữ số có bằng tích và xuất ra thông báo tương ứng, lặp lại việc trên cho đến khi nhập số 0.

#include <iostream>
using namespace std;

//Khai bao ham tinh tong cac chu so cua n
int tongCacChuSo(int n);

//Khai bao ham tinh tich cac chu so cua n
int tichCacChuSo(int n);

//Khai bao ham nhap n
int nhap(int& n);

int main()
{
	int n;
	//Vong lap cho den khi n = 0 thi dung lai
	while (1)
	{
		nhap(n);	//Tiep tuc nhap n
		if (n == 0) break;	//Neu n = 0 thoat khoi vong lap
		//Neu tong cac chu so bang tich cac chu so thi xuat ra thong bao
		else if (tongCacChuSo(n) == tichCacChuSo(n)) cout << "Tong cac chu so bang tich cac chu so!" << endl;
		else cout << "Tong cac chu so khong bang tich cac chu so!" << endl;
	}
	return 0;
}

//Dinh nghia ham tinh tong cac chu so cua n
int tongCacChuSo(int n)
{
	int tong = 0;
	int tach_so = 0;
	while (n > 0)
	{
		tach_so = n % 10;	//Tach chu so hang don vi cua n
		tong += tach_so;	//Truyen chu so hang don vi vao tong
		n /= 10;			//Cat bo chu so hang don vi vua tinh
	}
	return tong;
}

//Dinh nghia ham tinh tich cac chu so cua n
int tichCacChuSo(int n)
{
	int tich = 1;
	int tach_so = 0;
	while (n > 0)
	{
		tach_so = n % 10;	//Tach chu so hang don vi cua n
		tich *= tach_so;	//Truyen chu so hang don vi vao tich
		n /= 10;			//Cat bo chu so hang don vi vua tinh
	}
	return tich;
}

//Dinh nghia ham nhap n
int nhap(int& n)
{
	cout << "Nhap so nguyen duong n: "; cin >> n;
	while (n < 0)
	{
		cout << "Ban phai nhap so nguyen duong!" << endl;
		cout << "Nhap so nguyen duong n: "; cin >> n;
	}
	return n;
}
