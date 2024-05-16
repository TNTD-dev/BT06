
#include "CPhanSo.h"


using namespace std;

CPhanSo::CPhanSo(int tu, int mau) : tu(tu), mau(mau) {}

istream& operator >> (istream& c, CPhanSo& a) {
    cout << "Nhap tu so: ";
    c >> a.tu;
    cout << "Nhap mau so: ";
    c >> a.mau;
    return c;
}
ostream& operator << (ostream& c, CPhanSo a) {
    int m = abs(a.tu);
    int n = abs(a.mau);
    while (m * n != 0) {
        if (m > n) m = m - n;
        else n = n - m;
    }
    int k = m + n;
    a.tu = a.tu / k;
    a.mau = a.mau / k;
    if (a.mau < 0) {
        a.tu = -a.tu;
        a.mau = -a.mau;
    }
    c << "Phan so la: " << a.tu << "/" << a.mau << endl;
    return c;
}


CPhanSo operator+(const CPhanSo& ps1, const CPhanSo& ps2) {
    return CPhanSo(ps1.tu * ps2.mau + ps2.tu * ps1.mau, ps1.mau * ps2.mau);
}

CPhanSo operator-(const CPhanSo& ps1, const CPhanSo& ps2) {
    return CPhanSo(ps1.tu * ps2.mau - ps2.tu * ps1.mau, ps1.mau * ps2.mau);
}

CPhanSo operator*(const CPhanSo& ps1, const CPhanSo& ps2) {
    return CPhanSo(ps1.tu * ps2.tu, ps1.mau * ps2.mau);
}

CPhanSo operator/(const CPhanSo& ps1, const CPhanSo& ps2) {
    if (ps2.tu == 0) {
        cout << "Division by zero";
        exit(-1);
    }
    return CPhanSo(ps1.tu * ps2.mau, ps1.mau * ps2.tu);
}

CPhanSo& CPhanSo::operator+=(const CPhanSo& ps) {
    tu = tu * ps.mau + mau * ps.tu;
    mau = mau * ps.mau;
    return *this;
}

CPhanSo& CPhanSo::operator*=(const CPhanSo& ps) {
    tu = tu * ps.tu;
    mau = mau * ps.mau;
    return *this;
}

CPhanSo& CPhanSo::operator/=(const CPhanSo& ps) {
    if (ps.tu == 0) {
        cout << "Division by zero";
        exit(-1);
    }
    tu = tu * ps.mau;
    mau = mau * ps.tu;
    return *this;
}

CPhanSo& CPhanSo::operator-=(const CPhanSo& ps) {
    tu = tu * ps.mau - mau * ps.tu;
    mau = mau * ps.mau;
    return *this;
}

CPhanSo& CPhanSo::operator++() {
    tu = tu + mau;
    return *this;
}

CPhanSo& CPhanSo::operator--() {
    tu = tu - mau;
    return *this;
}

CPhanSo& CPhanSo::operator++(int)
{
    CPhanSo temp = *this;
    tu = tu + mau;
    mau = mau;
    return  temp;
}

CPhanSo& CPhanSo::operator--(int)
{
    CPhanSo temp = *this;
    tu = tu - mau;
    mau = mau;
    return  temp;
}







