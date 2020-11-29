#pragma once


#ifndef _MATRIX_HEADER_
#define _MATRIX_HEADER_

#include "Complex.hpp"

class MatrixComplex
{
public:
	Complex data[4][4];

	MatrixComplex() : data() {}

	Complex& operator()(int row, int col)
	{
		return data[row][col];
	}

};

#endif // !_MATRIX_HEADER_
