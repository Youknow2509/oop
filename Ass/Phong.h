#ifndef Phong_H 
#define Phong_H

#include <iostream>
#include <list>
#include "HopDong.h" 
#include "Person/Nguoi.h"
#include "Person/BaoVe.h"
#include "Person/SinhVien.h"

using namespace std;

class Phong {
private:
    int id;
    int soPhong;
    int soToa;
    int loaiPhong;
    int soDien;
    int soNuoc;
    HopDong a;
    list<SinhVien> dsSV;

public:
    Phong() {}
    Phong(int id, int soPhong, int soToa, int loaiPhong, int soDien, int soNuoc)
        : id(id), soPhong(soPhong), soToa(soToa), loaiPhong(loaiPhong), soDien(soDien), soNuoc(soNuoc) {}

    int getSoPhong() {
        return soPhong;
    }

    void setSoPhong(int soPhong) {
        this->soPhong = soPhong;
    }

    int getSoToa() {
        return soToa;
    }

    void setSoToa(int soToa) {
        this->soToa = soToa;
    }

    int getLoaiPhong() {
        return loaiPhong;
    }

    void setLoaiPhong(int loaiPhong) {
        this->loaiPhong = loaiPhong;
    }

    int getSoDien() {
        return soDien;
    }

    void setSoDien(int soDien) {
        this->soDien = soDien;
    }

    int getSoNuoc() {
        return soNuoc;
    }

    void setSoNuoc(int soNuoc) {
        this->soNuoc = soNuoc;
    }

    void setID(int id) {
        this->id = id;
    }

    int getID() {
        return id;
    }
    void themSV(SinhVien sv) {
        dsSV.push_back(sv);
    }
    void xoaSV(SinhVien sv) {
        dsSV.remove(sv);
    }
    HopDong getHopDong() {
        return a;
    }

    void setHopDong(HopDong a) {
        this->a = a;
    }

    SinhVien timSV(int id) {
        for (auto i = dsSV.begin(); i != dsSV.end(); i++) {
            if (i->getID() == id) {
                return *i;
            }
        }
        return SinhVien();
    }

    int soNguoiTrongPhong() {
        return dsSV.size();
    }

    // Nhap xuat voi operator
    friend istream& operator>>(istream& is, Phong& phong) {
        cout << "Nhap so phong: ";
        is >> phong.soPhong;
        cout << "Nhap so toa: ";
        is >> phong.soToa;
        cout << "Nhap loai phong: ";
        is >> phong.loaiPhong;
        cout << "Nhap so dien: ";
        is >> phong.soDien;
        cout << "Nhap so nuoc: ";
        is >> phong.soNuoc;
        cout << "Nhap thong tin hop dong:\n";
        is >> phong.a; 
        return is;
    }

    friend ostream& operator<<(ostream& os, const Phong& phong) {
        os << "So phong: " << phong.soPhong << endl;
        os << "So toa: " << phong.soToa << endl;
        os << "Loai phong: " << phong.loaiPhong << endl;
        os << "So dien: " << phong.soDien << endl;
        os << "So nuoc: " << phong.soNuoc << endl;
        os << "Thong tin hop dong:\n" << phong.a; 
        return os;
    }
    // Tinh tien phong
    int tinhTienPhong() {
        return a.getTienPhong();
    }
};

#endif 

