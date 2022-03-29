/*
 * Copyright (c) 2022 Brandon Pacewic
 *
 * Developed and tested by Brandon Pacewic
 * 
 * uniform_matrix.h
 */

#pragma once
#ifndef _BRANDON_UNIFORM_MATRIX_H
#define _BRANDON_UNIFORM_MATRIX_H

#include <cstddef>

namespace bp {

template<typename _Tp, const std::size_t _Sz>
class _uniform_matrix_row {
public:
    _uniform_matrix_row();
    ~_uniform_matrix_row();

    const std::size_t size() const;

    _Tp& operator[](const int&) const;
    
    int assign_back(const _Tp&);

private:
    _Tp* elements;
    int current_cell_index;
};

template<typename _Tp, const std::size_t _Sz>
class uniform_matrix {
public:
    uniform_matrix();
    ~uniform_matrix();

    const std::size_t size() const;

    _uniform_matrix_row<_Tp, _Sz>& operator[](const int&) const;

    void assign_back(const _Tp&);

private:
    _uniform_matrix_row<_Tp, _Sz>* inner_rows;
    int current_row_index;
    int fully_assigned_cells;
};

} // namespace bp

#endif // _BRANDON_UNIFORM_MATRIX_H