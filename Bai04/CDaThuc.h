#pragma once
#include <vector>
#include<iostream>
using namespace std;

class CDaThuc
{
    vector<double> v;
    int bac;
public:
    CDaThuc(vector<double> v = vector<double>(), int bac = 0);
    friend istream& operator >> (istream&, CDaThuc&);
    friend ostream& operator << (ostream&, CDaThuc);
    friend CDaThuc operator+(const CDaThuc&, const CDaThuc&);
    friend CDaThuc operator-(const CDaThuc&, const CDaThuc&);
    friend CDaThuc operator*(const CDaThuc&, const CDaThuc&);
    friend CDaThuc operator/(const CDaThuc&, const CDaThuc&);
    CDaThuc& operator+=(const CDaThuc&);
    CDaThuc& operator-=(const CDaThuc&);
    CDaThuc& operator*=(const CDaThuc&);
    CDaThuc& operator/=(const CDaThuc&);

};

