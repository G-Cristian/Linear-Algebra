#include "../la/matrix/matrix.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define RUN_TEST(testName, correctTestCounter, failTestCounter)     \
do{                                                                 \
    cout << "Running test: " << #testName << endl;                  \
    if(testName()){                                                 \
        correctTestCounter++;                                       \
        cout << "----- Passed"<< endl;                              \
    }                                                               \
    else {                                                          \
        failTestCounter++;                                          \
        cout << "----- Failed"<< endl;                              \
    }                                                               \
    cout << "END test " << #testName << endl;                       \
}while(false)

bool matrix_Creation();
bool matrix_Get_Size();
bool matrix_Get_Number_Of_Rows();
bool matrix_Get_Number_Of_Columns();
bool matrix_Get_Number_Of_Rows_Of_Transposed();
bool matrix_at_in_uninitialized_matrix();
bool matrix_isTransposed_rvalue();
bool matrix_isTransposed_lvalue();
bool matrix_set_value_at_and_check();
bool matrix_set_value_at_and_check_transposed();
bool matrix_retrieveAt();
bool matrix_retrieveAt_transposed();

int main(){
    int passedTests = 0;
    int failedTests = 0;
    RUN_TEST(matrix_Creation, passedTests, failedTests);
    RUN_TEST(matrix_Get_Size, passedTests, failedTests);
    RUN_TEST(matrix_Get_Number_Of_Rows, passedTests, failedTests);
    RUN_TEST(matrix_Get_Number_Of_Columns, passedTests, failedTests);
    RUN_TEST(matrix_Get_Number_Of_Rows_Of_Transposed, passedTests, failedTests);
    RUN_TEST(matrix_at_in_uninitialized_matrix, passedTests, failedTests);
    RUN_TEST(matrix_isTransposed_rvalue, passedTests, failedTests);
    RUN_TEST(matrix_isTransposed_lvalue, passedTests, failedTests);
    RUN_TEST(matrix_set_value_at_and_check, passedTests, failedTests);
    RUN_TEST(matrix_set_value_at_and_check_transposed, passedTests, failedTests);
    RUN_TEST(matrix_retrieveAt, passedTests, failedTests);
    RUN_TEST(matrix_retrieveAt_transposed, passedTests, failedTests);
    
    cout << endl << "-----------------" << endl;
    cout << "Total tests: " << passedTests +  failedTests << endl;
    cout << "Passed tests: " << passedTests << endl;
    cout << "Total tests: " << failedTests << endl;
    return 0;
}

bool matrix_Creation(){
    Matrix<float,1,2> mat;
    return true;
}

bool matrix_Get_Size(){
    Matrix<float,1,2> mat;

    return mat.size()==2;
}

bool matrix_Get_Number_Of_Rows(){
    Matrix<float,3,2> mat;
    return mat.rows() == 3;
}

bool matrix_Get_Number_Of_Columns(){
    Matrix<float,3,2> mat;
    return mat.columns() == 2;
}

bool matrix_Get_Number_Of_Rows_Of_Transposed(){
    return Matrix<float,3,2>().transposed().rows() == 2;
}

bool matrix_at_in_uninitialized_matrix(){
    bool ok =true;
    Matrix<float,3,2> mat;
    for(int i=0; i < 3 && ok; ++i){
        for(int j=0; j < 2 && ok; ++j){
            ok = mat.at(i,j) == 0.0f;
        }
    }
    return ok;
}

bool matrix_isTransposed_rvalue(){
    bool ok = Matrix<float,3,2>().transposed().isTransposed();
    return ok;
}

bool matrix_isTransposed_lvalue(){
    Matrix<float,3,2> mat;
    bool ok1 = !mat.isTransposed();
    Matrix<float,3,2> matTranp = mat.transposed();
    bool ok2 = matTranp.isTransposed();
    bool ok3 = !mat.isTransposed();

    return ok1 && ok2 && ok3;
}

bool matrix_set_value_at_and_check(){
    bool ok =true;
    Matrix<float,3,2> mat;
    mat.at(2,1)= 21.0f;
    mat.at(1,0)= 10.0f;
    for(int i=0; i < 3 && ok; ++i){
        for(int j=0; j < 2 && ok; ++j){
            if(i == 1 && j == 0){
                ok = (mat.at(i,j) == 10.0f);
            }
            else if(i == 2 && j == 1){
                ok = (mat.at(i,j) == 21.0f);
            }
            else{
                ok = (mat.at(i,j) == 0.0f);
            }
        }
    }
    return ok;
}

bool matrix_set_value_at_and_check_transposed(){
    bool ok =true;
    Matrix<float,3,2> mat;
    mat.at(2,1)= 21.0f;
    mat.at(1,0)= 10.0f;
    Matrix<float,3,2> mat2 = mat.transposed();
    for(int i=0; i < 2 && ok; ++i){
        for(int j=0; j < 3 && ok; ++j){
            if(i == 0 && j == 1){
                ok = (mat2.at(i,j) == 10.0f);
            }
            else if(i == 1 && j == 2){
                ok = (mat2.at(i,j) == 21.0f);
            }
            else{
                ok = (mat2.at(i,j) == 0.0f);
            }
        }
    }
    return ok;
}

bool matrix_retrieveAt(){
    bool ok =true;
    Matrix<float,3,2> mat;
    mat.at(2,1)= 21.0f;
    mat.at(1,0)= 10.0f;
    for(int i=0; i < 3 && ok; ++i){
        for(int j=0; j < 2 && ok; ++j){
            if(i == 1 && j == 0){
                ok = (mat.retrieveAt(i,j) == 10.0f);
            }
            else if(i == 2 && j == 1){
                ok = (mat.retrieveAt(i,j) == 21.0f);
            }
            else{
                ok = (mat.retrieveAt(i,j) == 0.0f);
            }
        }
    }
    return ok;
}

bool matrix_retrieveAt_transposed(){
    bool ok =true;
    Matrix<float,3,2> mat;
    mat.at(2,1)= 21.0f;
    mat.at(1,0)= 10.0f;
    Matrix<float,3,2> mat2 = mat.transposed();
    for(int i=0; i < 2 && ok; ++i){
        for(int j=0; j < 3 && ok; ++j){
            if(i == 0 && j == 1){
                ok = (mat2.retrieveAt(i,j) == 10.0f);
            }
            else if(i == 1 && j == 2){
                ok = (mat2.retrieveAt(i,j) == 21.0f);
            }
            else{
                ok = (mat2.retrieveAt(i,j) == 0.0f);
            }
        }
    }
    return ok;
}