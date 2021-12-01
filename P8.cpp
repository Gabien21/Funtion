//Viết chương trình (VCT) nhập ba số nguyên a,b,c. Kiểm tra xem chúng có thứ tự như thế nào (tăng, giảm, hay không tăng cũng không giảm). 
//Sau đó thực hiện các việc:
//Nếu tăng: Giải bất phương trình bậc hai aX^2+bX+c>0
//Nếu giảm: Giải phương trình bậc hai aX^2+bX+c<0
//Không tăng không giảm: Giải phương trình bậc hai aX^2+bX+c=0

#include <iostream>
#include <cmath>
using namespace std;

//Khai bao ham kiem tra a , b, c co tang dan, giam dan hay khong
int kiemTra(int& a, int& b, int& c);

//Khai bao ham giai phuong trinh bac 1
void giaiPTBac1(int b, int c);

//Khai bao ham giai BPT bx + c > 0
void giaiBPTBac1Lon(int b, int c);

//Khai bao ham giai BPT bx + c < 0
void giaiBPTBac1Nho(int b, int c);

//Khai bao ham tinh delta
int tinhDelta(int a, int b, int c);

//Khai bao ham giai phuong trinh bac 2
void giaiPTBac2(int a, int b, int c);

//Khai bao ham giai BPT ax^2 + bx + c > 0
void giaiBPTBac2Lon(int a, int b, int c);

//Khai bao ham giai BPT ax^2 + bx + c < 0
void giaiBPTBac2Nho(int a, int b, int c);

//Khai bao ham nhap a, b, c
void nhap(int& a, int& b, int& c);

int main()
{
	int a, b, c;
	nhap(a, b, c);
	int KQ = kiemTra(a, b, c);	//Kiem tra xem a,b,c co tang dan, giam dan hay khong
	if (KQ == 1)	//Neu a, b, c co thu tu tang dan
	{
		cout << "Cac so ban vua nhap co thu tu tang dan!" << endl;
		cout << "Giai bat phuong trinh: ax^2 + bx + c > 0" << endl;
		//Neu a = 0 thi giai BPT bx + c > 0
		if (a == 0)	giaiBPTBac1Lon(b, c);
		//Neu a khac 0 thi giai BPT ax^2 + bx + c > 0
		else giaiBPTBac2Lon(a, b, c);
	}
	else if (KQ == 2)	//Neu a, b, c co thu tu giam dan
	{
		cout << "Cac so ban vua nhap co thu tu giam dan!" << endl;
		cout << "Giai bat phuong trinh: ax^2 + bx + c < 0" << endl;
		//Neu a = 0 thi giai BPT bx + c < 0
		if (a == 0)  giaiBPTBac1Nho(b, c);
		//Neu a khac 0 thi giai BPT ax^2 + bx + c < 0
		else giaiBPTBac2Nho(a, b, c);
	}
	else	//Nguoc lai la a, b, c khong tang khong giam
	{
		cout << "Cac so ban vua nhap co thu tu khong tang khong giam!" << endl;
		cout << "Giai phuong trinh ax^2 + bx + c = 0" << endl;
		//Neu a = 0 thi giai PT bx + c = 0
		if (a == 0) giaiPTBac1(b, c);
		//Neu a khac 0 thi giai PT ax^2 + bx + c = 0
		else giaiPTBac2(a, b, c);
	}
	return 0;
}

//Dinh nghia ham kiem tra a , b, c co tang dan, giam dan hay khong
int kiemTra(int& a, int& b, int& c)
{
	if (a < b && a < c) return 1;
	else if (a > b && a > c) return 2;
	else return 0;
}

//Dinh nghia ham giai phuong trinh bac 1
void giaiPTBac1(int b, int c)
{
    if (b == 0) //Neu b = 0
    {
        if (c == 0) cout << "Phuong trinh vo so nghiem!" << endl;    //Neu c = 0
        else cout << "Phuong trinh vo nghiem!" << endl;             //Neu c khac 0
    }
    else cout << "Nghiem cua phuong trinh la: x = " << (double)(-c) / b;  //Neu b khac 0     
}

