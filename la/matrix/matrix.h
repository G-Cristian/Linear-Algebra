#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <initializer_list>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

/* ----- FORWARD DECLARETIONS ----- */

template<typename , size_t, size_t, typename> class Matrix;
template<typename, size_t, typename> class RowIterator;
template<typename, size_t, typename> class ConstRowIterator;

/* ----- PRINT OPERATOR ----- */

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
std::ostream& operator<<(std::ostream&, const Matrix<T,RowsN,ColumnsN,Container>&);

/* ----- OPERATORS ----- */

// return the matrix multiplication.
// The container type used for the returned matrix is is an array.
template<typename T, size_t RowsN_1, size_t ColumnsN_1, size_t ColumnsN_2, typename Container_2>
Matrix<T, RowsN_1, ColumnsN_2, T[ColumnsN_2]> operator*(const Matrix<T, RowsN_1, ColumnsN_1, T[ColumnsN_1]>&, const Matrix<T, ColumnsN_1, ColumnsN_2, Container_2>&);

// return the matrix multiplication.
// The container type used for the returned matrix is the same type as the one used for the first matrix.
template<typename T, size_t RowsN_1, size_t ColumnsN_1, typename Container_1, size_t ColumnsN_2, typename Container_2>
Matrix<T, RowsN_1, ColumnsN_2, Container_1> operator*(const Matrix<T, RowsN_1, ColumnsN_1, Container_1>&, const Matrix<T, ColumnsN_1, ColumnsN_2, Container_2>&);

template<typename T, size_t RowsN, size_t ColumnsN, typename Container_1, typename Container_2>
Matrix<T, RowsN, ColumnsN, Container_1> operator+(const Matrix<T, RowsN, ColumnsN, Container_1>&, const Matrix<T, RowsN, ColumnsN, Container_2>&);

template<typename T, size_t RowsN, size_t ColumnsN, typename Container_1, typename Container_2>
Matrix<T, RowsN, ColumnsN, Container_1> operator-(const Matrix<T, RowsN, ColumnsN, Container_1>&, const Matrix<T, RowsN, ColumnsN, Container_2>&);

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
Matrix<T, RowsN, ColumnsN, Container> operator*(const Matrix<T, RowsN, ColumnsN, Container>&, T);
template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
Matrix<T, RowsN, ColumnsN, Container> operator*(T, const Matrix<T, RowsN, ColumnsN, Container>&);
template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
Matrix<T, RowsN, ColumnsN, Container> operator/(const Matrix<T, RowsN, ColumnsN, Container>&, T);

/* ----- OTHER OPERATIONS ----- */

template<typename T, size_t ColumnsN, typename Container1, typename Container2>
T dot(const Matrix<T, 1, ColumnsN, Container1>&, const Matrix<T, 1, ColumnsN, Container2>&);

/* ----- MATRIX ----- */

template<typename T, size_t RowsN, size_t ColumnsN, typename Container=T[ColumnsN]>
class Matrix{
public:
    Matrix();
    Matrix(std::initializer_list<std::initializer_list<T>>);
    
    template<typename Container_row>
    explicit Matrix(const Container_row &row);

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

    template<typename Container_Ret>
    Matrix<T,ColumnsN,RowsN,Container_Ret> transposed() const;

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

