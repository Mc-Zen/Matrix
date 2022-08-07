#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "../src/solvers.h"

#include <iostream>


using Catch::Approx;
using namespace algebra;


TEST_CASE("Determinant") {
	Matrix<float, 2, 2> mat2{ 1, 2, 3, 4 };
	REQUIRE(-2.f == det(mat2));

	mat2 = { 1, 2, 4, 5 };
	REQUIRE(-3.f == det(mat2));

	Matrix<float, 3, 3> mat3{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	REQUIRE(0.f == det(mat3));

	mat3 = { 4, 8, 5, 4, 3, 6, 5, 1, 1 };
	REQUIRE(141.f == det(mat3));

	mat3 = { -8, 4.1f, -98, 2, 8, 6.4f, 1, 7.2f, 4 };
	REQUIRE(-13028.f / 25.f == det(mat3));
}

TEST_CASE("Invert") {
	Matrix<double, 2, 2> mat2{ 1, 2, 3, 4 };
	for (double el : mat2* inv(mat2) - Matrix<double, 2, 2>::identity())
		REQUIRE(el == Approx(0.).margin(1e-15));

	mat2 = { -4.55, 3.44, -9.333, -234 };
	for (double el : mat2* inv(mat2) - Matrix<double, 2, 2>::identity())
		REQUIRE(el == Approx(0.).margin(1e-15));

	Matrix<double, 3, 3> mat3{ 1, 2, 3, 4, 5, 6, 7, 8, 10 };
	for (double el : mat3* inv(mat3) - Matrix<double, 3, 3>::identity())
		REQUIRE(el == Approx(0.).margin(1e-15));

	mat3 = { 1, 2, 3, 4, 55, 6, 7, 8, 10 };
	for (double el : mat3* inv(mat3) - Matrix<double, 3, 3>::identity())
		REQUIRE(el == Approx(0.).margin(1e-15));
}
