#pragma once
#include <vector>
using namespace std;

namespace mathTools
{

    class polynomial {
    private:
        vector<int> m_data;
    public:

        void set(int size, double* m_data);

        polynomial();

        polynomial(int size, double* m_data);

        void delNull();

        void print();

    };

}
