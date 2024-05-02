#ifndef HopDong_H
#define HopDong_H

#include <iostream>
#include "DichVu.h"
#include "Phong.h"

using namespace std;

class HopDong {
private:
    int id;
    double tienphong;
    double tiennuoc = 20.0;
	double tiendien = 3.5;
    DichVu dv;
    string ngayBatDau;
    string ngayKetThuc;

public:
    HopDong() : id(0), tienphong(0.0), ngayBatDau(""), ngayKetThuc("") {}
    
    HopDong(int id, double tienphong, string ngayBatDau, string ngayKetThuc)
        : id(id), tienphong(tienphong), dv(), ngayBatDau(ngayBatDau), ngayKetThuc(ngayKetThuc) {}

    //getter and setter
	
	
    void setId(int id) {
        this->id = id;
    }

    int getId() {
        return id;
    }

    void setTienPhong(double tienphong) {
        this->tienphong = tienphong;
    }

    double getTienPhong() {
        return tienphong;
    }


    void setNgayBatDau(string ngayBatDau) {
        this->ngayBatDau = ngayBatDau;
    }

    string getNgayBatDau() {
        return ngayBatDau;
    }

    void setNgayKetThuc(string ngayKetThuc) {
        this->ngayKetThuc = ngayKetThuc;
    }

    string getNgayKetThuc() {
        return ngayKetThuc;
    }
    
    void setTienNuoc(double tn){
    	this->tiennuoc = tn;
	}
	double getTienNuoc(){
		return this->tiennuoc;
	}
	void setTienDien(double td){
    	this->tiendien = td;
	}
	double getTienDien(){
		return this->tiendien;
	}
	//nhap xuat
    void nhapThongTin() {
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

    void xuatThongTin() {
        cout << "ID: " << id << endl;
        cout << "Tien phong: " << tienphong << endl;
        cout << "Dich vu: " << dv << endl;
        cout << "Ngay bat dau: " << ngayBatDau << endl;
        cout << "Ngay ket thuc: " << ngayKetThuc << endl;
    }
    
    void giaHan() {
        cout << "Nhap ngay bat dau moi: ";
        cin >> this->ngayBatDau;
        cout << "Nhap ngay ket thuc moi: ";
        cin >> this->ngayKetThuc;
    }
    
    // Input and output with operator overloading
    friend istream& operator>>(istream& is, HopDong& hd);
    friend ostream& operator<<(ostream& os, const HopDong& hd);
};	

	//Nhap xuat voi operator
	istream& operator>>(istream& is, HopDong& hd) {
	    cout << "Nhap ID: ";
	    is >> hd.id;
	    cout << "Nhap tien phong: ";
	    is >> hd.tienphong;
        is.ignore();
	    cout << "Nhap ngay bat dau (dd/mm/yyyy): ";
	    is >> hd.ngayBatDau;
	    cout << "Nhap ngay ket thuc (dd/mm/yyyy): ";
	    is >> hd.ngayKetThuc;
	
	    cout << "Nhap thong tin dich vu:\n";
	    is >> hd.dv;
	
	    return is;
	}

	
	ostream& operator<<(ostream& os, const HopDong& hd) {
	    os << "ID: " << hd.id << endl;
	    os << "Tien phong: " << hd.tienphong << endl;
	    os << "Tien dien: " << hd.tiendien << endl;
	    os << "Tien nuoc: " << hd.tiennuoc << endl;
	    os << "Ngay bat dau: " << hd.ngayBatDau << endl;
	    os << "Ngay ket thuc: " << hd.ngayKetThuc << endl;
	    os << "Dich vu: " << hd.dv << endl;
	    return os;
	}

#endif // HopDong_H

