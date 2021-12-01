//VCT nhập một số nguyên dương n. Xác định:
//Tổng các chữ số của số vừa nhập có bằng tích.
//Các chữ số này có tăng dần hay giảm dần không?
//Số này có phải là số đối xứng? (các chữ số đối xứng, vd: 77, 191, 2002,..)
//Số này có phải là số nguyên tố?
//Số này có phải là số hoàn chỉnh (bằng tổng các ước nhỏ hơn nó, vd 6 = 1+2+3)

#include <iostream>
using namespace std;

//Khai bao ham kiem tra tong va tich cua cac chu so co bang nhau khong
int kiemTraTongVaTich(long n);

//Khai bao ham kiem tra cac chu so cua n co tang dan hay khong
int kiemTraTangDan(long n);

//Khai bao ham kiem tra cac chu so cua n co giam dan hay khong
int kiemTraGiamDan(long n);

//Khai bao ham kiem tra cac chu so cua n co doi xung hay khong
int kiemTraDoiXung(long n);

//Khai bao ham kiem tra n co phai la so nguyen to hay khong
bool kiemTraSoNguyenTo(long n);

//Khai bao ham kiem tra n co phai la so hoan chinh hay khong
bool kiemTraSoHoanChinh(long n);

//Khai bao ham tinh tong cac chu so cua n
long tongCacChuSo(long n);

//Khai bao ham tinh tich cac chu so cua n
long tichCacChuSo(long n);

//Khai bao ham tim so dao nguoc cua n
int soDaoNguoc(long n);

//Khai bao ham nhap n
void nhap(long& n);

int main()
{
	long n;
	nhap(n);

	//Kiem tra xem tong cac chu so cua n co bang tich cac chu so cua n khong
	int KT = kiemTraTongVaTich(n);
	if (KT == 1) cout << "Tong cac chu so bang tich cac chu so!" << endl;
	else cout << "Tong cac chu so khong bang tich cac chu so!" << endl;

	//Kiem tra xem cac chu so cua n co thu tu tang dan, giam dan hay khong
	int KTtang = kiemTraTangDan(n);
	int KTgiam = kiemTraGiamDan(n);
	if (KTtang == 1 && KTgiam == 0) cout << "So vua nhap co thu tu tang dan!" << endl;
	else if (KTtang == 0 && KTgiam == 1) cout << "So vua nhap co thu tu giam dan!" << endl;
	else if((KTtang == 1 && KTgiam == 1) || (KTtang == 0 && KTgiam == 0)) 
		cout << "So vua nhap khong co thu tu khong tang dan cung khong giam dan!" << endl;

	//Kiem tra n co phai la so doi xung hay khong
	if (kiemTraDoiXung(n)) cout << "Day la so doi xung!" << endl;
	else cout << "Day khong phai la so doi xung!" << endl;

	//Kiem tra n co phai la so nguyen to hay khong
	if (kiemTraSoNguyenTo(n)) cout << "Day la so nguyen to!" << endl;
	else cout << "Day khong phai la so nguyen to!" << endl;

	//Kiem tra n co phai la so hona chinh hay khong
	if (kiemTraSoHoanChinh(n)) cout << "Day la so hoan chinh!" << endl;
	else cout << "Day khong phai la so hoan chinh!" << endl;
	return 0;
}

//Dinh nghia ham kiem tra tong va tich cua cac chu so co bang nhau khong
int kiemTraTongVaTich(long n)
{
	int a = tongCacChuSo(n);	//Tinh tong cac chu so cua n
	int b = tichCacChuSo(n);	//Tinh tich cac chu so cua n
	if (a == b) return 1;		//Neu tong = tich thi tra ve 1
	else return 0;				//Nguoc lai, tra ve 0
}

//Dinh nghia ham kiem tra cac chu so cua n co tang dan hay khong
int kiemTraTangDan(long n)
{
	int a1, a2;
	bool flag = true;	//Gan gia tri true cho bien flag
	a1 = n % 10;		//Truyen chu so hang don vi vao bien a1
	n /= 10;			//Loai bo chu so hang don vi vua tach
	while (n > 0)
	{
		a2 = n % 10;					//Truyen chu so hang don vi moi vao bien a2
		if (a2 >= a1)
		{
			flag = false;		//Neu a1 <= a2 thi flag mang gia tri false
			break;
		}
		a2 = a1;						//Truyen gia tri cua a2 vao a1
		n /= 10;						//Loai bo chu so hang don vi va tiep tuc vong lap
	}
	if (flag) return 1;		//Neu flag = true thi tra ve 1
	else return 0;			//Nguoc lai tra ve 0
}

//Dinh nghia ham kiem tra cac chu so cua n co giam dan hay khong
int kiemTraGiamDan(long n)
{
	int a1, a2;
	bool flag = true;	//Gan gia tri true cho bien flag
	a1 = n % 10;		//Truyen chu so hang don vi vao bien a1
	n /= 10;			//Loai bo chu so hang don vi vua tach
	while (n > 0)
	{
		a2 = n % 10;					//Truyen chu so hang don vi moi vao bien a2
		if (a2 <= a1)
		{
			flag = false;		//Neu a1 >= a2 thi flag mang gia tri false
			break;
		}
		a2 = a1;						//Truyen gia tri cua a2 vao a1
		n /= 10;						//Loai bo chu so hang don vi va tiep tuc vong lap
	}
	if (flag) return 1;		//Neu flag = true thi tra ve 1
	else return 0;			//Nguoc lai tra ve 0
}

//Dinh nghia ham kiem tra cac chu so cua n co doi xung hay khong
int kiemTraDoiXung(long n)
{
	//Neu so dao nguoc cua n bang chinh no thi n la so doi xung
	if (soDaoNguoc(n) == n) return 1;
	else return 0;
}

//Dinh nghia ham kiem tra n co phai la so nguyen to hay khong
bool kiemTraSoNguyenTo(long n)
{
	//So nguyen to la so chi chia het cho 1 va chinh no
	for (int i = 2; i < n; i++)	//Tao vong lap voi i chay tu 2 den n-1
	{
		if (n % i == 0)	//Neu co gia tri i nao chia het cho n thi tra ve false
		{
			return false;
		}
	}
	return true;
}

//Dinh nghia ham kiem tra n co phai la so hoan chinh hay khong
bool kiemTraSoHoanChinh(long n)
{
	long tong = tongCacChuSo(n);
	//Neu tong cac chu so cua n bang chinh no thi n la so hoan chinh
	if (tong == n) return true;
	else return false;
}

//Dinh nghia ham tinh tong cac chu so cua n
long tongCacChuSo(long n)
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
long tichCacChuSo(long n)
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

//Dinh nghia ham tim so dao nguoc cua n
int soDaoNguoc(long n)
{
	int soDaoNguoc = 0;
	while (n > 0)
	{
		soDaoNguoc = soDaoNguoc * 10 + n % 10;		//Dao nguoc vi tri cac chu so cua so ban nhap vao
		n /= 10;									//Loai bo mot chu so hang don vi va tiep tuc vong lap
	}
	return soDaoNguoc;
}

//Dinh nghia ham nhap n
void nhap(long& n)
{
	cout << "Nhap so nguyen duong n: "; cin >> n;
	while (n <= 0)
	{
		cout << "n phai la mot so nguyen duong!" << endl;
		cout << "Nhap so nguyen duong n: "; cin >> n;
	}
}
