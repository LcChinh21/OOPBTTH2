#include<iostream>

using namespace std;

class NGAY {
private:
    int iNgay, iThang, iNam;

public:
    bool checkNamNhuan(int nam); //Hàm check năm nhuận
    bool checkThang(int thang); //Hàm check tháng hợp lệ
    bool checkNgay(int ngay, int thang, int nam); //Hàm check ngày hợp lệ
    void Nhap(); //Hàm nhập
    NGAY NgayThangNamTiepTheo(); //Hàm trả về ngày kế tiếp
    void Xuat(); //Hàm xuất
};

bool NGAY::checkNamNhuan(int nam) {
    if (nam % 100 != 0 && nam % 4 == 0) return true;
    else return false;
}

bool NGAY::checkThang(int thang) {
    if (thang > 0 && thang <= 12) return true;
    else return false;
}

bool NGAY::checkNgay(int ngay, int thang, int nam) {
    if (nam <= 0) return false;
    if (ngay <= 0 || ngay > 31) return false;
    if (!checkThang(thang)) return false;
    else if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
        if (ngay <= 31) return true;
    }
    else if (thang == 6 || thang == 4 || thang == 9 || thang == 11) {
        if (ngay <= 30) return true;
    }
    else if (checkNamNhuan(nam) && thang == 2 && ngay <= 29) return true;
    else if (!checkNamNhuan(nam) && thang == 2 && ngay <= 28) return true;
    return false;
}

void NGAY::Nhap() {
    cin >> iNgay >> iThang >> iNam;
    while (!checkNgay(iNgay, iThang, iNam)) {
        cout << "Ngay chua hop le!" << "\n";
        cout << "Vui long nhap lai: ";
        cin >> iNgay >> iThang >> iNam;
    }
}

NGAY NGAY::NgayThangNamTiepTheo() {
    NGAY res;
    if (iNgay > 0 && iNgay <= 28) {
        res.iNgay = this->iNgay + 1;
        res.iThang = this->iThang;
        res.iNam = this->iNam;
    }
    else if (iThang == 2 && iNgay == 28 && checkNamNhuan(iNam)) {
        res.iNgay = this->iNgay + 1;
        res.iThang = this->iThang;
        res.iNam = this->iNam;
    }
    else if (iThang == 2 && iNgay == 28 && !checkNamNhuan(iNam)) {
        res.iNgay = 1;
        res.iThang = this->iThang + 1;
        res.iNam = this->iNam;
    }
    else if (iThang == 2 && iNgay == 29 && checkNamNhuan(iNam)) {
        res.iNgay = 1;
        res.iThang = this->iThang + 1;
        res.iNam = this->iNam;
    }
    if (iThang == 1 || iThang == 3 || iThang == 5 || iThang == 7 || iThang == 8 || iThang == 10) {
        if (iNgay == 31) {
            res.iNgay = 1;
            res.iThang = this->iThang + 1;
            res.iNam = this->iNam;
        }
        else if (iNgay <= 30) {
            res.iNgay = this->iNgay + 1;
            res.iThang = this->iThang;
            res.iNam = this->iNam;
        }
    }
    else if (iThang == 12 && iNgay == 31) {
        res.iNgay = 1;
        res.iThang = 1;
        res.iNam = this->iNam + 1;
    }
    else if (iThang == 6 || iThang == 4 || iThang == 9 || iThang == 11) {
        if (iNgay == 30) {
            res.iNgay = 1;
            res.iThang = this->iThang + 1;
            res.iNam = this->iNam;
        }
        else if (iNgay <= 29) {
            res.iNgay = this->iNgay + 1;
            res.iThang = this->iThang;
            res.iNam = this->iNam;
        }
    }
    return res;
}

void NGAY::Xuat() {
    cout << iNgay << "/" << iThang << "/" << iNam << "\n";
}

int main() {
    NGAY x, y;
    x.Nhap();
    cout << "Ngay da nhap: ";
    x.Xuat();
    y = x.NgayThangNamTiepTheo();
    cout << "Ngay ke tiep: ";
    y.Xuat();
}
