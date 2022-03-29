/*
 * Copyright (c) 2022 Brandon Pacewic
 *
 * Developed and tested by Brandon Pacewic
 * 
 * static_mod_type.h
 */

#pragma once
#ifndef _BRANDON_STATIC_MOD_TYPE_H
#define _BRANDON_STATIC_MOD_TYPE_H

#include <cstdint>

namespace bp {

// TODO: Check overflow; default is int
typedef int ceil_num;

template<typename _Tp, const ceil_num Ceil>
class static_mod_type {
public:
	_Tp value;

	static_mod_type();
	static_mod_type(_Tp);

	explicit operator int() const;
	explicit operator int64_t() const;
	explicit operator float() const;
	explicit operator double() const;
	explicit operator long double() const;

	static_mod_type& operator+=(const static_mod_type&);
	static_mod_type& operator-=(const static_mod_type&);
	static_mod_type& operator*=(const static_mod_type&);
	static_mod_type& operator/=(const static_mod_type&);
	static_mod_type& operator%=(const static_mod_type&);

	static_mod_type operator+(const static_mod_type&) const;
	static_mod_type operator-(const static_mod_type&) const;
	static_mod_type operator*(const static_mod_type&) const;
	static_mod_type operator/(const static_mod_type&) const;
	static_mod_type operator%(const static_mod_type&) const;

	bool operator==(const static_mod_type&) const;
	bool operator!=(const static_mod_type&) const;
	bool operator<(const static_mod_type&) const;
	bool operator>(const static_mod_type&) const;
	bool operator<=(const static_mod_type&) const;
	bool operator>=(const static_mod_type&) const;
};

} // namespace bp

#endif