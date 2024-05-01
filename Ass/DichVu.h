#ifndef DichVu_H
#define DichVu_H

#include <bits/stdc++.h>
#include <iostream> 

using namespace std; 
class DichVu {
private:
    int giuong;
    int chieu;
    int nonglanh;
    int dieuhoa;
    int giuonghong;
    int chieuhong;
    int nonglanhhong;
    int dieuhoahong;

public:
    // constructor
    DichVu(int giuong, int chieu, int nonglanh, int dieuhoa, int giuonghong, int chieuhong, int nonglanhhong, int dieuhoahong)
        : giuong(giuong), chieu(chieu), nonglanh(nonglanh), dieuhoa(dieuhoa),
          giuonghong(giuonghong), chieuhong(chieuhong), nonglanhhong(nonglanhhong), dieuhoahong(dieuhoahong) {}

    DichVu()
        : giuong(1), chieu(1), nonglanh(1), dieuhoa(1), giuonghong(0), chieuhong(0), nonglanhhong(0), dieuhoahong(0) {}

    // C�c ph��ng th?c getter v� setter
    int getGiuong() const {
        return giuong;
    }

    void setGiuong(int value) {
        giuong = value;
    }

    int getChieu() const {
        return chieu;
    }

    void setChieu(int value) {
        chieu = value;
    }

    int getNongLanh() const {
        return nonglanh;
    }

    void setNongLanh(int value) {
        nonglanh = value;
    }

    int getDieuHoa() const {
        return dieuhoa;
    }

    void setDieuHoa(int value) {
        dieuhoa = value;
    }

    int getGiuongHong() const {
        return giuonghong;
    }

    void setGiuongHong(int value) {
        giuonghong = value;
    }

    int getChieuHong() const {
        return chieuhong;
    }

    void setChieuHong(int value) {
        chieuhong = value;
    }

    int getNongLanhHong() const {
        return nonglanhhong;
    }

    void setNongLanhHong(int value) {
        nonglanhhong = value;
    }

    int getDieuHoaHong() const {
        return dieuhoahong;
    }

    void setDieuHoaHong(int value) {
        dieuhoahong = value;
    }

	//nhap xuat voi toan tu  
    friend ostream& operator<<(ostream& os, DichVu dv) {
	    os << "Giuong: " << dv.giuong << endl;
	    os << "Chieu: " << dv.chieu << endl
	       << "Nong lanh: " << dv.nonglanh << endl
	       << "Dieu hoa: " << dv.dieuhoa << endl
	       << "Giuong hong: " << dv.giuonghong << endl
	       << "Chieu hong: " << dv.chieuhong << endl
	       << "Nong lanh hong: " << dv.nonglanhhong << endl
	       << "Dieu hoa hong: " << dv.dieuhoahong << endl;
	    return os;
	}

	friend istream& operator>>(istream& is, DichVu& dv) {
	    cout << "Nhap so luong giuong: ";
	    is >> dv.giuong;
	    cout << "Nhap so luong chieu: ";
	    is >> dv.chieu;
	    cout << "Nhap so luong nong lanh: ";
	    is >> dv.nonglanh;
	    cout << "Nhap so luong dieu hoa: ";
	    is >> dv.dieuhoa;
	    cout << "Nhap so luong giuong hong: ";
	    is >> dv.giuonghong;
	    cout << "Nhap so luong chieu hong: ";
	    is >> dv.chieuhong;
	    cout << "Nhap so luong nong lanh hong: ";
	    is >> dv.nonglanhhong;
	    cout << "Nhap so luong dieu hoa hong: ";
	    is >> dv.dieuhoahong;
        is.ignore();
	    return is;
	}

};
#endif

