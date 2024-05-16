#pragma once
#include <iostream>
using namespace std;

class CPhanSo
{
private:
    int tu, mau;
public:
    CPhanSo(int tu = 0, int mau = 1);
    friend istream& operator >> (istream&, CPhanSo&);
    friend ostream& operator << (ostream&, CPhanSo);
    friend CPhanSo operator+(const CPhanSo&, const CPhanSo&);
    friend CPhanSo operator-(const CPhanSo&, const CPhanSo&);
    friend CPhanSo operator*(const CPhanSo&, const CPhanSo&);
    friend CPhanSo operator/(const CPhanSo&, const CPhanSo&);
    CPhanSo& operator+=(const CPhanSo&);
    CPhanSo& operator-=(const CPhanSo&);
    CPhanSo& operator*=(const CPhanSo&);
    CPhanSo& operator/=(const CPhanSo&);
    CPhanSo& operator++();
    CPhanSo& operator--();
    CPhanSo& operator++(int);
    CPhanSo& operator--(int);

};



