#include<iostream>
#include"CDonThuc.h"
using namespace std;

int main()
{
    CDonThuc a, b, res[4];
    cout << "Nhap don thuc a:\n";
    cin >> a;
    cout << "Nhap don thuc b:\n";
    cin >> b;


    res[0] = a * b;
    res[1] = a / b;
    res[2] = a *= b;
    a /= b;
    res[3] = a /= b;
    a *= b;



    cout << "Result: a * b\n" << res[0] << endl;
    cout << "Result: a / b\n" << res[1] << endl;
    cout << "Result: a *= b\n" << res[2] << endl;
    cout << "Result: a /= b\n" << res[3] << endl;

    return 0;
}