    Matrix<T,1,ColumnsN,Container> rowAtIndex(size_t index) const{
        return Matrix<T,1,ColumnsN,Container>(_mat[index]);
    }

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
        return ConstRowIterator<T,ColumnsN, Container>::begin(&(_mat[rowIndex]));
    }

    //returns a RowIterator for the begining of the row at 'rowIndex'
    RowIterator<T, ColumnsN, Container> rowIteratorBegin(size_t rowIndex){
        return RowIterator<T,ColumnsN, Container>::begin(&(_mat[rowIndex]));
    }

    //returns a ConstRowIterator for the ending of the row at 'rowIndex'
    ConstRowIterator<T, ColumnsN, Container> rowIteratorEnd(size_t rowIndex) const{
        return ConstRowIterator<T,ColumnsN, Container>::end(&(_mat[rowIndex]));
    }

    //returns a RowIterator for the ending of the row at 'rowIndex'
    RowIterator<T, ColumnsN, Container> rowIteratorEnd(size_t rowIndex){
        return RowIterator<T,ColumnsN, Container>::end(&(_mat[rowIndex]));
    }

    /* ----- FRIENDS ----- */

    /* ----- OPERATORS ----- */

    template<typename Container2>
    Matrix<T, RowsN, ColumnsN, Container>& operator+=(const Matrix<T,RowsN,ColumnsN,Container2>&);

    template<typename Container2>
    Matrix<T, RowsN, ColumnsN, Container>& operator-=(const Matrix<T,RowsN,ColumnsN,Container2>&);

    Matrix<T, RowsN, ColumnsN, Container>& operator*=(const T&);
    Matrix<T, RowsN, ColumnsN, Container>& operator/=(const T&);

    // returns a reference to this matrix with the negative of each element
    // used for rvalues
    Matrix<T, RowsN, ColumnsN, Container>& operator-() &&{
        return (*this)*=(-1);
    }

    // returns a copy of the matrix with the negative of each element
    // used for lvalues
    Matrix<T, RowsN, ColumnsN, Container> operator-() const &{
        Matrix<T, RowsN, ColumnsN, Container>ret(*this);
        return ret*=(-1);
    }

    //Vector operations

private:
    /* ----- UTILITIES ----- */

    T getValueAtIndex(const T(&)[ColumnsN], size_t) const;
    T getValueAtIndex(const std::map<size_t,T>&, size_t) const;
    void insertValueAtRowIndex(const T&, T(&)[ColumnsN], size_t);
    void insertValueAtRowIndex(const T&, std::map<size_t, T>&, size_t);

    void resetRow(T(&)[ColumnsN]);
    void resetRow(std::map<size_t, T>&);

    void copyRow(Container &dest, const T(&src)[ColumnsN]);
    void copyRow(Container &dest, const std::map<size_t, T> &src);

    /* ----- MEMBERS ----- */

    Container _mat[RowsN];
};

/* ----- ROWITERATOR (array) ----- */

template<typename T, size_t ColumnsN>
class RowIterator<T, ColumnsN, T[ColumnsN]>{
public:
    typedef T Container[ColumnsN];

    static RowIterator begin(Container *row){
        return RowIterator(row, 0);
    }

    static RowIterator end(Container *row){
        return RowIterator(row, ColumnsN);
    }

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

    /* ----- MEMBERS ----- */

    Container *_row;
    size_t _index;
};

/* ----- CONSTROWITERATOR (array) ----- */

template<typename T, size_t ColumnsN>
class ConstRowIterator<T, ColumnsN, T[ColumnsN]>{
public:
    typedef T Container[ColumnsN];

    static ConstRowIterator begin(const Container *row){
        return ConstRowIterator(row, 0);
    }

    static ConstRowIterator end(const Container *row){
        return ConstRowIterator(row, ColumnsN);
    }

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

    /* ----- MEMBERS ----- */

    const Container *_row;
    size_t _index;
};

/* ----- ROWITERATOR (map) ----- */

template<typename T, size_t ColumnsN>
class RowIterator<T, ColumnsN, std::map<size_t, T>>{
public:
    typedef std::map<size_t, T> Container;
    typedef typename std::map<size_t, T>::iterator iterator;

    static RowIterator begin(Container *row){
        return RowIterator(row->begin());
    }

    static RowIterator end(Container *row){
        return RowIterator(row->end());
    }

    RowIterator(const RowIterator &ri):
        _it(ri._it){
    }

    RowIterator& operator++(){
        ++_it;
        return *this;
    }

    std::pair<size_t, T&> operator*(){
        return { _it->first, _it->second };
    }

    bool operator==(const RowIterator &rho)const{
        return _it == rho._it;
    }

