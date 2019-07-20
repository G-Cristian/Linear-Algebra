#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <utility>
#include <vector>

template<typename T, size_t RowsN, size_t ColumnsN, typename Container=T[ColumnsN]>
class Matrix{
public:
    Matrix();

    //dimentions

    //gets total size.
    size_t size() const{
        return RowsN*ColumnsN;
    }

    //gets number of rows.
    size_t rows() const{
        return (_isTransposed^1) *RowsN + (_isTransposed) *ColumnsN;
    }

    //gets number of columns.
    size_t columns() const{
        return (_isTransposed^1) *ColumnsN + (_isTransposed) *RowsN;
    }

    Matrix<T,RowsN,ColumnsN,Container>& transposed() &&{
        _isTransposed = (_isTransposed + 1)%2;
        return *this;
    }

    // TODO: Replace this method to return a Matri<T,ColumnsN,RowsN,Container>
    // in order to do so all stored values should be copied (use retrieve for retrieving the values in *this),
    // and no extra values should be stored (use insert to insert values in returned matrix)
    Matrix<T,RowsN,ColumnsN,Container> transposed() const &{
        Matrix<T,RowsN,ColumnsN,Container> mat = *this;
        mat._isTransposed = (_isTransposed + 1)%2;
        return mat;
    }

    bool isTransposed() const{
        return _isTransposed==1;
    }

    // returns a reference of the element in row 'row', column 'column'.
    // if the element does not exist i may be created depending of the Container used for the row.
    // For example, of the container is a 'map', and the value at row,column does not exist, it will be created.
    // if you are using a 'map' container and you want to retrieve a copy of the value but you don't want to create it if it does not exist
    // use 'retrieveAt' instead.
    T& at(size_t row, size_t column){
        auto actualRowColumn = actualRowColumnIndex(row, column);
        return _mat[actualRowColumn.first][actualRowColumn.second];
    }

    T retrieveAt(size_t row, size_t column) const;

private:
    std::pair<size_t, size_t> actualRowColumnIndex(size_t row, size_t column){
        size_t actualRow = (_isTransposed^1) *row + (_isTransposed) *column;
        size_t actualColumn = (_isTransposed^1) *column + (_isTransposed) *row;
        return { actualRow, actualColumn };
    }

    T getValueAtIndex(const T[ColumnsN], size_t) const;

    unsigned char _isTransposed = 0;
    Container _mat[RowsN];
};

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
Matrix<T, RowsN, ColumnsN, Container>::Matrix(){
    using namespace std;
    for(auto rowIt=begin(_mat); rowIt != end(_mat); rowIt++){
        for(auto colIt=begin(*rowIt); colIt != end(*rowIt); colIt++){
            *colIt=T();
        }
    }
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
T Matrix<T, RowsN, ColumnsN, Container>::retrieveAt(size_t row, size_t column) const{
    size_t actualRow = (_isTransposed^1) *row + (_isTransposed) *column;
    size_t actualColumn = (_isTransposed^1) *column + (_isTransposed) *row;

    return getValueAtIndex(_mat[actualRow], actualColumn);
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
T Matrix<T, RowsN, ColumnsN, Container>::getValueAtIndex(const T row[ColumnsN], size_t index) const{
    return row[index];
}

#endif