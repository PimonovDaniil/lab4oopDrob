﻿#define _USE_MATH_DEFINES
#include "fraction.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace mathTools
{
	fraction& operator+=(fraction& fraction1, const fraction& fraction2)
	{
        int n1 = fraction1.numerator * abs(fraction2.denominator);
        int n2 = fraction2.numerator * abs(fraction1.denominator);
        int d = fraction1.denominator * fraction2.denominator;
        fraction1.numerator = n1 + n2;
        fraction1.denominator = d;
        fraction1.sokrDrop();
        return fraction1;
	}

    fraction operator+(fraction& fraction1, const fraction& other)
    {
        fraction res(fraction1);
        res += other;
        return res;
    }

    fraction& operator-=(fraction& fraction1, const fraction& fraction2)
    {
        int n1 = fraction1.numerator * abs(fraction2.denominator);
        int n2 = fraction2.numerator * abs(fraction1.denominator);
        int d = fraction1.denominator * fraction2.denominator;
        fraction1.numerator = n1 - n2;
        fraction1.denominator = d;
        fraction1.sokrDrop();
        return fraction1;
    }

    fraction operator-(fraction& fraction1, const fraction& other)
    {
        fraction res(fraction1);
        res -= other;
        return res;
    }

    int fraction::gcd(int a, int b)
    {
        if (a == b) {
            return a;
        }
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        return gcd(a, b - a);
    }

    void fraction::sokrDrop()
    {
        int nod = this->gcd(abs(this->numerator), abs(this->denominator));
        if (nod != 0) {
            this->numerator /= nod;
            this->denominator /= nod;
        }
    }

    fraction::fraction()
    {
                this->numerator = 0;
                this->denominator = 0;
                this->sokrDrop();
    }

    fraction::fraction(int numerator, int denominator)
    {
        if (denominator == 0)throw "Знаменатель не может быть 0";
        this->numerator = numerator;
        this->denominator = denominator;
        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator = abs(this->denominator);
        }
        this->sokrDrop();
    }

    fraction& fraction::operator=(const fraction& other)
    {
        // Проверка на самоприсваивание
        if (this != &other) {
            this->numerator = other.numerator;
            this->denominator = other.denominator;
        }
        return *this;
    }

    void fraction::print()
    {
        printf("%d/%d\n", this->numerator, this->denominator);
    }
}
