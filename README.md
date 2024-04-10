# Matrix for C++

[![tests](https://github.com/Mc-Zen/Matrix/actions/workflows/ci.yml/badge.svg)](https://github.com/Mc-Zen/Matrix/actions/workflows/ci.yml)
[![license](https://img.shields.io/badge/license-MIT-blue)](https://github.com/Mc-Zen/Matrix/blob/main/LICENSE)


A tiny C++20 general-purpose library for dense, fixed-size and dynamically-sized matrices with no dependencies (other than `std`).
It makes use of C++20s concepts to enable special features such as norm for vectors and many more.

__View the full documentation at [https://mc-zen.github.io/Matrix/](https://mc-zen.github.io/Matrix/)__


## Overview

Features:

- intuitive syntax
- low-overhead
- header-only and single-header
- fully constexpr (except where math functions like `sqrt` are used). 
- STL-oriented
- Statically-sized have static memory (e.g. suited for audio development). 
- Dynamically-sized matrices are now available as well. 
- simple software design in comparison to some other matrix libs, e.g. no CRTP, virtual functions, ...
- fully tested. Tests can be run with [Catch2](https://github.com/catchorg/Catch2).

Limitations:

- only C++20 (and up) because of heavy use of concepts and constexpr
- this is not a linear algebra library - at the moment the library provides no linear algebra algorithms such as decomposition and solvers (exception: determinant and inverse of 2&times;2 and 3&times;3 matrices).

## Supported Platforms
Since this repository uses C++20 language features, a fairly new C++ compiler is necessary. 

|Platform | Compiler   | Minimum version |
|---------|------------|-----------------|
|Windows  | MSVC       | 14.30           |
|Linux    | GCC        | 13              |
|         | Clang      | 15              |
|MacOS    | AppleClang | 15              |


## Classes
| Class | Definition |
|-------|------------|
|`Matrix<T,m,n>`   | Main class for `m`×`n` matrices of type `T` |
|`Matrix_view<T>`   | Matrix view class for viewing or modifying parts of a matrix like a block, row or column. |
|`Matrix_iterator<T>`   | Random access iterator for iterating through a contiguous array in memory (matrix data). |
|`Matrix_stride_iterator<T>`   | Random access iterator for iterating i.e. vertically through a contiguous array in memory.   |
|`Matrix_block_iterator<T>`   | Bi-directional iterator for iterating through a matrix block within a bigger matrix. |


