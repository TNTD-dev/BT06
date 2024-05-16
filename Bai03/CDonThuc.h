#pragma once
#include<iostream>
using namespace std;
class CDonThuc
{
    double heso, somu;
public:
    CDonThuc(double heso = 0.0, double somu = 0.0);
    friend istream& operator >> (istream&, CDonThuc&);
    friend ostream& operator << (ostream&, CDonThuc);
    friend CDonThuc operator*(const CDonThuc&, const CDonThuc&);
    friend CDonThuc operator/(const CDonThuc&, const CDonThuc&);
    CDonThuc& operator*=(const CDonThuc&);
    CDonThuc& operator/=(const CDonThuc&);

};

