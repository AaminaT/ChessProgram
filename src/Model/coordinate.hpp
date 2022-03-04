#ifndef __COORDINATE_HPP__
#define __COORDINATE_HPP__

#include <cmath>
#include <iostream>

struct coordinate {
    int row;
    int col;

    coordinate(int row = -1, int col = -1): row{row}, col{col} {}
    coordinate(const coordinate&) = default;

    coordinate operator+(const coordinate& other) const {
        return coordinate(row + other.row, col + other.col);
    }

    coordinate operator-(const coordinate& other) const {
        return coordinate(row - other.row, col - other.col);
    }

    int operator*(const coordinate& other) const {
        return row*other.row + col*other.col;
    }

    coordinate operator*(int scalar) const {
        return coordinate(row*scalar, col*scalar);
    }

    bool operator==(const coordinate& other) const {
        return row == other.row && col == other.col;
    }

    bool operator!=(const coordinate& other) const {
        return !(*this == other);
    }

    friend coordinate rotate(const coordinate&, double);
    friend bool are_dependent(const coordinate&, const coordinate&);
};

coordinate rotate(const coordinate& v, double a) {
    a *= 3.14159265358979324/180.0;
    int adj = nearbyint(cos(a));
    int opp = nearbyint(sin(a));
    return coordinate(v.row*adj - v.col*opp, v.row*opp + v.col*adj);
}

bool are_equivalent(const coordinate& v, const coordinate& w) {
    return v * rotate(w, 90) == 0 && v * w > 0;
}

#endif
