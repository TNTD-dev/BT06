#include "CDaThuc.h"
#include <iostream>
#include <vector>

using namespace std;

CDaThuc::CDaThuc(vector<double> v, int bac) : v(v), bac(bac) {}

istream& operator >> (istream& c, CDaThuc& a) {
    cout << "Bac cua da thuc: "; c >> a.bac;
    a.v = vector<double>(a.bac + 1, 0);
    for (int i = 0; i <= a.bac; i++) {
        cout << "He so don thuc bac " << i << ": ";
        int tmp; cin >> tmp;
        a.v[i] = tmp;
    }
    cout << endl;
    return c;
}
ostream& operator << (ostream& c, CDaThuc a) {
    for (int i = a.bac; i >= 0; i--) {
        if (a.v[i] != 0) {
            c << (a.v[i] > 0 && i != a.bac ? "+" : "") << a.v[i] << "x^" << i;
        }
    }
    c << endl;
    return c;
}


CDaThuc operator+(const CDaThuc& dt1, const CDaThuc& dt2) {
    CDaThuc res;
    res.bac = max(dt1.bac, dt2.bac);
    res.v = vector<double>(res.bac + 1, 0);
    for (int i = 0; i <= res.bac; i++) {
        if (i <= dt1.bac) res.v[i] += dt1.v[i];
        if (i <= dt2.bac) res.v[i] += dt2.v[i];
    }
    return res;
}

CDaThuc operator-(const CDaThuc& dt1, const CDaThuc& dt2) {
    CDaThuc res;
    res.bac = max(dt1.bac, dt2.bac);
    res.v = vector<double>(res.bac + 1, 0);
    for (int i = 0; i <= res.bac; i++) {
        if (i <= dt1.bac) res.v[i] += dt1.v[i];
        if (i <= dt2.bac) res.v[i] -= dt2.v[i];
    }
    return res;
}

CDaThuc operator*(const CDaThuc& dt1, const CDaThuc& dt2) {
    CDaThuc res;
    res.bac = dt1.bac + dt2.bac;
    res.v = vector<double>(res.bac + 1, 0);
    for (int i = 0; i <= dt1.bac; i++) {
        for (int j = 0; j <= dt2.bac; j++) {
            res.v[i + j] += dt1.v[i] * dt2.v[j];
        }
    }
    return res;
}

CDaThuc operator/(const CDaThuc& dt1, const CDaThuc& dt2) {
    if (dt2.bac > dt1.bac) {
        cout << endl << "Khong the chia. " << endl;
        exit(-1);
    }
    CDaThuc res, tmp = dt1;
    res.bac = dt1.bac - dt2.bac;
    res.v = vector<double>(res.bac + 1, 0);
    while (tmp.bac >= dt2.bac) {
        double heso = tmp.v[tmp.bac] / dt2.v[dt2.bac];
        int somu = tmp.bac - dt2.bac;
        for (int i = 0; i <= dt2.bac; i++) {
            tmp.v[i + somu] -= dt2.v[i] * heso;
        }
        while (tmp.bac >= 0 && tmp.v[tmp.bac] == 0) {
            tmp.bac--;
        }
        res.v[somu] = heso;
    }
    return res;
}

CDaThuc& CDaThuc::operator+=(const CDaThuc& dt) {
    *this = *this + dt;
    return *this;
}

CDaThuc& CDaThuc::operator-=(const CDaThuc& dt) {
    *this = *this - dt;
    return *this;
}

CDaThuc& CDaThuc::operator*=(const CDaThuc& dt) {
    *this = *this * dt;
    return *this;
}

CDaThuc& CDaThuc::operator/=(const CDaThuc& dt) {
    *this = *this / dt;
    return *this;
}

