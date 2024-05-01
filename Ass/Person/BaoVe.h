#ifndef BAOVE_H
#define BAOVE_H

#include <bits/stdc++.h>
#include "Nguoi.h"
using namespace std;
typedef long long ll;
// class Bao ve
class BaoVe : public Nguoi
{
private:
	string chucvu;
	int tang;
	int id_toanha;

public:
	// Constructor
	BaoVe() {}

	BaoVe(int id, string name, string sdt, string email, string chucvu, int id_toanha, int tang) : Nguoi(id, name, sdt, email)
	{
		this->chucvu = chucvu;
		this->tang = tang;
		this->id_toanha = id_toanha;
	}

	// getter va setter
	string getChucVu()
	{
		return chucvu;
	}
	int getTang()
	{
		return tang;
	}
	int getID_toanha()
	{
		return this->id_toanha;
	}
	void setChucVu(string cv)
	{
		this->chucvu = cv;
	}
	void setTang(int tang)
	{
		this->tang = tang;
	}
	void setID_Toanha(int id)
	{
		this->id_toanha = id;
	}
	// input
	friend istream &operator>>(istream &is, BaoVe &bv)
	{
		is >> static_cast<Nguoi &>(bv); // Input Nguoi part
		is.ignore();
		cout << "Nhap chuc vu: ";
		getline(is, bv.chucvu);
		cout << "Nhap ID toa nha: ";
		is >> bv.id_toanha;
		cout << "Nhap tang: ";
		is >> bv.tang;

		return is;
	}
	// output
	friend ostream &operator<<(ostream &os, const BaoVe &bv)
	{
		os << static_cast<const Nguoi &>(bv) << " Chuc Vu: " << bv.chucvu << " ID Toa nha: " << bv.id_toanha << " Tang: " << bv.tang << endl;
		return os;
	}
};

#endif