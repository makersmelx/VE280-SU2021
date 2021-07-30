#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;
class complexNumber {
private:
    double real;
    double imag;

public:
    friend complexNumber operator+(const complexNumber& x, const complexNumber& y);
    friend ostream& operator<<(ostream& os, const complexNumber& x);
    complexNumber(double r = 0, double i = 0)
        : real(r)
        , imag(i)
    {
    }
    complexNumber operator-(const complexNumber& y)
    {
        return complexNumber(real - y.real, imag - y.imag);
    }
    complexNumber& operator+=(const complexNumber& y)
    {
        this->real += y.real;
        this->imag += y.imag;
        return *this;
    }
};
complexNumber operator+(const complexNumber& x, const complexNumber& y)
{
    return complexNumber(x.real + y.real, x.imag + y.imag);
}

ostream& operator<<(ostream& os, const complexNumber& x)
{
    os << x.real << "+" << x.imag << "i";
    return os;
}

int main()
{
    complexNumber x(1, 2);
    complexNumber y(2, 3);
    cout << x + y << endl;
    cout << x - y << endl;
    x += y;
    cout << x << endl;
    return 0;
}