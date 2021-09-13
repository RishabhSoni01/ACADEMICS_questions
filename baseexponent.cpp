#include <iostream>
using namespace std;

int Power(int, int);

int main()
{
    int base, exponent, result;

    cout << "Enter base number: ";
    cin >> base;

    cout << "Enter power number(positive integer): ";
    cin >> exponent;

    result =Power(base, exponent);
    cout << base << "^" << exponent << " = " << result;

    return 0;
}

int Power(int base, int exponent)
{
    if (exponent != 0)
        return (base*Power(base, exponent-1));
    else
        return 1;
}