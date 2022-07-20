# Matrix for C++


A tiny C++20 general-purpose library for dense, fixed-size matrices (and vectors) with no dependencies.
It makes use of C++20s concepts to enable special features such as norm for vectors and many more.

__View the full documentation at [https://mc-zen.github.io/Matrix/](https://mc-zen.github.io/Matrix/)__


## Overview

Features:

- intuitive syntax
- almost no overhead
- header-only
- fully constexpr
- STL-oriented
- static memory (e.g. suited for audio development)
- simple software design in compaison to some other matrix libs, e.g. no CRTP, virtual functions, ...
- fully tested. Tests can be run with Catch2.

Limitations:

- only C++20 (and up) because of heavy use of concepts and constexpr
- this is not a linear algebra library - at the moment the library provides no linear algebra algorithms such as decomposition and solvers (exception: determinant and inverse of 2&times;2 and 3&times;3 matrices).


## Classes
| Class | Definition |
|-------|------------|
|`Matrix<T,m,n>`   | Main class for `m`×`n` matrices of type `T` |
|`Matrix_view<T>`   | Matrix view class for viewing or modifying parts of a matrix like a block, row or column. |
|`Matrix_iterator<T>`   | Random access iterator for iterating through a contiguous array in memory (matrix data). |
|`Matrix_stride_iterator<T>`   | Random access iterator for iterating i.e. vertically through a contiguous array in memory.   |
|`Matrix_block_iterator<T>`   | Bi-directional iterator for iterating through a matrix block within a bigger matrix. |


