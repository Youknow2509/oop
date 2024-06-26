#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <bits/stdc++.h>
#include "Nguoi.h"
using namespace std;
typedef long long ll;
// class sinh vien
class SinhVien : public Nguoi
{
private:
	int sophong;
	bool ttdongtien; 

public:
	// constructor
	SinhVien()
	{
	}
	SinhVien(int id, string name, string sdt, string email, int sophong) : Nguoi(id, name, sdt, email)
	{
		this->sophong = sophong;
	}
	// getter setter
	int getSoPhong()
	{
		return sophong;
	}
	void setSoPhong(int so)
	{
		this->sophong = so;
	}
	
	bool isTtDongTien(){
		return this -> ttdongtien;
	}
	
	void setTtDongTien(bool tt){
		this -> ttdongtien = tt;
	}

	// bool kiem tra tien nop
	bool checkTienNop()
	{
		return true;
	}
	// input
	friend istream &operator>>(istream &is, SinhVien &sv)
	{
		is >> static_cast<Nguoi &>(sv); // Input Nguoi part
		return is;
	}
	// output
	friend ostream &operator<<(ostream &os, SinhVien sv)
	{
		os << static_cast<const Nguoi &>(sv) << " So Phong: " << sv.sophong << endl;
		return os;
	}
};

#endif
