//VCT nhập vào số tự nhiên N và thực hiện:
//Tìm số M bằng cách loại bỏ đi trong N tất cả các chữ số 0 và 5 và giữ nguyên thứ tự của các chữ số còn lại. Ví dụ N = 591090 thì M = 919.
//Phân tích N thành tích các thừa số nguyên tố.

#include <iostream>
using namespace std;
//Khai bao ham nhap so n
void nhapN(int& n);
//Khai bao ham loai bo chu so 0 va 5
int loaiBoChuSo(int n);
//Khai bao ham tim so dao nguoc
int soDaoNguoc(int n);
//Khai bao ham phan tich n thanh tich cac TSNT
void phanTichThanhTSNT(int n);

int main()
{
    int n;
    nhapN(n);
    cout << "So sao khi tach chu so 0 va 5 la: " << loaiBoChuSo(n) << endl;
    cout << "So N duoc phan tich thanh thua so nguyen to la: "; 
    phanTichThanhTSNT(n);
    return 0;
}

//Dinh nghia ham phan tich n thanh tich cac TSNT
void phanTichThanhTSNT(int n)
{
    int dem;
    //Tao vong lap chay tu 2 den n
    for (int i = 2; i <= n; i++)
    {
        dem = 0;
        //Neu n chia het cho i thi dem tang them 1 don vi va giam n di 1 lan
        while (n % i == 0)  
        {
            dem++;
            n /= i;
        }
        //Neu dem > 0 thi xuat ra ket qua
        if (dem > 0)    
        {
            cout << i;
            if (dem > 1) cout << "^" << dem;
            if (n > i) cout << " * ";
        }
    }
}

//Dinh nghia ham loai bo chu so 0 va 5 cua n
int loaiBoChuSo(int n)
{
    int soMoi = 0;
    while (n > 0)
    {
        if ((n % 10) != 0 && (n % 10) != 5)
        {
            soMoi = soMoi * 10 + n % 10;    // thuc hien loai bo chu so 0 va 5 cua n tuy nhien so moi nay bi nguoc
        }
        n /= 10;    //Cat bo 1 chu so hang don vi
    }
    return soDaoNguoc(soMoi);   // Tra ve dao nguoc cua so moi
}

//Dinh nghia ham dao nguoc so n
int soDaoNguoc(int n)
{
    int soDaoNguoc = 0;
    while (n > 0)
    {
        soDaoNguoc = soDaoNguoc * 10 + n % 10;  //tach chu so hang don vi va nhan them 10 roi cong voi chu so hang don vi tiep theo
        n /= 10;    //Cat bo chu so hang don vi vua tinh
    }
    return soDaoNguoc;
}

//Dinh nghia ham nhap so tu nhien n
void nhapN(int& n)
{
    cout << "Nhap so tu nhien n: "; cin >> n;
    while (n <= 0)
    {
        cout << "n phai la mot so nguyen duong!" << endl;
        cout << "Nhap so tu nhien n: "; cin >> n;
    }
}
