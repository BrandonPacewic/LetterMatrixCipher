/*
 * 2022 - Simple mod_type class
 * Brandon Pacewic
*/

#pragma once
#ifndef _BRANDON_MOD_TYPE_C
#define _BRANDON_MOD_TYPE_C

#include <cstdint>
#include <iostream>
#include <istream>

#include "mod_type.h"
using bp::mod_type;

template<typename _Tp>
mod_type<_Tp>::mod_type(_Tp _value) : value{_value} {}

template<typename _Tp>
mod_type<_Tp>::mod_type() : value{0} {}

template<typename _Tp>
mod_type<_Tp>::operator int() const { return value; }

template<typename _Tp>
mod_type<_Tp>::operator int64_t() const { return value; }

template<typename _Tp>
mod_type<_Tp>::operator float() const { return value; }

template<typename _Tp>
mod_type<_Tp>::operator double() const { return value; }

template<typename _Tp>
mod_type<_Tp>::operator long double() const { return value; }

// Main feature of mod_type<> class, modular arithmetic in C++ works different
// than it otherwise should. In C and C++ the % operator creates a value between
// -b and b when in most other cases the expected return value should be between 
// 0 and b. This is a simple fix.

template<typename _Tp>
mod_type<_Tp>& mod_type<_Tp>::operator%=(const mod_type<_Tp>& other) {
    value %= other.value;
    if (value < 0) { value += other.value; }
    return *this;
}

template<typename _Tp>
mod_type<_Tp> mod_type<_Tp>::operator%(const mod_type<_Tp>& other) const {
    mod_type tmp = *this;
    tmp.value %= other.value;
    if (tmp.value < 0) { tmp.value += other.value;}
    return tmp;
}

// Other basic number type operators, nothing changes other than modular arithmetic
template<typename _Tp>
mod_type<_Tp>& mod_type<_Tp>::operator++() { ++value; return *this; }

template<typename _Tp>
mod_type<_Tp>& mod_type<_Tp>::operator--() { --value; return *this; }

template<typename _Tp>
mod_type<_Tp>& mod_type<_Tp>::operator+=(const mod_type<_Tp>& other) { 
    value += other.value; 
    return *this; 
}

template<typename _Tp>
mod_type<_Tp>& mod_type<_Tp>::operator-=(const mod_type<_Tp>& other) { 
    value -= other.value; 
    return *this; 
}

template<typename _Tp>
mod_type<_Tp>& mod_type<_Tp>::operator*=(const mod_type<_Tp>& other) { 
    value *= other.value; 
    return *this; 
}

template<typename _Tp>
mod_type<_Tp>& mod_type<_Tp>::operator/=(const mod_type<_Tp>& other){ 
    value /= other.vaule; 
    return *this; 
}

template<typename _Tp>
mod_type<_Tp> mod_type<_Tp>::operator+(const mod_type<_Tp>& other) const
{ return value + other.value; }

template<typename _Tp>
mod_type<_Tp> mod_type<_Tp>::operator-(const mod_type<_Tp>& other) const
{ return value + other.value; }

template<typename _Tp>
mod_type<_Tp> mod_type<_Tp>::operator*(const mod_type<_Tp>& other) const
{ return value * other.value; }

template<typename _Tp>
mod_type<_Tp> mod_type<_Tp>::operator/(const mod_type<_Tp>& other) const
{ return value / other.value; }

template<typename _Tp>
bool mod_type<_Tp>::operator==(const mod_type<_Tp>& other) const
{ return value == other.value; }

template<typename _Tp>
bool mod_type<_Tp>::operator!=(const mod_type<_Tp>& other) const
{ return value != other.value; }

template<typename _Tp>
bool mod_type<_Tp>::operator<(const mod_type<_Tp>& other) const
{ return value < other.value; }

template<typename _Tp>
bool mod_type<_Tp>::operator>(const mod_type<_Tp>& other) const
{ return value > other.value; }

template<typename _Tp>
bool mod_type<_Tp>::operator<=(const mod_type<_Tp>& other) const
{ return value <= other.value; }

template<typename _Tp>
bool mod_type<_Tp>::operator>=(const mod_type<_Tp>& other) const
{ return value >= other.value; }

template<typename _Tp>
std::ostream& operator<<(std::ostream& os, const mod_type<_Tp>& a)
{ return os << a.value; }

template<typename _Tp>
std::istream& operator>>(std::istream& is, mod_type<_Tp>& a)
{ return is >> a.value; }

#endif // _BRANDON_MOD_TYPE_C
