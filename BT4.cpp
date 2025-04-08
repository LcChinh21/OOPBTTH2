#include<iostream>
using namespace std;

class GioPhutGiay {
private:
    int iGio, iPhut, iGiay;
public:
    void Nhap(); //Ham nhap
    void Xuat(); //Ham xuat
    GioPhutGiay TinhCongThemMotGiay(); //Ham tra ve GioPhutGiay khi cong them 1 giay
};

void GioPhutGiay::Nhap() {
    cout << "Nhap gio: ";
    cin >> iGio;
    cout << "\n";
    cout << "Nhap phut: ";
    cin >> iPhut;
    cout << "\n";
    cout << "Nhap giay: ";
    cin >> iGiay;
    cout << "\n";
}

void GioPhutGiay::Xuat() {
    cout << iGio << " gio " << iPhut << " phut " << iGiay << " giay" << endl;
}

GioPhutGiay GioPhutGiay::TinhCongThemMotGiay() {
    GioPhutGiay res = *this;
    res.iGiay++;
    if (res.iGiay == 60) {
        res.iGiay = 0;
        res.iPhut++;
        if (res.iPhut == 60) {
            res.iPhut = 0;
            res.iGio++;
            if (res.iGio == 24) {
                res.iGio = 0;
            }
        }
    }
    return res;
}

int main() {
    GioPhutGiay time;
    time.Nhap();
    cout << "Thoi gian ban dau: ";
    time.Xuat();

    GioPhutGiay newTime = time.TinhCongThemMotGiay();
    cout << "Thoi gian sau khi cong them mot giay: ";
    newTime.Xuat();

    return 0;
}
