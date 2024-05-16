#include<iostream>
#include"CPhanSo.h"
using namespace std;

int main()
{
    CPhanSo a, b, res[12];
    cout << "Nhap phan so a:\n";
    cin >> a;
    cout << "Nhap phan so b:\n";
    cin >> b;

    res[0] = a + b;
    res[1] = a - b;
    res[2] = a * b;
    res[3] = a / b;
    res[4] = a += b;
    a -= b;
    res[5] = a -= b;
    a += b;
    res[6] = a *= b;
    a /= b;
    res[7] = a /= b;
    a *= b;
    res[8] = ++a;
    a--;
    res[9] = a++;
    res[10] = --b;
    b++;
    res[11] = b--;
    b++;

    cout << "\nResult: a + b\n" << res[0] << endl;
    cout << "Result: a - b\n" << res[1] << endl;
    cout << "Result: a * b\n" << res[2] << endl;
    cout << "Result: a / b\n" << res[3] << endl;

    cout << "Result: a += b\n" << res[4] << endl;
    cout << "Result: a -= b\n" << res[5] << endl;
    cout << "Result: a *= b\n" << res[6] << endl;
    cout << "Result: a /= b\n" << res[7] << endl;

    cout << "Result: ++a\n" << res[8] << endl;
    cout << "Result: a++\n" << res[9] << endl;
    cout << "Result: --b\n" << res[10] << endl;
    cout << "Result: b--\n" << res[11] << endl;


    return 0;
}