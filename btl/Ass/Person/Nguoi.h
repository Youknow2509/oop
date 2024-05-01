#ifndef NGUOI_H
#define NGUOI_H

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Nguoi
{
private:
    int id;
    string name;
    string sdt;
    string email;

public:
    Nguoi()
    {
    }
    // Constructor
    Nguoi(int id, string name, string sdt, string email)
    {
        this->id = id;
        this->name = name;
        this->sdt = sdt;
        this->email = email;
    }

    // getter setter
    int getID()
    {
        return id;
    }

    void setID(int _id)
    {
        id = _id;
    }

    string getName()
    {
        return name;
    }

    void setName(string _name)
    {
        name = _name;
    }

    string getSDT()
    {
        return sdt;
    }

    void setSDT(string _sdt)
    {
        sdt = _sdt;
    }

    string getEmail()
    {
        return email;
    }

    void setEmail(string _email)
    {
        this->email = _email;
    }

    // input
    friend istream &operator>>(istream &is, Nguoi &ng)
    {
        cout << "Nhap ID: ";
        is >> ng.id;
        cout << "Nhap ten: ";
        is.ignore();
        getline(is, ng.name);
        cout << "Nhap SDT: ";
        is >> ng.sdt;
        cout << "Nhap Email: ";
        is >> ng.email;
        return is;
    }
    // output
    friend ostream &operator<<(ostream &os, Nguoi ng)
    {
        os << "ID: " << ng.id << " Name: " << ng.name << " SDT: " << ng.sdt << " Email: " << ng.email;
        return os;
    }
};

#endif
