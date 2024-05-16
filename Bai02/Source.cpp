#include<iostream>
#include"CSoPhuc.h"
using namespace std;

int main()
{
    CSoPhuc a, b, res[8];
    cout << "Nhap so phuc a:\n";
    cin >> a;
    cout << "Nhap so phuc b:\n";
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


    cout << "\nResult: a + b\n" << res[0] << endl;
    cout << "Result: a - b\n" << res[1] << endl;
    cout << "Result: a * b\n" << res[2] << endl;
    cout << "Result: a / b\n" << res[3] << endl;

    cout << "Result: a += b\n" << res[4] << endl;
    cout << "Result: a -= b\n" << res[5] << endl;
    cout << "Result: a *= b\n" << res[6] << endl;
    cout << "Result: a /= b\n" << res[7] << endl;

    return 0;
}