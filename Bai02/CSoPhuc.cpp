#include "CSoPhuc.h"
#include <iostream>
using namespace std;

CSoPhuc::CSoPhuc(double x, double y) : thuc(x), ao(y) {}

istream& operator >> (istream& c, CSoPhuc& a) {
    cout << "Nhap phan thuc: ";
    c >> a.thuc;
    cout << "Nhap phan ao: ";
    c >> a.ao;
    return c;

}

ostream& operator << (ostream& c, CSoPhuc a) {
    c << "So phuc la: " << a.thuc << (a.ao > 0 ? "+" : "") << a.ao << "i" << endl;
    return c;
}

CSoPhuc& operator+(const CSoPhuc& s1, const CSoPhuc& s2) {
    CSoPhuc res;
    res.thuc = s1.thuc + s2.thuc;
    res.ao = s1.ao + s2.ao;
    return res;
}

CSoPhuc& operator-(const CSoPhuc& s1, const CSoPhuc& s2) {
    CSoPhuc res;
    res.thuc = s1.thuc - s2.thuc;
    res.ao = s1.ao - s2.ao;
    return res;
}

CSoPhuc& operator*(const CSoPhuc& s1, const CSoPhuc& s2) {
    CSoPhuc res;
    res.thuc = s1.thuc * s2.thuc - s1.ao * s2.ao;
    res.ao = s1.thuc * s2.ao + s1.ao * s2.thuc;
    return res;
}

CSoPhuc& operator/(const CSoPhuc& s1, const CSoPhuc& s2) {
    CSoPhuc res;
    if (s1.ao == 0 && s2.ao == 0) {
        if (s2.thuc == 0) {
            cout << "Division by zero";
            exit(-1);
        }
        res.thuc = s1.thuc / s2.thuc;
        res.ao = 0;
    }
    else {
        double d = s1.ao * s1.ao + s2.ao * s2.ao;
        if (d == 0) {
            cout << "Division by zero";
            exit(-1);
        }
        res.thuc = (s1.thuc * s2.thuc + s1.ao * s2.ao);
        res.ao = (s1.ao * s2.thuc - s1.thuc * s2.ao);
    }
    return res;
}
CSoPhuc& CSoPhuc::operator+=(const CSoPhuc& other) {
    thuc = thuc + other.thuc;
    ao = ao + other.ao;
    return *this;
}

CSoPhuc& CSoPhuc::operator-=(const CSoPhuc& other) {
    thuc = thuc - other.thuc;
    ao = ao - other.ao;
    return *this;
}

CSoPhuc& CSoPhuc::operator*=(const CSoPhuc& other) {
    thuc = thuc * other.thuc - ao * other.ao;
    ao = thuc * other.ao + ao * other.thuc;
    return *this;
}

CSoPhuc& CSoPhuc::operator/=(const CSoPhuc& other) {
    if (this->ao == 0 && other.ao == 0) {
        if (other.thuc == 0) {
            cout << "Division by zero";
            exit(-1);
        }
        this->thuc /= other.thuc;
        this->ao = 0;
    }
    else {
        double d = other.ao * other.ao + other.thuc * other.thuc;
        if (d == 0) {
            cout << "Division by zero";
            exit(-1);
        }
        double temp = (this->thuc * other.thuc + this->ao * other.ao);
        this->ao = (this->ao * other.thuc - this->thuc * other.ao);
        this->thuc = temp;
    }
    return *this;
}

