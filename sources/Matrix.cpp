#include "Matrix.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
using namespace zich;
namespace zich
{
    Matrix Matrix::operator+(const Matrix &m) const
    {
        if ((this->row != m.row) || (this->column != m.column))
        {
            throw invalid_argument("Matrix must bw in the same sizes");
        }
        vector<double> v;
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.column; j++)
            {
                v.push_back(this->mat.at(i).at(j) + m.mat.at(i).at(j));
            }
        }
        Matrix sum(v, this->row, this->column);

        return sum;
    }

    Matrix &Matrix::operator+=(const Matrix &m)
    {
        if ((this->row) != m.row || (this->column) != m.column)
        {
            throw invalid_argument("Matrix must bw in the same sizes");
        }
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.column; j++)
            {
                this->mat.at(i).at(j) += m.mat.at(i).at(j);
            }
        }
        return *this;
    }

    Matrix Matrix::operator+() const
    {
        vector<double> temp;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                temp.push_back(this->mat.at(i).at(j));
            }
        }
        Matrix out(temp, this->row, this->column);
        return out;
    }

    // for prefix(++x)
    Matrix &Matrix::operator++()
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                this->mat.at(i).at(j) += 1;
            }
        }
        return *this;
    }

    // for postfix(x++) + the inside int is only for definition of what we are doing in it - we will not use the int ,just for defintion that it's postfix
    Matrix Matrix::operator++(int)
    {
        // as same as lines code in +unari
        Matrix out = +(*this);
        ++(*this);

        return out;
    }

    Matrix Matrix::operator-(const Matrix &m) const
    {
        if ((this->row != m.row) || (this->column != m.column))
        {
            throw invalid_argument("Matrix must bw in the same sizes");
        }
        vector<double> v;
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.column; j++)
            {
                v.push_back(this->mat.at(i).at(j) - m.mat.at(i).at(j));
            }
        }
        Matrix sum(v, this->row, this->column);

        return sum;
    }

    Matrix &Matrix::operator-=(const Matrix &m)
    {
        if ((this->row) != m.row || (this->column) != m.column)
        {
            throw invalid_argument("Matrix must bw in the same sizes");
        }
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.column; j++)
            {
                this->mat.at(i).at(j) -= m.mat.at(i).at(j);
            }
        }
        return *this;
    }

    Matrix Matrix::operator-() const
    {
        vector<double> temp;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                // as same as +unari just adding the opsite(-)
                temp.push_back(-(this->mat.at(i).at(j)));
            }
        }
        Matrix out(temp, this->row, this->column);
        return out;
    }

    // for prefix(--x)
    Matrix &Matrix::operator--()
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                this->mat.at(i).at(j) -= 1;
            }
        }
        return *this;
    }

    // for postfix(x--) + the inside int is only for definition of what we are doing in it - we will not use the int ,just for defintion that it's postfix
    Matrix Matrix::operator--(int)
    {
        vector<double> temp;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                temp.push_back(this->mat.at(i).at(j));
            }
        }
        Matrix out(temp, this->row, this->column);
        --(*this);

        return out;
    }

    // without using this( a*M)
    Matrix operator*(const double scalar, const Matrix &m)
    {
        vector<double> v;
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.column; j++)
            {
                v.push_back(scalar * m.mat.at(i).at(j));
            }
        }
        Matrix out(v, m.row, m.column);

        return out;
    }
    // with using this(M*a)
    Matrix Matrix::operator*(const double scalar) const
    {
        Matrix out = scalar * (*this);
        return out;
    }

    Matrix &Matrix::operator*=(const double scalar)
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                this->mat.at(i).at(j) *= scalar;
            }
        }
        return *this;
    }

    Matrix Matrix::operator*(const Matrix &m) const
    {
        if (this->column != m.row)
        {
            throw invalid_argument("cannt multply those matrix");
        }
        vector<double> v;
        for (int i = 0; i < this->row; i++)
        {
            for (int l = 0; l < m.column; l++)
            {
                int ans = 0;
                for (int j = 0, k = 0; j < this->column; j++, k++)
                {
                    ans += (this->mat.at(i).at(j) * m.mat.at(k).at(l));
                }
                v.push_back(ans);
            }
        }
        Matrix multiply(v, this->row, m.column);
        return multiply;
    }

    Matrix &Matrix::operator*=(const Matrix &m)
    {
        *this = *this * m;
        return *this;
    }

    bool Matrix::operator<(const Matrix &m) const
    {
        int sum1 = 0;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                sum1 += this->mat.at(i).at(j);
            }
        }
        int sum2 = 0;
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.column; j++)
            {
                sum2 += m.mat.at(i).at(j);
            }
        }
        return sum1 < sum2;
    }

    bool Matrix::operator<=(const Matrix &m) const
    {
        int sum1 = 0;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                sum1 += this->mat.at(i).at(j);
            }
        }
        int sum2 = 0;
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.column; j++)
            {
                sum2 += m.mat.at(i).at(j);
            }
        }
        return sum1 <= sum2;
    }

    bool Matrix::operator>(const Matrix &m) const
    {
        return m < *this;
    }

    bool Matrix::operator>=(const Matrix &m) const
    {
        return m <= *this;
    }

    bool Matrix::operator==(const Matrix &m) const
    {
        if ((this->row != m.row) || (this->column != m.column))
        {
            throw invalid_argument("Matrix must bw in the same sizes");
        }
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                if (this->mat.at(i).at(j) != m.mat.at(i).at(j))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool Matrix::operator!=(const Matrix &m) const
    {
        return !(*this == m);
    }

    ostream &operator<<(ostream &os, const Matrix &m)
    {
        for (int i = 0; i < m.row; i++)
        {
            os << "[";
            for (int j = 0; j < m.column; j++)
            {
                os << m.mat.at(i).at(j) << " ";
            }
            os << "]\n";
        }

        return os;
    }

    istream &operator>>(istream &is, Matrix &m)
    {
        char c;
        int row;
        int col;
        string num = "";
        vector<double> v;

        while (is >> c)
        {

            if (c == '[')
            {
                row++;
                v.clear();
            }
            else if ((c >= '0' && c <= '9') || c == '.')
            {
                num += c;
            }
            else if (c == ']' || ' ')
            {
                double n = stod(num);
                v.push_back(n);
                num = "";
                col++;
                if (c == ']')
                {
                    m.mat.push_back(v);
                }
            }
            else if (c == ',')
            {
                col = 0;
            }
        }
        m.column = col;
        m.row = row;
        return is;
    }
};