    bool operator!=(const RowIterator &rho)const{
        return !(*this == rho);
    }
    
private:
    explicit RowIterator(const iterator & it):
        _it(it){
    }

    /* ----- MEMBERS ----- */

    iterator _it;
};

/* ----- CONSTROWITERATOR (map) ----- */

template<typename T, size_t ColumnsN>
class ConstRowIterator<T, ColumnsN, std::map<size_t, T>>{
public:
    typedef std::map<size_t, T> Container;
    typedef typename std::map<size_t, T>::const_iterator constIterator;

    static ConstRowIterator begin(const Container *row){
        return ConstRowIterator(row->begin());
    }

    static ConstRowIterator end(const Container *row){
        return ConstRowIterator(row->end());
    }

    ConstRowIterator(const ConstRowIterator &ri):
        _it(ri._it){
    }

    ConstRowIterator& operator++(){
        ++_it;
        return *this;
    }

    std::pair<size_t, const T&> operator*(){
        return { _it->first, _it->second };
    }

    bool operator==(const ConstRowIterator &rho)const{
        return _it == rho._it;
    }

    bool operator!=(const ConstRowIterator &rho)const{
        return !(*this == rho);
    }
    
private:
    explicit ConstRowIterator(const constIterator & it):
        _it(it){
    }

    /* ----- MEMBERS ----- */

    constIterator _it;
};

/* ----- DEFINITIONS ----- */

/* ----- ROWITERATOR (Array) DEFINITIONS ----- */