//Dinh nghia ham giai BPT bx + c > 0
void giaiBPTBac1Lon(int b, int c)
{
	//vi a < b < c va a = 0 nen b va c khong the bang 0
	cout << "Tap nghiem cua bat phuong trinh la: x > " << (double)(-c) / b;
}

//Dinh nghia ham giai BPT bx + c < 0
void giaiBPTBac1Nho(int b, int c)
{
	//vi a > b > c va a = 0 nen b va c khong the bang 0          
	cout << "Tap nghiem cua bat phuong trinh la: x > " << (double)(-c) / b << endl;
}

//Dinh nghia ham tinh delta
int tinhDelta(int a, int b, int c)
{
	return b * b - 4 * a * c;
}

//Dinh nghia ham giai phuong trinh bac 2
void giaiPTBac2(int a, int b, int c)
{
    int delta = tinhDelta(a, b, c);
    if (delta < 0) cout << "Phuong trinh vo nghiem!" << endl;    //Neu delta < 0
    else if (delta == 0) cout << "Phuong trinh co nghiem kep: x = " << (-b) / (2 * a);  //Neu delta = 0
    else    //Neu delta > 0
    {
        cout << "Phuong trinh co hai nghiem phan biet! " << endl;
        cout << "x1 = " << (-b + (double)sqrt(delta)) / (2 * a) << endl;
        cout << "x2 = " << (-b - (double)sqrt(delta)) / (2 * a) << endl;
    }
}

//Dinh nghia ham giai BPT ax^2 + bx + c > 0
void giaiBPTBac2Lon(int a, int b, int c)
{
	int delta = tinhDelta(a, b, c);
    if (delta < 0)   // Neu delta < 0
    {
        if (a > 0) cout << "Bat phuong trinh luon dung voi moi x" << endl;
        else cout << "Khong co gia tri x nao thoa man bat phuong trinh!" << endl;
    }
    else if (delta == 0) //Neu delta = 0
    {
        if (a > 0) cout << "Bat phuong trinh dung voi moi x khac " << (-b) / (2 * a) << endl;
        else cout << "Khong co gia tri x nao thoa man bat phuong trinh!" << endl;
    }
    else //Neu delta  > 0
    {
        if (a > 0)
        {
            cout << "Bat phuong trinh dung voi: " << endl;
            cout << "x < " << (double)(-b - sqrt(delta)) / (2 * a) << " , x > " << (double)(-b + sqrt(delta)) / (2 * a);
        }
        else
        {
            cout << "Bat phuong trinh dung voi: " << endl;
            cout << (double)(-b + sqrt(delta)) / (2 * a) << " < x < " << (double)(-b - sqrt(delta)) / (2 * a);
        }
    }
}

//Dinh nghia ham giai BPT ax^2 + bx + c < 0
void giaiBPTBac2Nho(int a, int b, int c)
{
    int delta = tinhDelta(a, b, c);
    if (delta < 0)   //Neu delta < 0
    {
        if (a > 0) cout << "Khong co gia tri x nao thoa man bat phuong trinh!" << endl;
        else cout << "Bat phuong trinh luon dung voi moi x" << endl;
    }
    else if (delta == 0) //Neu delta = 0
    {
        if (a > 0) cout << "Khong co gia tri x nao thoa man bat phuong trinh!" << endl;
        else cout << "Bat phuong trinh dung voi moi x khac " << (-b) / (2 * a) << endl;
    }
    else    //Neu delta > 0
    {
        if (a > 0)
        {
            cout << "Bat phuong trinh dung voi: " << endl;
            cout << (double)(-b - sqrt(delta)) / (2 * a) << " < x < " << (double)(-b + sqrt(delta)) / (2 * a);
        }
        else
        {
            cout << "Bat phuong trinh dung voi: " << endl;
            cout << "x < " << (double)(-b + sqrt(delta)) / (2 * a) << " , x > " << (double)(-b - sqrt(delta)) / (2 * a);
        }
    }
}

//Dinh nghia ham nhap a, b, c
void nhap(int& a, int& b, int& c)
{
    cout << "Nhap a: "; cin >> a;
    cout << "Nhap b: "; cin >> b;
    cout << "Nhap c: "; cin >> c;
}
