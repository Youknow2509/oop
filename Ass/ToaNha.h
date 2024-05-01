#ifndef ToaNha_H 
#define ToaNha_H
#include<bits/stdc++.h>
#include"Phong.h"
#define ll long long
using namespace std;


class ToaNha {
private:
    int soTang;
    int soluongphong;
    vector<Phong> dsPhong;
    string tenToa;

public:
	//constructor 
    ToaNha() : soTang(0), soluongphong(0), tenToa("") {}
    
    ToaNha(int soTang, int soluongphong, const string& tenToa)
        : soTang(soTang), soluongphong(soluongphong), tenToa(tenToa) {}

    // Getter - setter
    void setSoTang(int soTang) {
        this->soTang = soTang;
    }

    int getSoTang() {
        return soTang;
    }

    void setSoLuongPhong(int soluongphong) {
        this->soluongphong = soluongphong;
    }

    int getSoLuongPhong() const {
        return soluongphong;
    }

    void setTenToa(const string& tenToa) {
        this->tenToa = tenToa;
    }

    const string& getTenToa()  {
        return tenToa;
    }

    // Nhap xuat voi toan tu  
    friend istream& operator>>(istream& is, ToaNha& toaNha) {
        cout << "Nhap ten toa: ";
        getline(is, toaNha.tenToa);
        cout << "Nhap so tang: ";
        is >> toaNha.soTang;
        cout << "Nhap so luong phong: ";
        is >> toaNha.soluongphong;
        is.ignore(); 

        cout << "Nhap thong tin cho tung phong:" << endl;
        for (int i = 0; i < toaNha.soluongphong; ++i) {
            Phong phong;
            cout << "Phong " << i + 1 << ":" << endl;
            is >> phong;
            toaNha.dsPhong.push_back(phong);
        }

        return is;
    }

    friend ostream& operator<<(ostream& os, const ToaNha& toaNha) {
        os << "Ten toa: " << toaNha.tenToa << endl;
        os << "So tang: " << toaNha.soTang << endl;
        os << "So luong phong: " << toaNha.soluongphong << endl;
        os << "Danh sach phong:" << endl;
        for (auto& phong : toaNha.dsPhong) {
            os << phong << endl;
        }
        return os;
    }
};

#endif

