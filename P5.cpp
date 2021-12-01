//VCT tính căn bậc ba của một số thực chính xác đến 0.001 – áp dụng thuật toán nhị phân, không dùng đến các hàm tính toán

#include <iostream>
using namespace std;

//Khai bao ham nhap n
void Nhap(double& n);

//Khai bao ham tinh can bac 3 cua n
double tinhCanBac3(double n);

int main()
{
	double n;
	Nhap(n);
	cout << "Can bac 3 cua " << n << " la: " << tinhCanBac3(n);
	return 0;
}


//Dinh nghia ham tinh can bac 3 cua n
double tinhCanBac3(double n)
{
	double n1 = 0;
	double i = 0;
	if (n < 0) n1 = -n;	//Neu n < 0 thi n1 = -n
	else n1 = n;
	while (i * i * i < n1 - 0.001)
	{
		i += 0.001;	// Sau moi lan lap thi tang i len 0.001 cho den khi tim duoc i^3 = n1
	}
	if (n >= 0) return i;
	else return -i;	//Neu x la so am thi can bac 3 cua n cung la mot so am
}


//Dinh nghia ham nhap n
void Nhap(double& n)
{
	cout << "Nhap so thuc n: "; cin >> n;
}
