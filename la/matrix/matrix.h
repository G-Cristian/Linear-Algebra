#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <map>
#include <utility>
#include <vector>

template<typename , size_t, size_t, typename> class Matrix;

// return the matrix multiplication.
// The container type used for the returned matrix is the same type as the one used for the second matrix.
//template<typename T, size_t RowsN_1, size_t ColumnsN_1, typename Container_1, size_t ColumnsN_2, typename Container_2>
//Matrix<T, RowsN_1, ColumnsN_2, Container_2> operator*(const Matrix<T, RowsN_1, ColumnsN_1, Container_1>&, const Matrix<T, ColumnsN_1, ColumnsN_2, Container_2>&);

template<typename T, size_t ColumnsN, size_t ColumnsN_2, typename Container_2>
void multiplyRow(const T(&row)[ColumnsN], const Matrix<T,ColumnsN,ColumnsN_2,Container_2> &mat2, T(&ret)[ColumnsN_2]);

template<typename T, size_t ColumnsN, typename Container1>
T dot(const Matrix<T, 1, ColumnsN, Container1>&, const Matrix<T, 1, ColumnsN, T[ColumnsN]>&);

template<typename, size_t, typename> class RowIterator;
template<typename, size_t, typename> class ConstRowIterator;

/* ----- MATRIX ----- */

template<typename T, size_t RowsN, size_t ColumnsN, typename Container=T[ColumnsN]>
class Matrix{
public:
    Matrix();

    /* ----- DIMENTIONS ----- */

    //gets total size.
    size_t size() const{
        return RowsN*ColumnsN;
    }

    //gets number of rows.
    size_t rows() const{
        //return (_isTransposed^1) *RowsN + (_isTransposed) *ColumnsN;
        return RowsN;
    }

    //gets number of columns.
    size_t columns() const{
        //return (_isTransposed^1) *ColumnsN + (_isTransposed) *RowsN;
        return ColumnsN;
    }

    /* ----- TRANSPOSE ----- */

    // This is a logic transposed which means that the inner matrix implementations, RowsN and ColumnsN are maintained,
    // and what is changed is the _isTransposed member value.
    // The returned matrix will behave as a transposed though, just keep in mind that the varialbe where you are assigning the transposed,
    // will need to be of type Matrix<T,RowsN,ColumnsN,Container> with all template arguments equal to this original matrix.
    //
    // It's faster used in rvalues since it does not copy values, it just returns this same matrix by reference swapping the _isTransposed member value.
    //
    // return the same matrix but swapping the _isTransposed member value.
    //Matrix<T,RowsN,ColumnsN,Container>& logicTransposed() &&{
    //    _isTransposed = (_isTransposed + 1)%2;
    //    return *this;
    //}

    // This is a logic transposed which means that the inner matrix implementations, RowsN and ColumnsN are maintained,
    // and what is changed is the _isTransposed member value.
    // The returned matrix will behave as a transposed though, just keep in mind that the varialbe where you are assigning the transposed,
    // will need to be of type Matrix<T,RowsN,ColumnsN,Container> with all template arguments equal to this original matrix.
    //
    // It's usefull used in rvalues since it does not copy values, it just returns this same matrix by reference swapping the _isTransposed member value.
    // Does not make much sence in lvalues since it copies the inner matrix implementation, but is here for completeness.
    //
    // return the same matrix but swapping the _isTransposed member value.
    //Matrix<T,RowsN,ColumnsN,Container> logicTransposed() const &{
    //    Matrix<T,RowsN,ColumnsN,Container> mat = *this;
    //    mat._isTransposed = (_isTransposed + 1)%2;
    //    return mat;
    //}

    template<typename Container_Ret>
    Matrix<T,ColumnsN,RowsN,Container_Ret> transposed() const;

    // TODO: Implement a physical transpose to return a Matri<T,ColumnsN,RowsN,Container>
    // In order to do so all stored values should be copied (use retrieve for retrieving the values in *this),
    // and no extra values should be stored (use insert to insert values in returned matrix)

    // returns the _isTransposed value.
    // It's mostly usefull for testing when the logicTransposed is used.
    //bool isTransposed() const{
    //    return _isTransposed==1;
    //}

    /* ----- GETTERS & SETTERS ----- */

    // returns a reference to the element in row 'row', column 'column'.
    // if the element does not exist it may be created depending of the Container used for the row.
    // For example, of the container is a 'map', and the value at row,column does not exist, it will be created.
    // if you are using a 'map' container and you want to retrieve a copy of the value but you don't want to create it if it does not exist
    // use 'retrieveAt' instead.
    T& at(size_t row, size_t column){
        //auto actualRowColumn = actualRowColumnIndex(row, column);
        //return _mat[actualRowColumn.first][actualRowColumn.second];
        return _mat[row][column];
    }

    // returns a copy of the element in row 'row', column 'column'.
    // if the Container is a structure like a 'map',
    // this method will not create an element in position (row,column) if there isn't one in that position.
    // This is usefull for sparce matrix implementations.
    T retrieveAt(size_t row, size_t column) const;

