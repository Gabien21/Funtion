//Xác định phần tử thứ k của dãy Fibonacci:  F(0)=0;  F1=(1);  F(n)=F(n-1)+F(n-2) 

#include <iostream>
using namespace std;
//Khai bao ham nhap k
void nhap(int& k);
//Khai bao ham tinh phan tu thu k cua day fibonancy
int fibonancy(int k);

int main()
{
	int k;
	nhap(k);
	//Vi phan tu thu nhat la f0 nen phan tu thu k la f(k-1)
	cout << "Phan tu thu " << k << " la: " << fibonancy(k - 1);
	return 0;
}

//Dinh nghia ham tinh phan tu thu k cua day fibonancy
int fibonancy(int k)
{
	int f = 0, f0 = 0, f1 = 1;
	if (k == 0) return 0;			//Neu k = 0 thi f = f0 = 0 theo gia thiet de bai cho
	else if (k == 1) return 1;		//Neu k = 1 thi f = f1 = 1 theo gia thiet de bai cho
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
//Dinh nghia ham nhap k
void nhap(int& k)
{
	cout << "Nhap k: "; cin >> k;
	while (k < 1)
	{
		cout << "k phai lon hon hoac bang 1" << endl;
		cout << "Nhap k: "; cin >> k;
	}
}
