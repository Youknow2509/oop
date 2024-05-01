
#include <bits/stdc++.h>

#include "Ass/Person/SinhVien.h"
#include "Ass/Person/Nguoi.h"
#include "Ass/Person/BaoVe.h"

#include "Ass/Phong.h"
#include "Ass/DichVu.h"
#include "Ass/HopDong.h"
#include "Ass/ToaNha.h"

using namespace std;

class QuanLi {
    private:
        vector<SinhVien> lSinhVien;
        vector<Phong> lPhong;
        vector<ToaNha> lToaNha;
        vector<BaoVe> lBaoVe;
    public:
    // Constructor
    QuanLi();
    QuanLi(vector<SinhVien> lSinhVien, vector<Phong> lPhong, vector<ToaNha> lToaNha, vector<BaoVe> lBaoVe);
    void themSV(int idPhong, SinhVien sv);
    void xoaSV(SinhVien sv);
    void giaHanHD(int idPhong);
    void chuyenPhong(SinhVien sv, int idPhongMoi);
    void tinhThuePhong(int idPhong);
    void tinhTienSV(SinhVien sv);
    void xoaPhong(int idPhong);
    void themPhong(int idPhong);
    // Help funtion
    Phong timPhong(int id);
};

QuanLi::QuanLi() {

}

QuanLi::QuanLi(vector<SinhVien> lSinhVien, vector<Phong> lPhong, vector<ToaNha> lToaNha, vector<BaoVe> lBaoVe) {
    this->lBaoVe = lBaoVe;
    this->lPhong = lPhong;
    this->lSinhVien = lSinhVien;
    this->lToaNha  = lToaNha;
}

void QuanLi::themSV(int idPhong, SinhVien sv) {
    Phong ph = timPhong(idPhong);
    ph.themSV(sv);
}

void QuanLi::xoaSV(SinhVien sv) {
    for (int i = 0; i < lPhong.size(); i++) {
        lPhong[i].xoaSV(sv);
    }
}

void QuanLi::giaHanHD(int idPhong) {
    Phong ph = timPhong(idPhong);
    ph.getHopDong().giaHan();
}

void QuanLi::chuyenPhong(SinhVien sv, int idPhong) {
    for (int i = 0; i < lPhong.size(); i++) {
        if (lPhong[i].timSV(sv.getID()).getID() == sv.getID()){
            lPhong[i].xoaSV(sv);
            break;
        }   
    }
    themSV(idPhong, sv);
}

void QuanLi::themPhong(int idPhong) {
    Phong ph;
    cin >> ph;
    lPhong.push_back(ph);
}

void QuanLi::xoaPhong(int idPhong) {
    for (int i = 0; i < lPhong.size(); i++) {
        if (lPhong[i].getID() == idPhong) {
            lPhong.erase(lPhong.begin() + i);
            break;
        }
    }
}


void QuanLi::tinhThuePhong(int idPhong) {
    Phong ph = timPhong(idPhong);
    cout << "Tien thue phong: " << ph.tinhTienPhong() << endl;
}

void QuanLi::tinhTienSV(SinhVien sv) {
    Phong ph;
    for (int i = 0; i < lPhong.size(); i++) {
        if (lPhong[i].timSV(sv.getID()).getID() == sv.getID()) {
            ph = lPhong[i];
            break;
        }
    }
    cout << "Tien phong: " << ph.tinhTienPhong()/ph.soNguoiTrongPhong() << endl;
}


// Help funtion
Phong QuanLi::timPhong(int id) {
    for (int i = 0; i < lPhong.size(); i++) {
        if (lPhong[i].getID() == id) {
            return lPhong[i];
        }
    }
    return Phong();
}

int main () {

    bool loop = true;

    QuanLi ql;

    while (loop) {
        cout << "1. Them sinh vien" << endl;
        cout << "2. Xoa sinh vien" << endl;
        cout << "3. Gia han hop dong" << endl;
        cout << "4. Chuyen phong" << endl;
        cout << "5. Tinh tien phong" << endl;
        cout << "6. Tinh tien sinh vien" << endl;
        cout << "7. Them phong" << endl;
        cout << "8. Xoa phong" << endl;
        cout << "9. Thoat" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                int idPhong;
                SinhVien sv;
                cin >> idPhong >> sv;
                ql.themSV(idPhong, sv);
                break;
            }
            case 2: {
                SinhVien sv;
                cin >> sv;
                ql.xoaSV(sv);
                break;
            }
            case 3: {
                int idPhong;
                cin >> idPhong;
                ql.giaHanHD(idPhong);
                break;
            }
            case 4: {
                int idPhong;
                SinhVien sv;
                cin >> idPhong >> sv;
                ql.chuyenPhong(sv, idPhong);
                break;
            }
            case 5: {
                int idPhong;
                cin >> idPhong;
                ql.tinhThuePhong(idPhong);
                break;
            }
            case 6: {
                SinhVien sv;
                cin >> sv;
                ql.tinhTienSV(sv);
                break;
            }
            case 7: {
                int idPhong;
                cin >> idPhong;
                ql.themPhong(idPhong);
                break;
            }
            case 8: {
                int idPhong;
                cin >> idPhong;
                ql.xoaPhong(idPhong);
                break;
            }
            case 9: {
                loop = false;
                break;
            }
        }
    }
    

    return 0;
}

