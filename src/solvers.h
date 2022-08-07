#pragma once

// Compute determinant and inverse of 2x2 as well as 3x3 matrices.

#include "matrix.h"


namespace algebra {

template<class T, Index n>
T det(const Matrix<T, n, n>& a);

template<class T, Index n>
Matrix<T, n, n> inv(const Matrix<T, n, n>& a);

template<class T>
T det(const Matrix<T, 2, 2>& a) {
	const auto data = a.data();
	return data[0] * data[3] - data[1] * data[2];
}

template<class T>
T det(const Matrix<T, 3, 3>& a) {
	const auto data = a.data();
	return data[0] * (data[4] * data[8] - data[7] * data[5]) + data[1] * (data[5] * data[6] - data[3] * data[8]) + data[2] * (data[3] * data[7] - data[6] * data[4]);
}
template<class T>
Matrix<T, 2, 2> inv(const Matrix<T, 2, 2>& a) {
	const auto data = a.data();
	Matrix<T, 2, 2> result{ data[3], -data[1], -data[2], data[0] };
	return result /= det(a);
}


template<class T>
Matrix<T, 3, 3> inv(const Matrix<T, 3, 3>& a) {
	const auto data = a.data();
	T eihf = data[4] * data[8] - data[7] * data[5];
	T fgdi = data[5] * data[6] - data[3] * data[8];
	T dhge = data[3] * data[7] - data[6] * data[4];
	T det = data[0] * eihf + data[1] * fgdi + data[2] * dhge;
	Matrix<T, 3, 3> result{
		eihf, data[2] * data[7] - data[1] * data[8], data[1] * data[5] - data[2] * data[4],
		fgdi, data[0] * data[8] - data[2] * data[6], data[3] * data[2] - data[0] * data[5],
		dhge, data[6] * data[1] - data[0] * data[7], data[0] * data[4] - data[3] * data[1]
	};
	return result *= T(1.0) / det;
}

}