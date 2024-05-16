#include "CDonThuc.h"
#include <iostream>
using namespace std;

CDonThuc::CDonThuc(double heso, double somu) : heso(heso), somu(somu) {}

istream& operator >> (istream& c, CDonThuc& a) {
    cout << "Nhap he so: ";
    c >> a.heso;
    cout << "Nhap so mu: ";
    c >> a.somu;
    return c;
}
ostream& operator << (ostream& c, CDonThuc a) {
    c << "Don thuc la: ";
    if (a.somu == 0) cout << a.heso << endl;
    else if (a.somu == 1) cout << a.heso << "x" << endl;
    else cout << a.heso << "x^" << a.somu << endl;
    return c;
}

CDonThuc operator/(const CDonThuc& dt1, const CDonThuc& dt2) {
    if (dt2.heso == 0) {
        cout << "Division by zero";
        exit(-1);
    }
    return CDonThuc(dt1.heso / dt2.heso, dt1.somu - dt2.somu);
}
CDonThuc operator*(const CDonThuc& dt1, const CDonThuc& dt2) {
    return CDonThuc(dt1.heso * dt2.heso, dt1.somu + dt2.somu);
}
CDonThuc& CDonThuc::operator*=(const CDonThuc& other) {
    this->heso *= other.heso;
    this->somu += other.somu;
    return *this;
}

CDonThuc& CDonThuc::operator/=(const CDonThuc& other) {
    if (other.heso == 0) {
        cout << "Division by zero";
        exit(-1);
    }
    this->heso /= other.heso;
    this->somu -= other.somu;
    return *this;
}

