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

    // This is a logic transposed which means that the inner matrix implementations, RowsN and ColumnsN are maintained,
    // and what is changed is the _isTransposed member value.
    // The returned matrix will behave as a transposed though, just keep in mind that the varialbe where you are assigning the transposed,
    // will need to be of type Matrix<T,RowsN,ColumnsN,Container> with all template arguments equal to this original matrix.
    //
    // It's faster used in rvalues since it does not copy values, it just returns this same matrix by reference swapping the _isTransposed member value.
    //
    // return the same matrix but swapping the _isTransposed member value.
    Matrix<T,RowsN,ColumnsN,Container>& logicTransposed() &&{
        _isTransposed = (_isTransposed + 1)%2;
        return *this;
    }

    // This is a logic transposed which means that the inner matrix implementations, RowsN and ColumnsN are maintained,
    // and what is changed is the _isTransposed member value.
    // The returned matrix will behave as a transposed though, just keep in mind that the varialbe where you are assigning the transposed,
    // will need to be of type Matrix<T,RowsN,ColumnsN,Container> with all template arguments equal to this original matrix.
    //
    // It's usefull used in rvalues since it does not copy values, it just returns this same matrix by reference swapping the _isTransposed member value.
    // Does not make much sence in lvalues since it copies the inner matrix implementation, but is here for completeness.
    //
    // return the same matrix but swapping the _isTransposed member value.
    Matrix<T,RowsN,ColumnsN,Container> logicTransposed() const &{
        Matrix<T,RowsN,ColumnsN,Container> mat = *this;
        mat._isTransposed = (_isTransposed + 1)%2;
        return mat;
    }

    // TODO: Implement a physical transpose to return a Matri<T,ColumnsN,RowsN,Container>
    // In order to do so all stored values should be copied (use retrieve for retrieving the values in *this),
    // and no extra values should be stored (use insert to insert values in returned matrix)

    // returns the _isTransposed value.
    // It's mostly usefull for testing when the logicTransposed is used.
    bool isTransposed() const{
        return _isTransposed==1;
    }

    // returns the number of actually stored elements
    // usefull for testing when implementing sparce matrix using 'map' as container.
    size_t storedElementsCount() const{
        size_t elements = 0;

        for(auto rowsIt = std::begin(_mat); rowsIt != std::end(_mat); ++rowsIt){
            for(auto columnsIt = std::begin(*rowsIt); columnsIt != std::end(*rowsIt); ++columnsIt){
                ++elements;
            }
        }

        return elements;
    }

    // returns a reference to the element in row 'row', column 'column'.
    // if the element does not exist it may be created depending of the Container used for the row.
    // For example, of the container is a 'map', and the value at row,column does not exist, it will be created.
    // if you are using a 'map' container and you want to retrieve a copy of the value but you don't want to create it if it does not exist
    // use 'retrieveAt' instead.
    T& at(size_t row, size_t column){
        auto actualRowColumn = actualRowColumnIndex(row, column);
        return _mat[actualRowColumn.first][actualRowColumn.second];
    }

    // returns a copy of the element in row 'row', column 'column'.
    // if the Container is a structure like a 'map',
    // this method will not create an element in position (row,column) if there isn't one in that position.
    // This is usefull for sparce matrix implementations.
    T retrieveAt(size_t row, size_t column) const;

    void insertValueAtRowColumn(const T& value, size_t row, size_t column);

private:
    std::pair<size_t, size_t> actualRowColumnIndex(size_t row, size_t column) const{
        size_t actualRow = (_isTransposed^1) *row + (_isTransposed) *column;
        size_t actualColumn = (_isTransposed^1) *column + (_isTransposed) *row;
        return { actualRow, actualColumn };
    }

    T getValueAtIndex(const T[ColumnsN], size_t) const;
    void insertValueAtRowIndex(const T&, T[ColumnsN], size_t);

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
    auto actualRowColumn = actualRowColumnIndex(row, column);

    return getValueAtIndex(_mat[actualRowColumn.first], actualRowColumn.second);
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
T Matrix<T, RowsN, ColumnsN, Container>::getValueAtIndex(const T row[ColumnsN], size_t index) const{
    return row[index];
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
void Matrix<T, RowsN, ColumnsN, Container>::insertValueAtRowColumn(const T& value, size_t row, size_t column){
    auto actualRowColumn = actualRowColumnIndex(row, column);
    insertValueAtRowIndex(value, _mat[actualRowColumn.first], actualRowColumn.second);
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
void Matrix<T, RowsN, ColumnsN, Container>::insertValueAtRowIndex(const T& value, T row[ColumnsN], size_t index){
    row[index] = value;
}

#endif