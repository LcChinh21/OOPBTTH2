#include<iostream>
using namespace std;

class SoPhuc {
private:
    float iThuc, iAo;
public:
    void Nhap(); //Ham nhap
    void Xuat(); //Ham xuat
    SoPhuc Tong(SoPhuc other); //Ham tra ve tong 2 so phuc
    SoPhuc Hieu(SoPhuc other); //Ham tra ve hieu 2 so phuc
    SoPhuc Tich(SoPhuc other); //Ham tra ve tich 2 so phuc
    SoPhuc Thuong(SoPhuc other); //Ham tra ve thuong 2 so phuc
};

void SoPhuc::Nhap() {
    cout << "Nhap phan thuc: ";
    cin >> iThuc;
    cout << "\n";
    cout << "Nhap phan ao: ";
    cin >> iAo;
    cout << "\n";
}

void SoPhuc::Xuat() {
    if (iAo < 0)
        cout << iThuc << " - " << -iAo << "i" << endl;
    else
        cout << iThuc << " + " << iAo << "i" << endl;
}

SoPhuc SoPhuc::Tong(SoPhuc other) {
    SoPhuc res;
    res.iThuc = iThuc + other.iThuc;
    res.iAo = iAo + other.iAo;
    return res;
}

SoPhuc SoPhuc::Hieu(SoPhuc other) {
    SoPhuc res;
    res.iThuc = iThuc - other.iThuc;
    res.iAo = iAo - other.iAo;
    return res;
}

SoPhuc SoPhuc::Tich(SoPhuc other) {
    SoPhuc res;
    res.iThuc = iThuc * other.iThuc - iAo * other.iAo;
    res.iAo = iThuc * other.iAo + iAo * other.iThuc;
    return res;
}

SoPhuc SoPhuc::Thuong(SoPhuc other) {
    SoPhuc res;
    float denominator = other.iThuc * other.iThuc + other.iAo * other.iAo;
    if (denominator != 0) {
        res.iThuc = (iThuc * other.iThuc + iAo * other.iAo) / denominator;
        res.iAo = (iAo * other.iThuc - iThuc * other.iAo) / denominator;
    } else {
        cout << "Loi: Khong the chia cho so phuc voi phan thuc va phan ao bang 0!" << endl;
    }
    return res;
}

int main() {
    SoPhuc a, b, tong, hieu, tich, thuong;
    
    cout << "Nhap so phuc a:" << endl;
    a.Nhap();
    cout << "Nhap so phuc b:" << endl;
    b.Nhap();
    cout << "So phuc a: ";
    
    a.Xuat();
    cout << "So phuc b: ";
    b.Xuat();
    tong = a.Tong(b);
    hieu = a.Hieu(b);
    tich = a.Tich(b);
    thuong = a.Thuong(b);

    cout << "Tong: ";
    tong.Xuat();

    cout << "Hieu: ";
    hieu.Xuat();

    cout << "Tich: ";
    tich.Xuat();

    cout << "Thuong: ";
    thuong.Xuat();

    return 0;
}
