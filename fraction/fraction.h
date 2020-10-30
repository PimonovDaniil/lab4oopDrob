#pragma once

namespace mathTools
{

    class fraction {
    private:
        int numerator;
        int denominator;

        friend fraction& operator+=(fraction& fraction1, const fraction& fraction2);
        friend fraction operator+(fraction& fraction1, const fraction& other);
        friend fraction& operator-=(fraction& fraction1, const fraction& fraction2);
        friend fraction operator-(fraction& fraction1, const fraction& other);

        int gcd(int a, int b);

        void sokrDrop();

    public:
        fraction();

        fraction(int numerator, int denominator);

        fraction& operator=(const fraction& other);

        void print();
    };

}
