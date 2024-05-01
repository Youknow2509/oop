#ifndef DICHVU_H
#define DICHVU_H

#include <iostream>

using namespace std;

class DichVu
{
private:
    int giuong;
    int chieu;
    int nonglanh;
    int dieuhoa;
    int slhong;

public:
    // Constructor
    DichVu() : giuong(1), chieu(1), nonglanh(1), dieuhoa(1), slhong(1) {}

    DichVu(int giuong = 1, int chieu = 1, int nonglanh = 1, int dieuhoa = 1, int slhong = 0)
        : giuong(giuong), chieu(chieu), nonglanh(nonglanh), dieuhoa(dieuhoa), slhong(slhong) {}
    void setGiuong(int value)
    {
        giuong = value;
    }
    // Getter and setter
    int getGiuong()
    {
        return giuong;
    }

    void setChieu(int value)
    {
        chieu = value;
    }

    int getChieu()
    {
        return chieu;
    }

    void setNongLanh(int value)
    {
        nonglanh = value;
    }

    int getNongLanh()
    {
        return nonglanh;
    }

    void setDieuHoa(int value)
    {
        dieuhoa = value;
    }

    int getDieuHoa()
    {
        return dieuhoa;
    }

    void setSoLuongHong(int value)
    {
        slhong = value;
    }

    int getSoLuongHong()
    {
        return slhong;
    }
    // Nhap xuat voi operator
    friend ostream &operator<<(ostream &os, const DichVu &dv)
    {
        os << "Giuong: " << dv.giuong << ", Chieu: " << dv.chieu << ", Nong lanh: " << dv.nonglanh
           << ", Dieu hoa: " << dv.dieuhoa << ", So luong hong: " << dv.slhong;
        return os;
    }


    friend std::istream &operator>>(std::istream &is, DichVu &dv)
    {
        std::cout << "Nhap so luong giuong: ";
        is >> dv.giuong;
        std::cout << "Nhap so luong chieu: ";
        is >> dv.chieu;
        std::cout << "Nhap so luong nong lanh: ";
        is >> dv.nonglanh;
        std::cout << "Nhap so luong dieu hoa: ";
        is >> dv.dieuhoa;
        std::cout << "Nhap so luong hong: ";
        is >> dv.slhong;
        return is;
    }
};

#endif 