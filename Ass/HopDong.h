#ifndef HOPDONG_H
#define HOPDONG_H

#include <bits/stdc++.h>
#include "DichVu.h"
#include "Phong.h"
using namespace std;
using namespace std::chrono;

class HopDong
{
private:
    int id;
    double tienphong;
    DichVu dv;
    string ngayBatDau;
    string ngayKetThuc;

public:
    // constructor
    HopDong() : id(0), tienphong(0.0), ngayBatDau(""), ngayKetThuc("") {}

    HopDong(int id, double tienphong, string ngayBatDau, string ngayKetThuc)
        : id(id), tienphong(tienphong), dv(), ngayBatDau(ngayBatDau), ngayKetThuc(ngayKetThuc) {}
    // getter and setter
    void setDichVu(Phong p)
    {
        dv.setGiuong(p.loaiphong);
        dv.setChieu(p.loaiphong);
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return id;
    }

    void setTienPhong(double tienphong)
    {
        this->tienphong = tienphong;
    }

    double getTienPhong()
    {
        return tienphong;
    }

    void setNgayBatDau(string ngayBatDau)
    {
        this->ngayBatDau = ngayBatDau;
    }

    string getNgayBatDau()
    {
        return ngayBatDau;
    }

    void setNgayKetThuc(string ngayKetThuc)
    {
        this->ngayKetThuc = ngayKetThuc;
    }

    string getNgayKetThuc()
    {
        return ngayKetThuc;
    }
    // nhap xuat
    void nhapThongTin()
    {
        cout << "Nhap ID: ";
        cin >> id;
        cout << "Nhap tien phong: ";
        cin >> tienphong;
        cout << "Nhap dich vu: ";
        cin.ignore();
        cout << "Nhap dich vu: ";
        cin >> dv;
        cout << "Nhap ngay bat dau (dd/mm/yyyy): ";
        getline(cin, ngayBatDau);
        cout << "Nhap ngay ket thuc (dd/mm/yyyy): ";
        getline(cin, ngayKetThuc);
    }

    void xuatThongTin()
    {
        cout << "ID: " << id << endl;
        cout << "Tien phong: " << tienphong << endl;
        cout << "Dich vu: " << dv << endl;
        cout << "Ngay bat dau: " << ngayBatDau << endl;
        cout << "Ngay ket thuc: " << ngayKetThuc << endl;
    }
    // nhap xuat voi operator
    friend istream &operator>>(istream &is, HopDong &hd)
    {
        cout << "Nhap ID: ";
        is >> hd.id;
        cout << "Nhap tien phong: ";
        is >> hd.tienphong;
        cout << "Nhap ngay bat dau: ";
        is >> hd.ngayBatDau;
        cout << "Nhap ngay ket thuc: ";
        is >> hd.ngayKetThuc;

        cout << "Nhap thong tin dich vu:\n";
        is >> hd.dv;

        return is;
    }

    // Output operator overload
    friend ostream &operator<<(ostream &os, HopDong hd)
    {
        os << "ID: " << hd.id << endl;
        os << "Tien phong: " << hd.tienphong << endl;
        os << "Ngay bat dau: " << hd.ngayBatDau << endl;
        os << "Ngay ket thuc: " << hd.ngayKetThuc << endl;
        os << "Danh sach dich vu:" << endl;
        os << dv << endl;
        return os;
    }

    // chuyen doi string sang date
    string xoakt(string s)
    {
        string result;
        for (char c : s)
        {
            if (c != '/')
            {
                result += c;
            }
        }
        return result;
    }

    int chuyenngay(string date)
    {
        int day = stoi(date.substr(0, 2));
        int month = stoi(date.substr(2, 2));
        int year = stoi(date.substr(4, 4));
        return year * 10000 + month * 100 + day;
    }

    bool sosanhth()
    {
        string s = xoakt(this->ngayBatDau);
        string ss = xoakt(this->ngayKetThuc);
        int bd = chuyenngay(s);
        int kt = chuyenngay(ss);
        if (kt - bd <= 152)
            return false;
        return true;
    }
};

#endif