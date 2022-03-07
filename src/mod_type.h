// TODO: Need to add header comment

#pragma once
#ifndef _BRANDON_MOD_TYPE_H
#define _BRANDON_MOD_TYPE_H

#include <cstdint>

namespace bp {

template<typename _Tp>
class mod_type {
public:
	_Tp value;

	mod_type(_Tp _value);
	mod_type();

	explicit operator int() const;
	explicit operator int64_t() const;
	explicit operator float() const;
	explicit operator double() const;
	explicit operator long double() const;

	mod_type& operator%=(const mod_type&);
	mod_type operator%(const mod_type&) const;

	mod_type& operator++();
	mod_type& operator--();

	mod_type& operator+=(const mod_type&);
	mod_type& operator-=(const mod_type&);
	mod_type& operator*=(const mod_type&);
	mod_type& operator/=(const mod_type&);
	mod_type operator+(const mod_type&) const;
	mod_type operator-(const mod_type&) const;
	mod_type operator*(const mod_type&) const;
	mod_type operator/(const mod_type&) const;

	bool operator==(const mod_type&) const;
	bool operator!=(const mod_type&) const;
	bool operator<(const mod_type&) const;
	bool operator>(const mod_type&) const;
	bool operator<=(const mod_type&) const;
	bool operator>=(const mod_type&) const;
};

} // namespace bp

#endif // _BRANDON_MOD_TYPE_H
