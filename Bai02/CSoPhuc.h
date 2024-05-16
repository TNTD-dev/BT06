#pragma once
#include <iostream>
using namespace std;

class CSoPhuc
{
private:
    double thuc, ao;
public:
    CSoPhuc(double thuc = 0, double ao = 0);
    friend istream& operator >> (istream&, CSoPhuc&);
    friend ostream& operator << (ostream&, CSoPhuc);
    friend CSoPhuc& operator+(const CSoPhuc&, const CSoPhuc&);
    friend CSoPhuc& operator-(const CSoPhuc&, const CSoPhuc&);
    friend CSoPhuc& operator*(const CSoPhuc&, const CSoPhuc&);
    friend CSoPhuc& operator/(const CSoPhuc&, const CSoPhuc&);
    CSoPhuc& operator+=(const CSoPhuc&);
    CSoPhuc& operator-=(const CSoPhuc&);
    CSoPhuc& operator*=(const CSoPhuc&);
    CSoPhuc& operator/=(const CSoPhuc&);
};

