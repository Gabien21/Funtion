//VCT nhập vào số nguyên dương N và thực hiện:
//a) Kiểm tra N có phải là số Palindrom không, nếu các chữ số của nó viết theo thứ tự ngược lại thì bằng
//chính nó, ví dụ 121 hay 1221.
//b) Tìm tất cả các số Palindrom >10 và <100 mà bình phương của chúng cũng là số Palindrom.
//c) Nếu N không phải là số Palindrom thì thay đổi thứ tự của các chữ số của nó theo thứ tự ngược lại và
//cộng với số ban đầu. Nếu tổng chưa phải là một số Palindrom thì lặp lại quá trình trên đối với tổng đó
//cho đến khi nhận được một số Palindrom.

#include <iostream>
using namespace std;
//Khai bao ham nhap
void nhapN(int& n);
//Khai bao ham dao nguoc so
int soDaoNguoc(int n);
//Khai bao ham kiem tra so do co phai la so Palindrom khong
int kiemTraPalindrom(int n);

int main()
{
	int n;
	nhapN(n);
	int KT = kiemTraPalindrom(n);
	//kiem tra n co phai la so palindrom hay khong
	if (KT == 1) cout << "Day la so Palindrom!" << endl;
	else
	{
		cout << "Day khong phai la so Palindrom!" << endl;
		//Tao vong lap n cong voi so dao nguoc cua n cho den khi tim duoc so palindrom thi dung lai
		while (kiemTraPalindrom(n) == 0) n += soDaoNguoc(n);	
		cout << "Sau khi thay doi, so Palindrom tim duoc la: " << n << endl;
	}

	cout << "Cac so Palindrom trong khoang 11 den 99 la: ";
	for (int i = 11; i < 100; i++)
	{
		//kiem tra i va i^2 co phai la so palindrom hay khong
		if (kiemTraPalindrom(i) && kiemTraPalindrom(i * i)) cout << i << " ";
	}
	return 0;
}

//Dinh nghia ham kiem tra so Palindrom
int kiemTraPalindrom(int n)
{
    if (soDaoNguoc(n) == n) return 1;
    else return 0;
}

//Dinh nghia ham dao nguoc n
int soDaoNguoc(int n)
{
    int soDaoNguoc = 0;
    while (n > 0)
    {
        soDaoNguoc = soDaoNguoc * 10 + n % 10;
        n /= 10;
    }
    return soDaoNguoc;
}

//Dinh nghia ham nhap n
void nhapN(int& n)
{
    cout << "Nhap so nguyen duong n: "; cin >> n;
    while (n <= 0)
    {
        cout << "n phai la mot so nguyen duong!" << endl;
        cout << "Nhap so nguyen duong n: "; cin >> n;
    }
}
