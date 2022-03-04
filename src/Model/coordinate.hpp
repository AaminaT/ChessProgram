#ifndef __COORDINATE_HPP__
#define __COORDINATE_HPP__

struct coordinate {
    int row;
    int col;

    coordinate(int row = 0, int col = 0): row{row}, col{col} {}
    coordinate(const coordinate&) = default;

    coordinate operator+(const coordinate& other) {
        row += other.row;
        col += other.col;
        return *this;
    }

    coordinate operator-(const coordinate& other) {
        row -= other.row;
        col -= other.col;
        return *this;
    }

    int operator*(const coordinate& other) {
        return row*other.row + col*other.col;
    }

    coordinate operator*(int scalar) {
        row *= scalar;
        col *= scalar;
        return *this;
    }

    bool operator==(const coordinate& other) {
        return row == other.row && col == other.col;
    }
};

#endif
