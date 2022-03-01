#ifndef __COORDINATE_HPP__
#define __COORDINATE_HPP__

struct coordinate {
    int row;
    int col;

    coordinate(int row = 0, int col = 0): row{row}, col{col} {}
    coordinate(const coordinate&) = default;

    coordinate operator+(coordinate& other) {
        row += other.row;
        col += other.col;
        return *this;
    }

    coordinate operator-(coordinate& other) {
        row -= other.row;
        col -= other.col;
        return *this;
    }

    int operator*(coordinate& other) {
        return row*other.row + col*other.col;
    }

    bool operator==(coordinate& other) {
        return row == other.row && col == other.col;
    }
};

#endif