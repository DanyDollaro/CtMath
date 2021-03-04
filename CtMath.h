/***************************************************************************************************

  Math At Compile Time Library (CtMath)

***************************************************************************************************/

#pragma once
#include <cstdint>

/* ============================================================================================== */
/* Exported functions                                                                             */
/* ============================================================================================== */

/* ---------------------------------------------------------------------------------------------- */
/* Mathematical operations                                                                        */
/* ---------------------------------------------------------------------------------------------- */

// Absolute
template<int64_t _Index>
struct Abs {
    static constexpr int64_t value = (_Index >= 0) ? _Index : -_Index;
};

// Factorial
template<int64_t _Index>
struct Factorial {
    static constexpr int64_t value = _Index * Factorial<_Index - 1>::value;
};

template<>
struct Factorial<0> {
    static constexpr int64_t value = 1;
};

// Mod
template<int64_t _Dividend, int64_t _Divisor>
struct Mod {
    static constexpr int64_t value = _Dividend % _Divisor;
};

// Pow
template<int64_t _Index, int64_t _Power>
struct Pow {
    static constexpr int64_t value = _Index * Pow<_Index, _Power - 1>::value;
};

template<int64_t _Index>
struct Pow<_Index, 0> {
    static constexpr int64_t value = 1;
};

// Summation
template<int64_t _Index, int64_t... _Rest>
struct Summation {
    static constexpr int64_t value = _Index + Summation<_Rest...>::value;
};

template<int64_t _Index>
struct Summation<_Index> {
    static constexpr int64_t value = _Index;
};

/* ---------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------- */
/* Other templates                                                                                */
/* ---------------------------------------------------------------------------------------------- */

// Make odd
template<int64_t _Index>
struct Make_odd {
    static constexpr int64_t value = _Index & 0xFFFF'FFFF'FFFF'FFFE;
};

// Make even
template<int64_t _Index>
struct Make_even {
    static constexpr int64_t value = _Index | 0x01 ^ 0x01;
};

/* ---------------------------------------------------------------------------------------------- */

/* ============================================================================================== */