    void insertValueAtRowColumn(const T& value, size_t row, size_t column);

    /* ----- HELPERS ----- */

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

    /* ----- ITERATORS OPERATIONS ----- */

    //returns a ConstRowIterator for the begining of the row at 'rowIndex'
    ConstRowIterator<T, ColumnsN, Container> rowIteratorBegin(size_t rowIndex) const{
        return ConstRowIterator<T,ColumnsN, Container>(&(_mat[rowIndex]),0);
    }

    //returns a RowIterator for the begining of the row at 'rowIndex'
    RowIterator<T, ColumnsN, Container> rowIteratorBegin(size_t rowIndex){
        return RowIterator<T,ColumnsN, Container>(&(_mat[rowIndex]),0);
    }

    //returns a ConstRowIterator for the ending of the row at 'rowIndex'
    ConstRowIterator<T, ColumnsN, Container> rowIteratorEnd(size_t rowIndex) const{
        return ConstRowIterator<T,ColumnsN, Container>(&(_mat[rowIndex]),ColumnsN);
    }

    //returns a RowIterator for the ending of the row at 'rowIndex'
    RowIterator<T, ColumnsN, Container> rowIteratorEnd(size_t rowIndex){
        return RowIterator<T,ColumnsN, Container>(&(_mat[rowIndex]),ColumnsN);
    }

    /* ----- FRIENDS ----- */

    /* ----- OPERATORS ----- */

    // return the matrix multiplication.
    // The container type used for the returned matrix is the same type as the one used for the second matrix.
    template<typename U, size_t RowsN_1, size_t ColumnsN_1, typename Container_1, size_t ColumnsN_2, typename Container_2>
    friend Matrix<U, RowsN_1, ColumnsN_2, Container_2> operator*(const Matrix<U, RowsN_1, ColumnsN_1, Container_1>&, const Matrix<U, ColumnsN_1, ColumnsN_2, Container_2>&);

    //Vector operations

    friend T dot<>(const Matrix<T, 1, ColumnsN, Container>&, const Matrix<T, 1, ColumnsN, T[ColumnsN]>&);

private:
    /* ----- UTILITIES ----- */
    
    //std::pair<size_t, size_t> actualRowColumnIndex(size_t row, size_t column) const{
    //    size_t actualRow = (_isTransposed^1) *row + (_isTransposed) *column;
    //    size_t actualColumn = (_isTransposed^1) *column + (_isTransposed) *row;
    //    return { actualRow, actualColumn };
    //}

    T getValueAtIndex(const T(&)[ColumnsN], size_t) const;
    T getValueAtIndex(const std::map<size_t,T>&, size_t) const;
    void insertValueAtRowIndex(const T&, T(&)[ColumnsN], size_t);
    void insertValueAtRowIndex(const T&, std::map<size_t, T>&, size_t);

    void setValueToIterator(const T &value, T *it){
        *it = value;
    }

    // Note that this method does not set the index into the map iterator, just the value.
    // Usefull when the position in the matrix already exist and the value wants to be changed.
    void setValueToIterator(const T &value, typename std::map<size_t, T>::iterator &it){
        it->second = value;
    }

    /* ----- MEMBERS ----- */

    //unsigned char _isTransposed = 0;
    Container _mat[RowsN];
};

/* ----- ROWITERATOR (array) ----- */

template<typename T, size_t ColumnsN>
class RowIterator<T, ColumnsN, T[ColumnsN]>{
public:
    typedef T Container[ColumnsN];

    RowIterator(const RowIterator &ri):
        _row(ri._row),
        _index(ri._index){
    }

    RowIterator& operator++(){
        ++_index;
        return *this;
    }

    std::pair<size_t, T&> operator*(){
        return {_index, (*_row)[_index]};
    }

    bool operator==(const RowIterator &rho)const{
        return _row == rho._row && _index == rho._index;
    }

    bool operator!=(const RowIterator &rho)const{
        return !(*this == rho);
    }
    
private:
    explicit RowIterator(Container *row, size_t index):
        _row(row),
        _index(index){
    }

    /* ----- FRIENDS ----- */

    template<typename, size_t, size_t, typename>
    friend class Matrix;

    Container *_row;
    size_t _index;
};

/* ----- CONSTROWITERATOR (array) ----- */

template<typename T, size_t ColumnsN>
class ConstRowIterator<T, ColumnsN, T[ColumnsN]>{
public:
    typedef T Container[ColumnsN];

    ConstRowIterator(const ConstRowIterator &ri):
        _row(ri._row),
        _index(ri._index){
    }

    ConstRowIterator& operator++(){
        ++_index;
        return *this;
    }

    std::pair<size_t, const T&> operator*(){
        return {_index, (*_row)[_index]};
    }

    bool operator==(const ConstRowIterator &rho)const{
        return _row == rho._row && _index == rho._index;
    }

