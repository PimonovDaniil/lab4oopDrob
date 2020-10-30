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
    double* m = new double[5];
    for (int i = 0; i < 4; i++)
        m[i] = i;
    m[4] = 0;
    polynomial a(5,m);
    a.print();
    
}