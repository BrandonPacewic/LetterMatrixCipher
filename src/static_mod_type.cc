/*
 * Copyright (c) 2022 Brandon Pacewic
 *
 * Developed and tested by Brandon Pacewic
 * 
 * static_mod_type.cc
 */

#ifndef _BRANDON_STATIC_MOD_TYPE_C
#define _BRANDON_STATIC_MOD_TYPE_C

#include <cstdint>
#include <iostream>
#include <istream>

#include "static_mod_type.h"
using bp::static_mod_type;
using bp::ceil_num;

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil>::static_mod_type() : value{0} {}

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil>::static_mod_type(_Tp _value) : value{_value} {}

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil>::operator int() const { return value; }

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil>::operator int64_t() const { return value; }

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil>::operator float() const { return value; }

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil>::operator double() const { return value; }

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil>::operator long double() const { return value; }

// Side feature of static_mod_type<> class, modular arithmetic in C++ works
// different than it otherwise should. In C and C++ the % operator creates a
// value between -b and b when in most other cases the expected return value
// should be between 0 and b. This is a simple fix. This, not the main feature
// of this class, is found in both the static_mod_type<> class as well as the
// mod_type<> class. This change also can be found for the operator%

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil>& static_mod_type<_Tp, Ceil>::operator%=(
        const static_mod_type<_Tp, Ceil>& other) {
    value %= other.value;
    if (value < 0) { value += other.value; }
    return *this;
}

template<typename _Tp, const ceil_num Ceil> 
static_mod_type<_Tp, Ceil>& static_mod_type<_Tp, Ceil>::operator+=(
        const static_mod_type<_Tp, Ceil>& other) {
    value += other.value;
    return *this %= Ceil;
}

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil>& static_mod_type<_Tp, Ceil>::operator-=(
        const static_mod_type<_Tp, Ceil>& other) {
    value -= other.value;
    return *this %= Ceil;
}

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil>& static_mod_type<_Tp, Ceil>::operator*=(
        const static_mod_type<_Tp, Ceil>& other) {
    value *= other.value;
    return *this %= Ceil;
}

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil>&static_mod_type<_Tp, Ceil>::operator/=(
        const static_mod_type<_Tp, Ceil>& other) 
{ return value /= other.value; }

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil> static_mod_type<_Tp, Ceil>::operator+(
        const static_mod_type<_Tp, Ceil>& other) const { 
    auto tmp = *this;
    return tmp += other;
}

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil> static_mod_type<_Tp, Ceil>::operator-(
        const static_mod_type<_Tp, Ceil>& other) const {
    auto tmp = *this;
    return tmp -= other;
}

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil> static_mod_type<_Tp, Ceil>::operator*(
        const static_mod_type<_Tp, Ceil>& other) const {
    auto tmp = *this;
    return tmp *= other;
}

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil> static_mod_type<_Tp, Ceil>::operator/(
        const static_mod_type<_Tp, Ceil>& other) const {
    auto tmp = *this;
    return tmp /= other;
}

template<typename _Tp, const ceil_num Ceil>
static_mod_type<_Tp, Ceil> static_mod_type<_Tp, Ceil>::operator%(
        const static_mod_type<_Tp, Ceil>& other) const {
    auto tmp = *this;
    return tmp %= other;
}

template<typename _Tp, const ceil_num Ceil>
bool static_mod_type<_Tp, Ceil>::operator==(
    const static_mod_type<_Tp, Ceil>& other) const
{ return value == other.value; }

template<typename _Tp, const ceil_num Ceil>
bool static_mod_type<_Tp, Ceil>::operator!=(
    const static_mod_type<_Tp, Ceil>& other) const
{ return value != other.value; }

template<typename _Tp, const ceil_num Ceil>
bool static_mod_type<_Tp, Ceil>::operator<(
const static_mod_type<_Tp, Ceil>& other) const
{ return value < other.value; }

template<typename _Tp, const ceil_num Ceil>
bool static_mod_type<_Tp, Ceil>::operator>(
    const static_mod_type<_Tp, Ceil>& other) const
{ return value > other.value; }

template<typename _Tp, const ceil_num Ceil>
bool static_mod_type<_Tp, Ceil>::operator<=(
    const static_mod_type<_Tp, Ceil>& other) const
{ return value <= other.value; }

template<typename _Tp, const ceil_num Ceil>
bool static_mod_type<_Tp, Ceil>::operator>=(
    const static_mod_type<_Tp, Ceil>& other) const
{ return value >= other.value; }

template<typename _Tp, const ceil_num Ceil>
std::ostream& operator<<(std::ostream& os, const static_mod_type<_Tp, Ceil>& a)
{ return os << a.value; }

template<typename _Tp, const ceil_num Ceil>
std::istream& operator>>(std::istream& is, static_mod_type<_Tp, Ceil>& a)
{ return is >> a.value; }

#endif // _BRANDON_STATIC_MOD_TYPE_C