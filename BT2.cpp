#include<iostream>

using namespace std;

class PhanSo {
private:
    int iTu, iMau;

public:
    void Nhap(); //Ham nhap
    void Xuat(); //Ham xuat
    void RutGon(); //Ham rut gon phan so
    PhanSo Tong(PhanSo other); //Ham tra ve tong 2 phan so
    PhanSo Hieu(PhanSo other); //Ham tra ve hieu 2 phan so
    PhanSo Tich(PhanSo other); //Ham tra ve tich 2 phan so
    PhanSo Thuong(PhanSo other); //Ham tra ve thuong 2 phan so
    int SoSanh(PhanSo other); //Ham so sanh 2 phan so
    int UCLN(int a, int b); //Ham tinh UCLN
};

int PhanSo::UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void PhanSo::Nhap() {
    cout << "Nhap tu: ";
    cin >> iTu;
    cout << "\n";
    cout << "Nhap mau: ";
    cin >> iMau;
    cout << "\n";
    while (iMau == 0) {
        cout << "Mau phai khac 0. Nhap lai mau: ";
        cin >> iMau;
        cout << "\n";
    }
}

void PhanSo::Xuat() {
    if (iMau == 1) cout << iTu;
    else if ((iTu < 0 && iMau < 0) || (iTu > 0 && iMau < 0)) {
        cout << iTu * (-1) << "/" << -iMau * (-1);
    }
    else {
        cout << iTu << "/" << iMau;
    }
    cout << "\n";
}

void PhanSo::RutGon() {
    int tmp = UCLN(iTu, iMau);
    iTu /= tmp;
    iMau /= tmp;
}

PhanSo PhanSo::Tong(PhanSo other) {
    PhanSo res;
    res.iTu = iTu * other.iMau + other.iTu * iMau;
    res.iMau = iMau * other.iMau;
    res.RutGon();
    return res;
}

PhanSo PhanSo::Hieu(PhanSo other) {
    PhanSo res;
    res.iTu = iTu * other.iMau - other.iTu * iMau;
    res.iMau = iMau * other.iMau;
    res.RutGon();
    return res;
}

PhanSo PhanSo::Tich(PhanSo other) {
    PhanSo res;
    res.iTu = iTu * other.iTu;
    res.iMau = iMau * other.iMau;
    res.RutGon();
    return res;
}

PhanSo PhanSo::Thuong(PhanSo other) {
    PhanSo res;
    if (other.iTu != 0) {
        res.iTu = iTu * other.iMau;
        res.iMau = iMau * other.iTu;
        res.RutGon();
    } else {
        cout << "Loi: Khong the chia cho phan so co tu = 0!" << endl;
    }
    return res;
}

int PhanSo::SoSanh(PhanSo other) {
    int thisTu = iTu * other.iMau;
    int otherTu = other.iTu * iMau;

    if (thisTu > otherTu) return 1;
    if (thisTu < otherTu) return -1;
    return 0;
}

int main() {
    PhanSo a, b;

    cout << "Nhap phan so 1:" << "\n";
    a.Nhap();
    cout << "Nhap phan so 2:" << "\n";
    b.Nhap();

    a.RutGon();
    b.RutGon();
    cout << "Phan so thu 1: ";
    a.Xuat();
    cout << "Phan so thu 2: ";
    b.Xuat();
    PhanSo tong = a.Tong(b);
    PhanSo hieu = a.Hieu(b);
    PhanSo tich = a.Tich(b);
    PhanSo thuong = a.Thuong(b);

    cout << "TONG: ";
    tong.Xuat();
    cout << "HIEU: ";
    hieu.Xuat();
    cout << "TICH: ";
    tich.Xuat();
    cout << "THUONG: ";
    thuong.Xuat();

    cout << "SO SANH 2 PHAN SO: ";
	if(a.SoSanh(b)){
		a.Xuat();
		cout << " > ";
		b.Xuat();
	}
	else if(a.SoSanh(b) == 0){
		a.Xuat();
		cout << " = ";
		b.Xuat();
	}
	else{
		a.Xuat();
		cout << " < ";
		b.Xuat();
	}
    return 0;
}
