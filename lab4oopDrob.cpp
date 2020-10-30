#include <iostream>
#include "fraction/fraction.h"

using namespace mathTools;

int main()
{
    fraction a(4,10);
    fraction b(1, 4);
    a.print();
    b.print();
    fraction c;
    c = a / b;
    c.print();
    
}