    bool operator!=(const ConstRowIterator &rho)const{
        return !(*this == rho);
    }
    
private:
    explicit ConstRowIterator(const Container *row, size_t index):
        _row(row),
        _index(index){
    }

    /* ----- FRIENDS ----- */

    template<typename, size_t, size_t, typename>
    friend class Matrix;

    const Container *_row;
    size_t _index;
};

/* ----- DEFINITIONS ----- */

/* ----- ROWITERATOR (Array) DEFINITIONS ----- */

/* ----- MATRIX DEFINITIONS ----- */

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
Matrix<T, RowsN, ColumnsN, Container>::Matrix(){
    using namespace std;
    for(auto rowIt=begin(_mat); rowIt != end(_mat); rowIt++){
        for(auto colIt=begin(*rowIt); colIt != end(*rowIt); colIt++){
            setValueToIterator(T(), colIt);
        }
    }
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
template<typename Container_Ret>
Matrix<T,ColumnsN,RowsN,Container_Ret> Matrix<T, RowsN, ColumnsN, Container>::transposed() const{
    Matrix<T,ColumnsN,RowsN,Container_Ret> mat;

    for(size_t r = 0; r < RowsN; ++r){
        for(size_t c = 0; c < ColumnsN; ++c){
            mat.insertValueAtRowColumn(this->retrieveAt(r,c), c, r);
        }
    }
        
    return mat;
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
T Matrix<T, RowsN, ColumnsN, Container>::retrieveAt(size_t row, size_t column) const{
    //auto actualRowColumn = actualRowColumnIndex(row, column);
    //return getValueAtIndex(_mat[actualRowColumn.first], actualRowColumn.second);
    return getValueAtIndex(_mat[row], column);
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
T Matrix<T, RowsN, ColumnsN, Container>::getValueAtIndex(const T (&row)[ColumnsN], size_t index) const{
    return row[index];
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
T Matrix<T, RowsN, ColumnsN, Container>::getValueAtIndex(const std::map<size_t,T> &row, size_t index) const{
    auto colIt = row.find(index);
    if(colIt != row.end()){
        return colIt->second;
    }
    else{
        return T();
    }
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
void Matrix<T, RowsN, ColumnsN, Container>::insertValueAtRowColumn(const T& value, size_t row, size_t column){
    //auto actualRowColumn = actualRowColumnIndex(row, column);
    //insertValueAtRowIndex(value, _mat[actualRowColumn.first], actualRowColumn.second);
    insertValueAtRowIndex(value, _mat[row], column);
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
void Matrix<T, RowsN, ColumnsN, Container>::insertValueAtRowIndex(const T& value, T (&row)[ColumnsN], size_t index){
    row[index] = value;
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
void Matrix<T, RowsN, ColumnsN, Container>::insertValueAtRowIndex(const T &value, std::map<size_t, T> &row, size_t index){
    if(value == T()){
        // if '0' is trying to be inserted, we must remove the position if it exists.
        auto colIt = row.find(index);
        if(colIt != row.end()){
            //if position exists, remove it.
            row.erase(colIt);
        }
    }
    else{
        // A value other than '0' is trying to be inserted so we either create the position and assigns the value
        // or assign the value to the existing position.
        row[index] = value;
    }
}

template<typename U, size_t RowsN_1, size_t ColumnsN_1, typename Container_1, size_t ColumnsN_2, typename Container_2>
Matrix<U, RowsN_1, ColumnsN_2, Container_2> operator*(const Matrix<U, RowsN_1, ColumnsN_1, Container_1> &mat1, const Matrix<U, ColumnsN_1, ColumnsN_2, Container_2> &mat2){
    Matrix<U, RowsN_1, ColumnsN_2, Container_2> ret;

    for(size_t row = 0; row < RowsN_1; ++row){
        multiplyRow(mat1._mat[row], mat2, ret._mat[row]);
    }

    return ret;
}

template<typename T, size_t ColumnsN, size_t ColumnsN_2, typename Container_2>
void multiplyRow(const T(&row)[ColumnsN], const Matrix<T,ColumnsN,ColumnsN_2,Container_2> &mat2, T(&ret)[ColumnsN_2]){
    for(size_t c2 = 0; c2 < ColumnsN_2; ++c2){
        for(size_t c = 0; c < ColumnsN; ++c){
            ret[c2] += row[c]*mat2.retrieveAt(c,c2);
        }
    }
}

//Vector operations

// returns the dot product of two vectors
// It will always return the dot product as long as you provide two matrix with RowsN == 1 and same ColumnsN
// If what is intended is the matrix product use the matrix operator*
template<typename T, size_t ColumnsN, typename Container1>
T dot(const Matrix<T, 1, ColumnsN, Container1> &v1, const Matrix<T, 1, ColumnsN, T[ColumnsN]> &v2){
    T sum = T();
    const T* row_v2 = v2._mat[0];

    for(size_t c = 0; c < ColumnsN; ++c){
        sum += (row_v2[c] * v1.retrieveAt(0,c));
    }

    return sum;
}

#endif