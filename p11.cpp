//Bài 1. VCT tìm tất cả các số nguyên tố X (10<=X<=65535) thỏa mãn:
//X là số nguyên tố
//X là số Fibonacci
//Ít nhất có một số nguyên tố được tạo thành khi thay đổi vị trí các chữ số của X.
//Hướng dẫn: Tìm tất cả các số Fibonacci nhỏ hơn 65535. Với mỗi số Fibonacci tìm được hãy kiểm tra số này có phải là số nguyên tố hay không. 
//Sau đó tìm mọi hoán vị của số thỏa 2 điều kiện trên xem có tồn tại một hoán vị nào tạo thành số nguyên tố, thì in kết quả ra màn hình.

//Bai nay em chua nghi ra cach hoan vi cac so a
#include <iostream>
using namespace std;

//Khai bao ham tim so Fibonaccy
int Fibonacci(int k);
//Khai bao ham kiem tra so nguyen to
int KiemTraSoNguyenTo(int n);

int main()
{
    for (int i = 3; ; i++)
    {
        int a = Fibonacci(i);       //gan so fibonaccy thu i cho bien a
        if (a >= 10 && a <= 65535)  //Neu a lon hon hoac bang 10 va be hon hoac bang 65535 thi thuc hien cac lenh sau
        {
            if (KiemTraSoNguyenTo(a) == 1) cout << a << " ";    //Neu a la so nguyen to thi xuat ra a
        }
        if (a > 65535) break;   //Neu a > 65535 thi dung vong lap
    }
    return 0;
}

//Dinh nghia ham tim so Fibonaccy
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

//Dinh nghia ham kiem tra so nguyen to
int KiemTraSoNguyenTo(int n)
{
    //Dung vong lap de kiem tra trong cac so tu 2 den n - 1
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0) return 0;   // neu co so nao chia het cho n thi tra ve 0
    }
    return 1;
}
