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




}
