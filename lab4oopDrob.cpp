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
    double* m = new double[2];
    m[0] = 5; m[1] = 2;
    polynomial a(2,m);
    a.print();

    double* m1 = new double[3];
    m1[0] = 1; m1[1] = -2; m1[2] = 6;
    polynomial b(3, m1);
    b.print();

    a *= b;
    a.print();
    
}