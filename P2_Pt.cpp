//Một số Amstrong có đặc điểm: số đó có n ký tự, tổng các lũy thừa bậc n của các ký số bằng chính nó. Ví dụ số 153, có 3 chữ số và 13+53+33=153.
//Viết hàm kiểm tra số nguyên dương x có thỏa điều kiện không.
//Nếu x thỏa, hãy liệt kê các số Amstrong nhỏ hơn x^n

#include <iostream>
using namespace std;
//Khai bao ham nhap x
void nhapX(int& x);
//Khai bao ham tinh luy thua
int luyThua(int x, int n);
//Khai bao ham tinh so ky tu cua n
int soKyTu(int n);
//Khai bao ham tinh tong luy thua
int tongLuyThua(int x);
//Khai bao ham kiem tra x co phai la so Amstrong hay khong
int kiemTra(int x);

int main()
{
	int x;
	nhapX(x);
	int KT = kiemTra(x);
	if (KT == 1)	//Neu bien KT bang 1 thi day la so Amstrong
	{
		cout << "Day la so Amstrong!" << endl;
		//Dung vong lap de tim den tat ca gia tri tu 0 den x^n
		cout << "Cac so Amstrong nho hon x^n la: ";
		for (int i = 1; i < luyThua(x, soKyTu(x)); i++)
		{
			if (kiemTra(i) == 1) cout << i << " "; //Neu i la so Amstrong thi xuat ra i
		}
	}
	else cout << "Day khong phai la so Amstrong!" << endl;
	return 0;
}

//Dinh nghia ham tinh tong luy thua
int tongLuyThua(int x)
{
	int tachSo = 0;
	int s = 0;
	int n = soKyTu(x);
	while (x > 0)
	{
		tachSo = x % 10;	//Tach chu so hang don vi cua x
		s += luyThua(tachSo, n);	//Tinh luy thua cua chu so hang don vi vua tach va truyen vao s 
		x /= 10;	//Cat bo chu so hang don vi da tinh
	}
	return s;
}

//Dinh nghia ham tinh luy thua
int luyThua(int x, int n)
{
	int p = 1;
	for (int i = 1; i <= n; i++)
	{
		p *= x;
	}
	return p;
}

//Dinh nghia ham tinh so ky tu
int soKyTu(int n)
{
	int dem = 0;
	while (n > 0)
	{
		n /= 10;
		dem++;
	}
	return dem;
}

//Dinh nghia ham kiem tra
int kiemTra(int x)
{
	//Neu tong luy thua bang chinh x thi tra ve gia tri 1
	if (tongLuyThua(x) == x) return 1;
	else return 0;	//Nguoc lai thi tra ve gia tri 0
}

//Dinh nghia ham nhap vao x
void nhapX(int& x)
{
	cout << "Nhap so tu nhien x: "; cin >> x;
	while (x <= 0)
	{
		cout << "x phai la mot so nguyen duong!" << endl;
		cout << "Nhap so tu nhien x: "; cin >> x;
	}
}
