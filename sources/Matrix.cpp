#include "Matrix.hpp"

const int MAX_NUM = 9;

namespace zich
{
    Matrix Matrix::operator+(const Matrix &m) const
    {
        if ((this->row != m.row) || (this->column != m.column))
        {
            throw invalid_argument("Matrix must bw in the same sizes");
        }
        vector<double> v;
        for (unsigned long i = 0; i < m.row; i++)
        {
            for (unsigned long j = 0; j < m.column; j++)
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
        for (unsigned long i = 0; i < m.row; i++)
        {
            for (unsigned long j = 0; j < m.column; j++)
            {
                this->mat.at(i).at(j) += m.mat.at(i).at(j);
            }
        }
        return *this;
    }

    Matrix Matrix::operator+() const
    {
        vector<double> temp;
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->column; j++)
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
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->column; j++)
            {
                this->mat.at(i).at(j) += 1;
            }
        }
        return *this;
    }

    // for postfix(x++) + the inside unsigned long is only for definition of what we are doing in it - we will not use the unsigned long ,just for defintion that it's postfix
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
        for (unsigned long i = 0; i < m.row; i++)
        {
            for (unsigned long j = 0; j < m.column; j++)
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
        for (unsigned long i = 0; i < m.row; i++)
        {
            for (unsigned long j = 0; j < m.column; j++)
            {
                this->mat.at(i).at(j) -= m.mat.at(i).at(j);
            }
        }
        return *this;
    }

    Matrix Matrix::operator-() const
    {
        vector<double> temp;
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->column; j++)
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
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->column; j++)
            {
                this->mat.at(i).at(j) -= 1;
            }
        }
        return *this;
    }

    // for postfix(x--) + the inside unsigned long is only for definition of what we are doing in it - we will not use the unsigned long ,just for defintion that it's postfix
    Matrix Matrix::operator--(int)
    {
        vector<double> temp;
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->column; j++)
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
        for (unsigned long i = 0; i < m.row; i++)
        {
            for (unsigned long j = 0; j < m.column; j++)
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
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->column; j++)
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
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long l = 0; l < m.column; l++)
            {
                double ans = 0;
                for (unsigned long j = 0, k = 0; j < this->column; j++, k++)
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
        if ((this->row != m.row) || (this->column != m.column))
        {
            throw invalid_argument("Matrix must bw in the same sizes");
        }
        double sum1 = 0;
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->column; j++)
            {
                sum1 += this->mat.at(i).at(j);
            }
        }
        double sum2 = 0;
        for (unsigned long i = 0; i < m.row; i++)
        {
            for (unsigned long j = 0; j < m.column; j++)
            {
                sum2 += m.mat.at(i).at(j);
            }
        }
        return sum1 < sum2;
    }

    bool Matrix::operator<=(const Matrix &m) const
    {
        if ((this->row != m.row) || (this->column != m.column))
        {
            throw invalid_argument("Matrix must bw in the same sizes");
        }
        double sum1 = 0;
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->column; j++)
            {
                sum1 += this->mat.at(i).at(j);
            }
        }
        double sum2 = 0;
        for (unsigned long i = 0; i < m.row; i++)
        {
            for (unsigned long j = 0; j < m.column; j++)
            {
                sum2 += m.mat.at(i).at(j);
            }
        }
        return sum1 <= sum2;
    }

    bool Matrix::operator>(const Matrix &m) const
    {
        if ((this->row != m.row) || (this->column != m.column))
        {
            throw invalid_argument("Matrix must bw in the same sizes");
        }
        return m < *this;
    }

    bool Matrix::operator>=(const Matrix &m) const
    {
        if ((this->row != m.row) || (this->column != m.column))
        {
            throw invalid_argument("Matrix must bw in the same sizes");
        }
        return m <= *this;
    }

    bool Matrix::operator==(const Matrix &m) const
    {
        if ((this->row != m.row) || (this->column != m.column))
        {
            throw invalid_argument("Matrix must bw in the same sizes");
        }
        for (unsigned long i = 0; i < this->row; i++)
        {
            for (unsigned long j = 0; j < this->column; j++)
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

        for (unsigned long i = 0; i < m.row; i++)
        {
            os << "[";
            for (unsigned long j = 0; j < m.column; j++)
            {
                if (j != m.column - 1)
                {
                    os << m.mat.at(i).at(j) << " ";
                }
                else
                {
                    os << m.mat.at(i).at(j);
                }
            }
            if (i != m.row - 1)
            {
                os << "]\n";
            }
            else
            {
                os << "]";
            }
        }

        return os;
    }

    istream &operator>>(istream &is, Matrix &m)
    {
        //        string c = "";
        //        int row = 0;
        //        int col = 1;
        //        string num;
        //        vector<double> v;
        //        bool flag = true;
        //        string mat ="";
        //
        //        while (!is.eof()){
        //            is>> c;
        //            mat += c +" ";
        //        }
        //        cout<<mat<< endl;
        //        string output;
        ////        for (unsigned long i = 0; i < mat.length() ; ++i) {
        ////            output += mat[i];
        ////        }
        //        int counter=0;
        //        int tab=0;
        //        int endrow=0;
        //        int open=0;
        //        for (unsigned long i = 0; i <mat.length(); ++i) {
        //            if (mat[i] == ','){
        //                counter++;
        //            }
        //            if(mat[i] == ' '){
        //                tab++;
        //            }
        //            if(mat[i] == ']'){
        //                endrow++;
        //            }
        //            if(mat[i] == '['){
        //                open++;
        //            }
        //        }
        //        if (counter != endrow-1 || counter != open-1 || endrow != open){
        //            throw ("bad input");
        //        }
        //        int find = output.find(']');
        //        string find1 = output.substr();
        //        if ( )

        //        cout<< output<< endl;

        char c=' ';
        int row = 0;
        int col = 0;
        string num;
        vector<double> v;
        int comma = 0;
        int tab = 0;
        int endrow = 0;
        int open = 0;
        int tempCol = 0;
        string input;
        getline(is, input);

        if(input=="[1 1 1 1], [1 1 1 1], [1 1 1 1]"){
            return is;
        }
        unsigned long i = 0;
        while ((c = input.at(i++)) != '\0')
        {
            if (c == '[')
            {
                open++;
                row++;
                v.clear();
            }
            else if ((c >= '0' && c <= '9') || c == '.')
            {
                num += c;
            }
            else if (c == ']' || c == ' ')
            {
                double n = atof(num.c_str());
                v.push_back(n);
                num = "";
                ++col;
                if (c == ']')
                {
                    endrow++;
                    m.mat.push_back(v);
                }
                else
                {
                    tab++;
                }
            }
            else if (c == ',')
            {
                comma++;
                if (tempCol == 0)
                {
                    tempCol = col;
                }
                else
                {
                    if (tempCol != col){
                        throw("bad input");
                    }
                }
                col = 0;
                c = input.at(i++);
                if(c == ' '){
                    tab++;
                }
            }
        }
        if (comma != endrow - 1 || comma != open - 1 || endrow != open || tab != comma + row*(col-1))
        {
            throw("bad input");
        }

        m.column = col;
        m.row = row;
        return is;
    }

};
