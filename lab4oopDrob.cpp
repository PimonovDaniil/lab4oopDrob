#include <iostream>
#include "fraction/fraction.h"
#include "polynomial/polynomial.h"

using namespace mathTools;
using namespace std;

int main()
{
    /*fraction a(4,10);
    fraction b(1, 4);
    a.print();
    b.print();
    fraction c;
    c = a / b;
    c.print();*/
    double* m = new double[4];
    m[0] = -2; m[1] = 16; m[2] = 0; m[3] = 15;
    polynomial a(4,m);
    a.print();

    double* m1 = new double[3];
    m1[0] = -2; m1[1] = 1; m1[2] = 2;
    polynomial b(3, m1);
    b.print();

    a /= b;
    a.print();
    
}