
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
    //
    void indssinhvienphong(Phong p);
    void indsphongtrong(ToaNha tn);
    void indssinhviendanoptien(ToaNha tn);
    void indssinhvienchuanoptien(ToaNha tn);
    //
    bool checksinhvientontai(int idsinhvien);
    bool checksinhviendanoptien(int idsinhvien);
    bool checkphongdanoptien(int idsinhvien);
    bool checkphongchuanoptien(int idsinhvien);
    bool checkphongtrong(int idphong);

    // Getter - Setter
    vector<SinhVien>& getlSinhVien() {
        return lSinhVien;
    }
    void setlSinhVien(vector<SinhVien> lSinhVien) {
        this->lSinhVien = lSinhVien;
    }
    vector<Phong>& getlPhong() {
        return lPhong;
    }
    void setlPhong(vector<Phong> lPhong) {
        this->lPhong = lPhong;
    }
    vector<ToaNha>& getlToaNha() {
        return lToaNha;
    }
    void setlToaNha(vector<ToaNha> lToaNha) {
        this->lToaNha = lToaNha;
    }

    // Help funtion
    Phong timPhong(int id);
    int soluongtrongphong(int idphong);
    void HienThiDSPhongTrong();

};

QuanLi::QuanLi() {
    this->lBaoVe = vector<BaoVe>();
    this->lPhong = vector<Phong>();
    this->lSinhVien = vector<SinhVien>();
    this->lToaNha = vector<ToaNha>();
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

void QuanLi::HienThiDSPhongTrong() {
    for (int i = 0; i <= this->lPhong.size(); i++) {
        Phong ph = lPhong[i];
        if (ph.getSoNguoiTrongPhong() < ph.getSoNguoiToiDa()) {
            cout << ph.getID() << endl;
        }
    }
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

void QuanLi :: indssinhvienphong(Phong p){
	cout << "\nDanh sach sinh vien trong phong";
	SinhVien sv;
	
} 

void QuanLi :: indsphongtrong(ToaNha tn){
	
} 

void QuanLi :: indssinhviendanoptien(ToaNha tn){
	
}

void QuanLi :: indssinhvienchuanoptien(ToaNha tn){
	
}



// // 1. Them sinh vien   
// void Handle1(SinhVien& sv) {
//     cout << sv;
//     cout << "Danh sach phong co the vao:";
//     ql.HienThiDSPhongTrong();
//     cout << "Nhap ID phong muon vao: ";
//     int idPh; 
//     cin >> idPh;
//     cin.ignore();
//     sv.setSoPhong(idPh);
//     ql.themSV(idPh, sv);

//     return;
// }

void Application() {
    bool loop = true;
    QuanLi ql;
    Phong phong1(1, 1, 1, 4, 12, 20, 4);
    HopDong contract1(1, 500.0, "01/01/2024", "31/12/2024");
    phong1.setHopDong(contract1);
    
    ql.getlPhong().push_back(phong1);
    ql.getlPhong().push_back(Phong(2, 1, 1, 4, 12, 20, 4));

    while (loop) {
    	 cout << "                                -------------------------------------" << endl;
	    cout << "                                |";
	    cout << setw(26) << "Quan li Ki tuc xa";
	    cout << "         |" << endl;
	    cout << "                                -------------------------------------" << endl;
        cout << "--------------------------------------" << endl;
        cout << "| 1. Them sinh vien                  |" << endl; // Nhap thong tin va chon chuc nang
        cout << "| 2. Xoa sinh vien                   |" << endl;
        cout << "| 3. Gia han hop dong                |" << endl;
        cout << "| 4. Chuyen phong                    |" << endl;
        cout << "| 5. Tinh tien phong                 |" << endl;
        cout << "| 6. Tinh tien sinh vien             |" << endl;
        cout << "| 7. Them phong                      |" << endl;
        cout << "| 8. Xoa phong                       |" << endl;
        cout << "| 9. Xem danh sach sinh vien                           |" << endl;
        cout << "| 10. Xem danh sach phong              |" << endl;
        cout << "| 11. Xem danh sach phong trong        |" << endl;
        cout << "| 12. Xem danh sach toa nha               |" << endl;
        cout << "| 13. Thoat                           |" << endl;
        cout << "--------------------------------------" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                int idPhong;
                SinhVien sv;
                cout << "Nhap id phong :";
                cin >> idPhong ;
                cout << "Nhap thong tin sinh vien: ";
                cin >> sv;
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
                cout << "Nhap id phong: ";
                cin >> idPhong;
                ql.giaHanHD(idPhong);
                break;
            }
            case 4: {
                int idPhong;
                SinhVien sv;
                cout << "Nhap id phong: ";
                cin >> idPhong;
                cout << "Nhap thong tin sinh vien: ";
                cin >> sv;
                ql.chuyenPhong(sv, idPhong);
                break;
            }
            case 5: {
                int idPhong;
                cout << "Nhap id phong: ";
                cin >> idPhong;
                ql.tinhThuePhong(idPhong);
                break;
            }
            case 6: {
                SinhVien sv;
                cout << "Nhap thong tin sinh vien: ";
                cin >> sv;
                ql.tinhTienSV(sv);
                break;
            }
            case 7: {
                int idPhong;
                cout << "Nhap id phong: ";
                cin >> idPhong;
                ql.themPhong(idPhong);
                break;
            }
            case 8: {
                int idPhong;
                cout << "Nhap id phong: ";
                cin >> idPhong;
                ql.xoaPhong(idPhong);
                break;
            }
            case 9: {
                for (int i = 0; i < ql.getlSinhVien().size(); i++) {
                    cout << ql.getlSinhVien()[i];
                }
                break;
            }
            case 10: {
                cout << ql.getlPhong().size() << endl;
                for (int i = 0; i < ql.getlPhong().size(); i++) {
                    cout << ql.getlPhong()[i];
                }
                break;
            }
            case 11: {
                ql.HienThiDSPhongTrong();
                break;
            }
            case 12: {
                for (int i = 0; i < ql.getlToaNha().size(); i++) {
                    cout << ql.getlToaNha()[i];
                }
                break;
            }
            case 13: {
                loop = false;
                break;
            }
        }
    }
}

int main () {

    Application();

    return 0;
}

