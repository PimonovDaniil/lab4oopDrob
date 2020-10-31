#pragma once
#include <vector>
using namespace std;

namespace mathTools
{

    class polynomial {
    private:
        vector<double> m_data;

        friend polynomial& operator+=(polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial operator+(polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial& operator-=(polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial operator-(polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial& operator*=(polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial operator*(polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial& operator/=(polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial operator/(polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial& operator%=(polynomial& polynomial1, const polynomial& polynomial2);
        friend polynomial operator%(polynomial& polynomial1, const polynomial& polynomial2);
    public:
        double& operator()(double x);

        void set(int size, double* m_data);

        polynomial();

        polynomial(int size, double* m_data);

        void delNull();

        void print();

    };

}
