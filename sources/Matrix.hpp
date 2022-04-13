#pragma once
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
namespace zich {

    class Matrix {
    private:
        vector <vector<double>> mat;
        int row;
        int column;

    public:
        Matrix(const vector<double> &v, int r, int c) : row(r), column(c) {
            unsigned long col = (unsigned long)c;
            for (unsigned long i = 0; i < r; ++i) {
                vector<double> temp;
                for (unsigned long j = 0; j < c; ++j) {
                 temp.push_back(v.at( i * col + j));
                }
                mat.push_back(temp);
            }
        };

        ~Matrix() {};

        Matrix operator+(const Matrix &m) const;

        Matrix &operator+=(const Matrix &m);

        Matrix operator+() const;

        // for prefix(++x)
        Matrix &operator++();

        // for postfix(x++) + the inside int is only for definition of what we are doing in it - we will not use the int ,just for defintion that it's postfix
        Matrix operator++(int);

        Matrix operator-(const Matrix &m) const;

        Matrix &operator-=(const Matrix &m);

        Matrix operator-() const;

        // for prefix(++x)
        Matrix &operator--();

        // for postfix(x++) + the inside int is only for definition of what we are doing in it - we will not use the int ,just for defintion that it's postfix
        Matrix operator--(int);

        // without using this( a*M)
        friend Matrix operator*(const double scalar, const Matrix &m);

        // with using this(M*a)
        Matrix operator*(const double scalar) const;

        Matrix &operator*=(const double scalar);

        Matrix operator*(const Matrix &m) const;

        Matrix& operator*=(const Matrix &m);

        bool operator<(const Matrix &m) const;

        bool operator<=(const Matrix &m) const;

        bool operator>(const Matrix &m) const;

        bool operator>=(const Matrix &m) const;

        bool operator==(const Matrix &m) const;

        bool operator!=(const Matrix &m) const;

        friend ostream &operator<<(ostream &os, const Matrix &m);

        friend istream &operator>>(istream &is, Matrix &m);

    };
}




