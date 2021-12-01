//VCT tìm ước số chung lớn nhất của 2 số nguyên dương M và N.

#include <iostream>
using namespace std;

//Khai bao ham nhap m,n
void nhap(int& m, int& n);
//Khai bao ham tim UCLN
int timUCLN(int m, int n);

int main()
{
	int m, n;
	nhap(m, n);
	cout << "Uoc chung lon nhat cua " << m << " va " << n << " la: " << timUCLN(m, n);
	return 0;
}

//Dinh nghia ham tim UCLN
int timUCLN(int m, int n)
//Uoc chung lon nhat cua hai so nguyen khong thay doi khi thay the so lon hon bang hieu cua no voi so nho hon
//Dung vong lap de tinh cho den khi a = b thi dung vong lap
{
	while (m != n)
	{
		if (m > n) m -= n;   //Neu m > n thi thay m bang m - n
		else if (m < n) n -= m;  //Neu n > m thi thay n bang n - m
	}
}

//Dinh nghia ham nhap m,n
void nhap(int& m, int& n)
{
	cout << "Nhap m: "; cin >> m;
	while (m < 0)
	{
		cout << "m phai la mot so nguyen duong!" << endl;
		cout << "Nhap m: "; cin >> m;		
	}

	cout << "Nhap n: "; cin >> n;
	while ( n < 0)
	{
		cout << "n phai la mot so nguyen duong!" << endl;
		cout << "Nhap n: "; cin >> n;		
	}
}
