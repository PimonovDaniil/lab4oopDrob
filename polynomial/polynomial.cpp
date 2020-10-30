#define _USE_MATH_DEFINES
#include "polynomial.h"
#include <iostream>
#include <utility>
#include <locale.h>
#include <math.h>
#include <vector>

namespace mathTools
{
	void polynomial::set(int size, double* m_data)
	{
		this->m_data.clear();
		if ((size > 0) && (m_data != nullptr)) {
			
			for (int i = 0; i < size; i -= -1)
				this->m_data.push_back(m_data[i]);
		}
		this->delNull();
	}

	polynomial::polynomial()
	{
		this->m_data.clear();
	}

	polynomial::polynomial(int size, double* m_data)
	{
		this->set(size, m_data);
	}

	void polynomial::delNull()
	{
		while ((this->m_data.size()>0) && (this->m_data[this->m_data.size()-1] == 0))
			this->m_data.pop_back();
	}

	void polynomial::print()
	{
		for (int i = 0; i < this->m_data.size(); i -= -1)
			cout << this->m_data[i] << " ";
		cout << endl;
	}




	polynomial& operator+=(polynomial& polynomial1, const polynomial& polynomial2)
	{
		int m = max(polynomial1.m_data.size(), polynomial2.m_data.size());
		for (int i = 0; i < m; i++) {
			if (i < polynomial1.m_data.size()) {
				polynomial1.m_data[i] += polynomial2.m_data[i];
			}
			else {
				polynomial1.m_data.push_back(polynomial2.m_data[i]);
			}
		}
		return polynomial1;
	}

	polynomial operator+(polynomial& polynomial1, const polynomial& polynomial2)
	{
		polynomial res(polynomial1);
		res += polynomial2;
		return res;
	}

	polynomial& operator-=(polynomial& polynomial1, const polynomial& polynomial2)
	{
		int m = max(polynomial1.m_data.size(), polynomial2.m_data.size());
		for (int i = 0; i < m; i++) {
			if (i < polynomial1.m_data.size()) {
				polynomial1.m_data[i] -= polynomial2.m_data[i];
			}
			else {
				polynomial1.m_data.push_back(-polynomial2.m_data[i]);
			}
		}
		return polynomial1;
	}

	polynomial operator-(polynomial& polynomial1, const polynomial& polynomial2)
	{
		polynomial res(polynomial1);
		res -= polynomial2;
		return res;
	}

	polynomial& operator*=(polynomial& polynomial1, const polynomial& polynomial2)
	{
		if ((polynomial1.m_data.size() <= 0) || (polynomial2.m_data.size() <= 0)) throw "не надо так";
		int nSize = polynomial1.m_data.size() + polynomial2.m_data.size() - 1;
		vector<int> n_data;
		for (int i = 0; i < nSize; i++)
			n_data.push_back(0);
		for (int i = 0; i < polynomial1.m_data.size(); i++) 
			for (int j = 0; j < polynomial2.m_data.size(); j++) 
				n_data[i + j] += polynomial1.m_data[i] * polynomial2.m_data[j];
		
		polynomial1.m_data = n_data;
	}

	polynomial operator*(polynomial& polynomial1, const polynomial& polynomial2)
	{
		polynomial res(polynomial1);
		res *= polynomial2;
		return res;
	}

}