/* ----- MATRIX DEFINITIONS ----- */

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
Matrix<T, RowsN, ColumnsN, Container>::Matrix(){
    using namespace std;
    for(auto rowIt=begin(_mat); rowIt != end(_mat); rowIt++){
        resetRow(*rowIt);
    }
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
Matrix<T, RowsN, ColumnsN, Container>::Matrix(std::initializer_list<std::initializer_list<T>> il):Matrix(){
    size_t row = 0;
    size_t column = 0;
    auto endIL = il.end();
    for(auto rowIt = il.begin(); rowIt != endIL; ++rowIt){
        column = 0;
        auto endInnerIL = rowIt->end();
        for(auto columnIt = rowIt->begin(); columnIt != endInnerIL; ++columnIt){
            this->insertValueAtRowColumn(*columnIt, row, column);
            ++column;
        }
        ++row;
    }
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
template<typename Container_row>
Matrix<T, RowsN, ColumnsN, Container>::Matrix(const Container_row &srcRow){
    using namespace std;
    for(auto rowIt=begin(_mat); rowIt != end(_mat); rowIt++){
        copyRow(*rowIt, srcRow);
    }
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
void Matrix<T, RowsN, ColumnsN, Container>::resetRow(T(&row)[ColumnsN]){
    for(auto it = std::begin(row); it != std::end(row); ++it){
        *it = T();
    }
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
void Matrix<T, RowsN, ColumnsN, Container>::resetRow(std::map<size_t, T> &row){
    row=std::map<size_t, T>();
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
void Matrix<T, RowsN, ColumnsN, Container>::copyRow(Container &dest, const T(&src)[ColumnsN]){
    size_t i=0;
    for(auto c:src){
        dest[i]=c;
        ++i;
    }
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
void Matrix<T, RowsN, ColumnsN, Container>::copyRow(Container &dest, const std::map<size_t, T> &src){
    resetRow(dest);
    for(auto it = src.begin(); it != src.end(); ++it){
        dest[it->first]=it->second;
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

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
template<typename Container2>
Matrix<T, RowsN, ColumnsN, Container>& Matrix<T, RowsN, ColumnsN, Container>::operator+=(const Matrix<T,RowsN,ColumnsN,Container2> &m2){
    for(size_t row = 0; row < RowsN; ++row){
        auto endIt = m2.rowIteratorEnd(row);
        for(auto it = m2.rowIteratorBegin(row); it != endIt; ++it){
            T sum = this->at(row, (*it).first) + (*it).second;
            this->insertValueAtRowColumn(sum, row, (*it).first);
        }
    }

    return *this;
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
template<typename Container2>
Matrix<T, RowsN, ColumnsN, Container>& Matrix<T, RowsN, ColumnsN, Container>::operator-=(const Matrix<T,RowsN,ColumnsN,Container2> &m2){
    for(size_t row = 0; row < RowsN; ++row){
        auto endIt = m2.rowIteratorEnd(row);
        for(auto it = m2.rowIteratorBegin(row); it != endIt; ++it){
            T sum = this->at(row, (*it).first) - (*it).second;
            this->insertValueAtRowColumn(sum, row, (*it).first);
        }
    }

    return *this;
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
Matrix<T, RowsN, ColumnsN, Container>& Matrix<T, RowsN, ColumnsN, Container>::operator*=(const T &scalar){
    if(scalar == T())
    {
        // if multiplying by 0
        for(auto rowIt = std::begin(_mat); rowIt != std::end(_mat); ++rowIt){
            // reset each row
            resetRow(*rowIt);
        }
    }
    else{
        //if multiplying by scalar not equal 0
        for(size_t row = 0; row < RowsN; ++row){
            //update each row
            auto endIt = this->rowIteratorEnd(row);
            for(auto it = this->rowIteratorBegin(row); it != endIt; ++it){
                //multiplying only stored values
                (*it).second*=scalar;
            }
        }
    }

    return *this;
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
Matrix<T, RowsN, ColumnsN, Container>& Matrix<T, RowsN, ColumnsN, Container>::operator/=(const T &scalar){
    for(size_t row = 0; row < RowsN; ++row){
        //update each row
        auto endIt = this->rowIteratorEnd(row);
        for(auto it = this->rowIteratorBegin(row); it != endIt; ++it){
            //dividing only stored values
            (*it).second/=scalar;
        }
    }

    return *this;
}

/* ----- FUNCTIONS ----- */

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
std::ostream& operator<<(std::ostream &op, const Matrix<T,RowsN,ColumnsN,Container> &mat){
    op << "[" << std::endl;
    for(size_t row = 0; row < mat.rows(); ++row){
        op << " [";
        for(size_t column = 0; column < mat.columns(); ++column){
            op << " " << mat.retrieveAt(row,column);
        }
        op << " ]" << std::endl;
    }
    op << "]" << std::endl;
    return op;
}

// return the matrix addition.
// The container type used for the returned matrix is the same type as the one used for the left hand matrix.
template<typename T, size_t RowsN, size_t ColumnsN, typename Container_1, typename Container_2>
Matrix<T, RowsN, ColumnsN, Container_1> operator+(const Matrix<T, RowsN, ColumnsN, Container_1> &lh, const Matrix<T, RowsN, ColumnsN, Container_2> &rh){
    Matrix<T, RowsN, ColumnsN, Container_1> ret(lh);
    return ret+=rh;
}

// return the matrix subtraction.
// The container type used for the returned matrix is the same type as the one used for the left hand matrix.
template<typename T, size_t RowsN, size_t ColumnsN, typename Container_1, typename Container_2>
Matrix<T, RowsN, ColumnsN, Container_1> operator-(const Matrix<T, RowsN, ColumnsN, Container_1> &lh, const Matrix<T, RowsN, ColumnsN, Container_2> &rh){
    Matrix<T, RowsN, ColumnsN, Container_1> ret(lh);
    return ret-=rh;
}

template<typename U, size_t RowsN_1, size_t ColumnsN_1, size_t ColumnsN_2, typename Container_2>
Matrix<U, RowsN_1, ColumnsN_2, U[ColumnsN_2]> operator*(const Matrix<U, RowsN_1, ColumnsN_1, U[ColumnsN_1]> &mat1, const Matrix<U, ColumnsN_1, ColumnsN_2, Container_2> &mat2){
    Matrix<U, RowsN_1, ColumnsN_2, U[ColumnsN_2]> ret;
    // for each row in mat 1
    for(size_t row1 = 0; row1 < RowsN_1; ++row1){    
        auto endRow1It = mat1.rowIteratorEnd(row1);
        // grab stored values in current row of mat1
        for(auto row1It = mat1.rowIteratorBegin(row1); row1It != endRow1It; ++row1It){
            auto endRow2It = mat2.rowIteratorEnd((*row1It).first);
            // grab stored values in the corresponding row of mat2
            for(auto row2It = mat2.rowIteratorBegin((*row1It).first); row2It != endRow2It; ++row2It){
                // multiply the corresponding value of the row of mat1 with the corresponding value of the row of mat2
                // and add that value in the corresponding position
                ret.at(row1,(*row2It).first)+=((*row1It).second*(*row2It).second);
            }
        }
    }

    return ret;
}

template<typename U, size_t RowsN_1, size_t ColumnsN_1, typename Container_1, size_t ColumnsN_2, typename Container_2>
Matrix<U, RowsN_1, ColumnsN_2, Container_1> operator*(const Matrix<U, RowsN_1, ColumnsN_1, Container_1> &mat1, const Matrix<U, ColumnsN_1, ColumnsN_2, Container_2> &mat2){
    Matrix<U, RowsN_1, ColumnsN_2, Container_1> ret;
    // for each row in mat 1
    for(size_t row1 = 0; row1 < RowsN_1; ++row1){    
        auto endRow1It = mat1.rowIteratorEnd(row1);
        std::vector<U> tmpRow(ColumnsN_2, 0);
        // grab stored values in current row of mat1
        for(auto row1It = mat1.rowIteratorBegin(row1); row1It != endRow1It; ++row1It){
            auto endRow2It = mat2.rowIteratorEnd((*row1It).first);
            // grab stored values in the corresponding row of mat2
            for(auto row2It = mat2.rowIteratorBegin((*row1It).first); row2It != endRow2It; ++row2It){
                // multiply the corresponding value of the row of mat1 with the corresponding value of the row of mat2
                // and add that value to the temp row in the corresponding position
                tmpRow[(*row2It).first]+=((*row1It).second*(*row2It).second);
            }
        }
        // finally copy the tempRow to the corresponding row of the returned matrix
        auto tmpRowSize = tmpRow.size();
        for(size_t i = 0; i < tmpRowSize; ++i){
            ret.insertValueAtRowColumn(tmpRow[i],row1, i);
        }
    }

    return ret;
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
Matrix<T, RowsN, ColumnsN, Container> operator*(const Matrix<T, RowsN, ColumnsN, Container> &mat, T scalar){
    Matrix<T, RowsN, ColumnsN, Container> ret(mat);
    return ret*=scalar;
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
Matrix<T, RowsN, ColumnsN, Container> operator*(T scalar, const Matrix<T, RowsN, ColumnsN, Container> &mat){
    return mat*scalar;
}

template<typename T, size_t RowsN, size_t ColumnsN, typename Container>
Matrix<T, RowsN, ColumnsN, Container> operator/(const Matrix<T, RowsN, ColumnsN, Container> &mat, T scalar){
    Matrix<T, RowsN, ColumnsN, Container> ret(mat);
    return ret/=scalar;
}

//Vector operations

// returns the dot product of two vectors
// It will always return the dot product as long as you provide two matrix with RowsN == 1 and same ColumnsN
// If what is intended is the matrix product use the matrix operator*
template<typename T, size_t ColumnsN, typename Container1, typename Container2>
T dot(const Matrix<T, 1, ColumnsN, Container1> &v1, const Matrix<T, 1, ColumnsN, Container2> &v2){
    T sum = T();
    auto endIt = v1.rowIteratorEnd(0);

    for(auto it = v1.rowIteratorBegin(0); it != endIt; ++it){
        sum += ((*it).second * v2.retrieveAt(0,(*it).first));
    }

    return sum;
}

#endif