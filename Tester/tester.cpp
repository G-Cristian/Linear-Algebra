#include "../la/matrix/matrix.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define RUN_TEST(testName, correctTestCounter, failTestCounter)     \
do{                                                                 \
    cout << "----------------------------------" << endl;           \
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
    cout << "----------------------------------" << endl;           \
}while(false)

/* ------------ Array container tests --------------- */

bool matrix_array_container_Creation();
bool matrix_array_container_Get_Size();
bool matrix_array_container_Get_Number_Of_Rows();
bool matrix_array_container_Get_Number_Of_Columns();
//bool matrix_array_container_Get_Number_Of_Rows_Of_Logic_Transposed();
bool matrix_array_container_Get_Number_Of_Rows_Of_Transposed();
//bool matrix_array_container_Get_Number_Of_Columns_Of_Logic_Transposed();
bool matrix_array_container_Get_Number_Of_Columns_Of_Transposed();
bool matrix_array_container_at_in_uninitialized_matrix();
//bool matrix_array_container_isTransposed_rvalue();
//bool matrix_array_container_isTransposed_lvalue();
bool matrix_array_container_set_value_at_and_check();
//bool matrix_array_container_set_value_at_and_check_logic_transposed();
bool matrix_array_container_set_value_at_and_check_transposed();
bool matrix_array_container_retrieveAt();
//bool matrix_array_container_retrieveAt_logic_transposed();
bool matrix_array_container_retrieveAt_transposed();
bool matrix_array_container_insertAt_and_check();
//bool matrix_array_container_insertAt_and_check_logic_transposed();
bool matrix_array_container_insertAt_and_check_transposed();
bool matrix_array_container_copy_constructor_copies_all();
bool matrix_array_container_assign_operator_copies_all();
bool matrix_array_container_copy_constructor_passing_transposed_copies_all();
bool matrix_array_container_assign_operator_passing_transposed_copies_all();
bool matrix_array_container_copy_constructor_copies_by_value();
bool matrix_array_container_assign_operator_copies_by_value();
bool matrix_array_container_storedElementsCount();
bool matrix_array_container_array_container_dot();
bool matrix_array_container_array_container_dot_doesnt_change_vectors_values();
bool matrix_array_container_array_container_multiplication();
bool matrix_array_container_array_container_multiplication_doesnt_change_matrices_values();

/* ------------ Map container tests --------------- */

bool matrix_map_container_Creation();
bool matrix_map_container_Get_Size();
bool matrix_map_container_Get_Number_Of_Rows();
bool matrix_map_container_Get_Number_Of_Columns();
//bool matrix_map_container_Get_Number_Of_Rows_Of_Logic_Transposed();
bool matrix_map_container_Get_Number_Of_Rows_Of_Transposed();
//bool matrix_map_container_Get_Number_Of_Columns_Of_Logic_Transposed();
bool matrix_map_container_Get_Number_Of_Columns_Of_Transposed();
bool matrix_map_container_at_in_uninitialized_matrix();
//bool matrix_map_container_isTransposed_rvalue();
//bool matrix_map_container_isTransposed_lvalue();
bool matrix_map_container_set_value_at_and_check();
//bool matrix_map_container_set_value_at_and_check_logic_transposed();
bool matrix_map_container_set_value_at_and_check_transposed();
bool matrix_map_container_retrieveAt();
//bool matrix_map_container_retrieveAt_logic_transposed();
bool matrix_map_container_retrieveAt_transposed();
bool matrix_map_container_insertAt_and_check();
//bool matrix_map_container_insertAt_and_check_logic_transposed();
bool matrix_map_container_insertAt_and_check_transposed();

int main(){
    int passedTests = 0;
    int failedTests = 0;
    /* ------------ Array container tests --------------- */
    RUN_TEST(matrix_array_container_Creation, passedTests, failedTests);
    RUN_TEST(matrix_array_container_Get_Size, passedTests, failedTests);
    RUN_TEST(matrix_array_container_Get_Number_Of_Rows, passedTests, failedTests);
    RUN_TEST(matrix_array_container_Get_Number_Of_Columns, passedTests, failedTests);
    //RUN_TEST(matrix_array_container_Get_Number_Of_Rows_Of_Logic_Transposed, passedTests, failedTests);
    RUN_TEST(matrix_array_container_Get_Number_Of_Rows_Of_Transposed, passedTests, failedTests);
    //RUN_TEST(matrix_array_container_Get_Number_Of_Columns_Of_Logic_Transposed, passedTests, failedTests);
    RUN_TEST(matrix_array_container_Get_Number_Of_Columns_Of_Transposed, passedTests, failedTests);
    RUN_TEST(matrix_array_container_at_in_uninitialized_matrix, passedTests, failedTests);
    //RUN_TEST(matrix_array_container_isTransposed_rvalue, passedTests, failedTests);
    //RUN_TEST(matrix_array_container_isTransposed_lvalue, passedTests, failedTests);
    RUN_TEST(matrix_array_container_set_value_at_and_check, passedTests, failedTests);
    //RUN_TEST(matrix_array_container_set_value_at_and_check_logic_transposed, passedTests, failedTests);
    RUN_TEST(matrix_array_container_set_value_at_and_check_transposed, passedTests, failedTests);
    RUN_TEST(matrix_array_container_retrieveAt, passedTests, failedTests);
    //RUN_TEST(matrix_array_container_retrieveAt_logic_transposed, passedTests, failedTests);
    RUN_TEST(matrix_array_container_retrieveAt_transposed, passedTests, failedTests);
    RUN_TEST(matrix_array_container_insertAt_and_check, passedTests, failedTests);
    //RUN_TEST(matrix_array_container_insertAt_and_check_logic_transposed, passedTests, failedTests);
    RUN_TEST(matrix_array_container_insertAt_and_check_transposed, passedTests, failedTests);
    RUN_TEST(matrix_array_container_copy_constructor_copies_all, passedTests, failedTests);
    RUN_TEST(matrix_array_container_assign_operator_copies_all, passedTests, failedTests);
    RUN_TEST(matrix_array_container_copy_constructor_passing_transposed_copies_all, passedTests, failedTests);
    RUN_TEST(matrix_array_container_assign_operator_passing_transposed_copies_all, passedTests, failedTests);
    RUN_TEST(matrix_array_container_copy_constructor_copies_by_value, passedTests, failedTests);
    RUN_TEST(matrix_array_container_assign_operator_copies_by_value, passedTests, failedTests);
    RUN_TEST(matrix_array_container_storedElementsCount, passedTests, failedTests);
    RUN_TEST(matrix_array_container_array_container_dot, passedTests, failedTests);
    RUN_TEST(matrix_array_container_array_container_dot_doesnt_change_vectors_values, passedTests, failedTests);
    RUN_TEST(matrix_array_container_array_container_multiplication, passedTests, failedTests);
    RUN_TEST(matrix_array_container_array_container_multiplication_doesnt_change_matrices_values, passedTests, failedTests);

    /* ------------ Map container tests --------------- */
    RUN_TEST(matrix_map_container_Creation, passedTests, failedTests);
    RUN_TEST(matrix_map_container_Get_Size, passedTests, failedTests);
    RUN_TEST(matrix_map_container_Get_Number_Of_Rows, passedTests, failedTests);
    RUN_TEST(matrix_map_container_Get_Number_Of_Columns, passedTests, failedTests);
    //RUN_TEST(matrix_map_container_Get_Number_Of_Rows_Of_Logic_Transposed, passedTests, failedTests);
    RUN_TEST(matrix_map_container_Get_Number_Of_Rows_Of_Transposed, passedTests, failedTests);
    //RUN_TEST(matrix_map_container_Get_Number_Of_Columns_Of_Logic_Transposed, passedTests, failedTests);
    RUN_TEST(matrix_map_container_Get_Number_Of_Columns_Of_Transposed, passedTests, failedTests);
    RUN_TEST(matrix_map_container_at_in_uninitialized_matrix, passedTests, failedTests);
    //RUN_TEST(matrix_map_container_isTransposed_rvalue, passedTests, failedTests);
    //RUN_TEST(matrix_map_container_isTransposed_lvalue, passedTests, failedTests);
    RUN_TEST(matrix_map_container_set_value_at_and_check, passedTests, failedTests);
    //RUN_TEST(matrix_map_container_set_value_at_and_check_logic_transposed, passedTests, failedTests);
    RUN_TEST(matrix_map_container_set_value_at_and_check_transposed, passedTests, failedTests);
    RUN_TEST(matrix_map_container_retrieveAt, passedTests, failedTests);
    //RUN_TEST(matrix_map_container_retrieveAt_logic_transposed, passedTests, failedTests);
    RUN_TEST(matrix_map_container_retrieveAt_transposed, passedTests, failedTests);
    RUN_TEST(matrix_map_container_insertAt_and_check, passedTests, failedTests);
    //RUN_TEST(matrix_map_container_insertAt_and_check_logic_transposed, passedTests, failedTests);
    RUN_TEST(matrix_map_container_insertAt_and_check_transposed, passedTests, failedTests);
    
    cout << endl << "-----------------" << endl;
    cout << "Total tests: " << passedTests +  failedTests << endl;
    cout << "Passed tests: " << passedTests << endl;
    cout << "Total tests: " << failedTests << endl;
    return 0;
}

/* ------------ Array container tests --------------- */

bool matrix_array_container_Creation(){
    Matrix<float,1,2> mat;
    return true;
}

bool matrix_array_container_Get_Size(){
    Matrix<float,1,2> mat;

    return mat.size()==2;
}

bool matrix_array_container_Get_Number_Of_Rows(){
    Matrix<float,3,2> mat;
    return mat.rows() == 3;
}

bool matrix_array_container_Get_Number_Of_Columns(){
    Matrix<float,3,2> mat;
    return mat.columns() == 2;
}

/*bool matrix_array_container_Get_Number_Of_Rows_Of_Logic_Transposed(){
    return Matrix<float,3,2>().logicTransposed().rows() == 2;
}*/

bool matrix_array_container_Get_Number_Of_Rows_Of_Transposed(){
    return Matrix<float,3,2>().transposed<float[3]>().rows() == 2;
}

/*bool matrix_array_container_Get_Number_Of_Columns_Of_Logic_Transposed(){
    return Matrix<float,3,2>().logicTransposed().columns() == 3;
}*/

bool matrix_array_container_Get_Number_Of_Columns_Of_Transposed(){
    return Matrix<float,3,2>().transposed<float[3]>().columns() == 3;
}

bool matrix_array_container_at_in_uninitialized_matrix(){
    bool ok =true;
    Matrix<float,3,2> mat;
    for(int i=0; i < 3 && ok; ++i){
        for(int j=0; j < 2 && ok; ++j){
            ok = mat.at(i,j) == 0.0f;
        }
    }
    return ok;
}
/*
bool matrix_array_container_isTransposed_rvalue(){
    bool ok = Matrix<float,3,2>().logicTransposed().isTransposed();
    return ok;
}

bool matrix_array_container_isTransposed_lvalue(){
    Matrix<float,3,2> mat;
    bool ok1 = !mat.isTransposed();
    Matrix<float,3,2> matTranp = mat.logicTransposed();
    bool ok2 = matTranp.isTransposed();
    bool ok3 = !mat.isTransposed();

    return ok1 && ok2 && ok3;
}
*/
bool matrix_array_container_set_value_at_and_check(){
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
/*
bool matrix_array_container_set_value_at_and_check_logic_transposed(){
    bool ok =true;
    Matrix<float,3,2> mat;
    mat.at(2,1)= 21.0f;
    mat.at(1,0)= 10.0f;
    Matrix<float,3,2> mat2 = mat.logicTransposed();
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
}*/

bool matrix_array_container_set_value_at_and_check_transposed(){
    bool ok =true;
    Matrix<float,3,2> mat;
    mat.at(2,1)= 21.0f;
    mat.at(1,0)= 10.0f;
    Matrix<float,2,3> mat2 = mat.transposed<float[3]>();
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

bool matrix_array_container_retrieveAt(){
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
/*
bool matrix_array_container_retrieveAt_logic_transposed(){
    bool ok =true;
    Matrix<float,3,2> mat;
    mat.at(2,1)= 21.0f;
    mat.at(1,0)= 10.0f;
    Matrix<float,3,2> mat2 = mat.logicTransposed();
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
*/
bool matrix_array_container_retrieveAt_transposed(){
    bool ok =true;
    Matrix<float,3,2> mat;
    mat.at(2,1)= 21.0f;
    mat.at(1,0)= 10.0f;
    Matrix<float,2,3> mat2 = mat.transposed<float[3]>();
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

bool matrix_array_container_insertAt_and_check(){
    bool ok =true;
    Matrix<float,3,2> mat;
    mat.insertValueAtRowColumn(21.0f,2,1);
    mat.insertValueAtRowColumn(10.0f,1,0);
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
/*
bool matrix_array_container_insertAt_and_check_logic_transposed(){
    bool ok =true;
    Matrix<float,3,2> mat;
    mat.insertValueAtRowColumn(21.0f,2,1);
    mat.insertValueAtRowColumn(10.0f,1,0);
    Matrix<float,3,2> mat2 = mat.logicTransposed();
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
}*/
bool matrix_array_container_insertAt_and_check_transposed(){
    bool ok =true;
    Matrix<float,3,2> mat;
    mat.insertValueAtRowColumn(21.0f,2,1);
    mat.insertValueAtRowColumn(10.0f,1,0);
    Matrix<float,2,3> mat2 = mat.transposed<float[3]>();
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

bool matrix_array_container_copy_constructor_copies_all(){
    bool ok = true;
    Matrix<float,4,5> mat1;
    mat1.at(0,0) = 1.0f;
    mat1.insertValueAtRowColumn(34.0f,3,4);
    Matrix<float,4,5> matCopy(mat1);

    ok =    (mat1.size() == matCopy.size()) &&
            (mat1.rows() == matCopy.rows()) &&
            (mat1.columns() == matCopy.columns())/*&&
            (mat1.isTransposed() == matCopy.isTransposed())*/;
    
    for(int i=0; i < 4 && ok; ++i){
        for(int j=0; j < 5 && ok; ++j){
            ok = (mat1.retrieveAt(i,j) == matCopy.retrieveAt(i,j));
        }
    }

    return ok;
}

bool matrix_array_container_assign_operator_copies_all(){
    bool ok = true;
    Matrix<float,4,5> mat1;
    mat1.at(0,0) = 1.0f;
    mat1.insertValueAtRowColumn(34.0f,3,4);
    Matrix<float,4,5> matCopy;
    matCopy.at(2,2) = 22.0f;
    matCopy = mat1;

    ok =    (mat1.size() == matCopy.size()) &&
            (mat1.rows() == matCopy.rows()) &&
            (mat1.columns() == matCopy.columns())/* &&
            (mat1.isTransposed() == matCopy.isTransposed())*/;
    
    for(int i=0; i < 4 && ok; ++i){
        for(int j=0; j < 5 && ok; ++j){
            ok = (mat1.retrieveAt(i,j) == matCopy.retrieveAt(i,j));
        }
    }

    return ok;
}

bool matrix_array_container_copy_constructor_passing_transposed_copies_all(){
    bool ok = true;
    Matrix<float,4,5> mat1;
    mat1.at(0,0) = 1.0f;
    mat1.insertValueAtRowColumn(34.0f,3,4);
    //Matrix<float,4,5> matCopy(mat1.logicTransposed());
    Matrix<float,5,4> matCopy(mat1.transposed<float[4]>());

    ok =    (mat1.size() == matCopy.size()) &&
            (mat1.rows() == matCopy.columns()) &&
            (mat1.columns() == matCopy.rows())/* &&
            (mat1.isTransposed() == !matCopy.isTransposed())*/;
    
    for(int i=0; i < 4 && ok; ++i){
        for(int j=0; j < 5 && ok; ++j){
            ok = (mat1.retrieveAt(i,j) == matCopy.retrieveAt(j,i));
        }
    }

    return ok;
}

bool matrix_array_container_assign_operator_passing_transposed_copies_all(){
    bool ok = true;
    Matrix<float,4,5> mat1;
    mat1.at(0,0) = 1.0f;
    mat1.insertValueAtRowColumn(34.0f,3,4);
    Matrix<float,5,4> matCopy;
    matCopy.at(2,2) = 22.0f;
    //matCopy = mat1.logicTransposed();
    matCopy = mat1.transposed<float[4]>();

    ok =    (mat1.size() == matCopy.size()) &&
            (mat1.rows() == matCopy.columns()) &&
            (mat1.columns() == matCopy.rows()) /*&&
            (mat1.isTransposed() == !matCopy.isTransposed())*/;
    
    for(int i=0; i < 4 && ok; ++i){
        for(int j=0; j < 5 && ok; ++j){
            ok = (mat1.retrieveAt(i,j) == matCopy.retrieveAt(j,i));
        }
    }

    return ok;
}

bool matrix_array_container_copy_constructor_copies_by_value(){
    bool ok = true;
    Matrix<float,4,5> mat1;
    mat1.at(0,0) = 1.0f;
    mat1.insertValueAtRowColumn(34.0f,3,4);
    Matrix<float,4,5> matCopy(mat1);
    matCopy.at(0,0) = 200.0f;
    matCopy.insertValueAtRowColumn(800.0f,3,4);

    for(int i=0; i < 4 && ok; ++i){
        for(int j=0; j < 5 && ok; ++j){
            if(i == 0 && j == 0){
                ok = (mat1.retrieveAt(i,j) == 1.0f) && (matCopy.retrieveAt(i,j) == 200.0f);
            }
            else if(i == 3 && j == 4){
                ok = (mat1.retrieveAt(i,j) == 34.0f) && (matCopy.retrieveAt(i,j) == 800.0f);
            }
            else{
                ok = (mat1.retrieveAt(i,j) == 0.0f) && (matCopy.retrieveAt(i,j) == 0.0f);
            }
        }
    }

    return ok;
}

bool matrix_array_container_assign_operator_copies_by_value(){
    bool ok = true;
    Matrix<float,4,5> mat1;
    mat1.at(0,0) = 1.0f;
    mat1.insertValueAtRowColumn(34.0f,3,4);
    Matrix<float,4,5> matCopy;
    matCopy.at(2,2) = 22.0f;
    matCopy = mat1;
    matCopy.at(0,0) = 200.0f;
    matCopy.insertValueAtRowColumn(800.0f,3,4);

    for(int i=0; i < 4 && ok; ++i){
        for(int j=0; j < 5 && ok; ++j){
            if(i == 0 && j == 0){
                ok = (mat1.retrieveAt(i,j) == 1.0f) && (matCopy.retrieveAt(i,j) == 200.0f);
            }
            else if(i == 3 && j == 4){
                ok = (mat1.retrieveAt(i,j) == 34.0f) && (matCopy.retrieveAt(i,j) == 800.0f);
            }
            else{
                ok = (mat1.retrieveAt(i,j) == 0.0f) && (matCopy.retrieveAt(i,j) == 0.0f);
            }
        }
    }

    return ok;
}

bool matrix_array_container_storedElementsCount(){
    Matrix<float,4,5> mat1;

    return mat1.storedElementsCount() == 20;
}

bool matrix_array_container_array_container_dot(){
    Matrix<float,1,5> mat1;
    Matrix<float,1,5> mat2;

    mat1.at(0,0) = 2.0f;
    mat2.at(0,0) = 5.0f;

    mat1.at(0,2) = 8.0f;

    mat2.at(0,3) = 15.0f;

    mat1.at(0,4) = 13.0f;
    mat2.at(0,4) = 10.0f;

    return dot(mat1,mat2) == 140.0f;
}

bool matrix_array_container_array_container_dot_doesnt_change_vectors_values(){
    bool ok = true;
    Matrix<float,1,5> mat1;
    Matrix<float,1,5> mat2;

    mat1.at(0,0) = 2.0f;
    mat2.at(0,0) = 5.0f;

    mat1.at(0,2) = 8.0f;

    mat2.at(0,3) = 15.0f;

    mat1.at(0,4) = 13.0f;
    mat2.at(0,4) = 10.0f;

    float dotVal = dot(mat1,mat2);

    ok = (dotVal == 140.0f);

    for(int j=0; j < 5 && ok; ++j){
        if(j == 0){
            ok = (mat1.retrieveAt(0,j) == 2.0f) && (mat2.retrieveAt(0,j) == 5.0f);
        }
        else if(j == 2){
            ok = (mat1.retrieveAt(0,j) == 8.0f) && (mat2.retrieveAt(0,j) == 0.0f);
        }
        else if(j == 3){
            ok = (mat1.retrieveAt(0,j) == 0.0f) && (mat2.retrieveAt(0,j) == 15.0f);
        }
        else if(j == 4){
            ok = (mat1.retrieveAt(0,j) == 13.0f) && (mat2.retrieveAt(0,j) == 10.0f);
        }
        else{
            ok = (mat1.retrieveAt(0,j) == 0.0f) && (mat2.retrieveAt(0,j) == 0.0f);
        }
    }

    return ok;
}

bool matrix_array_container_array_container_multiplication(){
    bool ok = false;
    Matrix<float,2,3> mat1;
    Matrix<float,3,1> mat2;

    mat1.at(0,0) = 2.0f; mat1.at(0,1) = 3.0f; mat1.at(0,2) = 4.0f;
    mat1.at(1,0) = 5.0f; mat1.at(1,1) = 6.0f; mat1.at(1,2) = 7.0f;

    mat2.at(0,0) = 9.0f;
    mat2.at(1,0) = 8.0f;
    mat2.at(2,0) = 7.0f;

    Matrix<float,2,1> mat3 = mat1*mat2;

    ok = (  mat3.retrieveAt(0,0) == 70.0f &&
            mat3.retrieveAt(1,0) == 142.0f);
    

    return ok;
}

bool matrix_array_container_array_container_multiplication_doesnt_change_matrices_values(){
    bool ok = false;
    Matrix<float,2,3> mat1;
    Matrix<float,3,1> mat2;

    mat1.at(0,0) = 2.0f; mat1.at(0,1) = 3.0f; mat1.at(0,2) = 4.0f;
    mat1.at(1,0) = 5.0f; mat1.at(1,1) = 6.0f; mat1.at(1,2) = 7.0f;

    mat2.at(0,0) = 9.0f;
    mat2.at(1,0) = 8.0f;
    mat2.at(2,0) = 7.0f;

    Matrix<float,2,1> mat3 = mat1*mat2;

    ok = (  mat1.retrieveAt(0,0) == 2.0f && mat1.retrieveAt(0,1) == 3.0f && mat1.retrieveAt(0,2) == 4.0f &&
            mat1.retrieveAt(1,0) == 5.0f && mat1.retrieveAt(1,1) == 6.0f && mat1.retrieveAt(1,2) == 7.0f &&
            mat2.retrieveAt(0,0) == 9.0f &&
            mat2.retrieveAt(1,0) == 8.0f &&
            mat2.retrieveAt(2,0) == 7.0f &&
            mat3.retrieveAt(0,0) == 70.0f &&
            mat3.retrieveAt(1,0) == 142.0f);
    

    return ok;
}

/* ------------ Map container tests --------------- */

bool matrix_map_container_Creation(){
    Matrix<float,1, 2, std::map<size_t, float>> mat;
    return true;
}

bool matrix_map_container_Get_Size(){
    Matrix<float,1,2, std::map<size_t, float>> mat;

    return mat.size()==2;
}

bool matrix_map_container_Get_Number_Of_Rows(){
    Matrix<float,3,2, std::map<size_t, float>> mat;
    return mat.rows() == 3;
}

bool matrix_map_container_Get_Number_Of_Columns(){
    Matrix<float,3,2, std::map<size_t, float>> mat;
    return mat.columns() == 2;
}

//bool matrix_map_container_Get_Number_Of_Rows_Of_Logic_Transposed();

bool matrix_map_container_Get_Number_Of_Rows_Of_Transposed(){
    return Matrix<float,3,2, std::map<size_t, float>>().transposed<std::map<size_t, float>>().rows() == 2;
}

//bool matrix_map_container_Get_Number_Of_Columns_Of_Logic_Transposed();

bool matrix_map_container_Get_Number_Of_Columns_Of_Transposed(){
    return Matrix<float,3,2, std::map<size_t, float>>().transposed<std::map<size_t, float>>().columns() == 3;
}

bool matrix_map_container_at_in_uninitialized_matrix(){
    bool ok =true;
    Matrix<float,3,2, std::map<size_t, float>> mat;
    for(int i=0; i < 3 && ok; ++i){
        for(int j=0; j < 2 && ok; ++j){
            ok = mat.at(i,j) == 0.0f;
        }
    }
    return ok;
}
//bool matrix_map_container_isTransposed_rvalue();
//bool matrix_map_container_isTransposed_lvalue();

bool matrix_map_container_set_value_at_and_check(){
    bool ok =true;
    Matrix<float,3,2, map<size_t, float>> mat;
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
/*
bool matrix_map_container_set_value_at_and_check_logic_transposed(){
    bool ok =true;
    Matrix<float,3,2, map<size_t, float>> mat;
    mat.at(2,1)= 21.0f;
    mat.at(1,0)= 10.0f;
    Matrix<float,3,2> mat2 = mat.logicTransposed();
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
}*/

bool matrix_map_container_set_value_at_and_check_transposed(){
    bool ok =true;
    Matrix<float,3,2> mat;
    mat.at(2,1)= 21.0f;
    mat.at(1,0)= 10.0f;
    Matrix<float,2,3, map<size_t, float>> mat2 = mat.transposed<map<size_t, float>>();
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

bool matrix_map_container_retrieveAt(){
    bool ok =true;
    Matrix<float,3,2, map<size_t, float>> mat;
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
/*
bool matrix_map_container_retrieveAt_logic_transposed(){
    bool ok =true;
    Matrix<float,3,2, map<size_t, float>> mat;
    mat.at(2,1)= 21.0f;
    mat.at(1,0)= 10.0f;
    Matrix<float,3,2, map<size_t, float>> mat2 = mat.logicTransposed();
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
*/
bool matrix_map_container_retrieveAt_transposed(){
    bool ok =true;
    Matrix<float,3,2, map<size_t, float>> mat;
    mat.at(2,1)= 21.0f;
    mat.at(1,0)= 10.0f;
    Matrix<float,2,3, map<size_t, float>> mat2 = mat.transposed<map<size_t, float>>();
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

bool matrix_map_container_insertAt_and_check(){
    bool ok =true;
    Matrix<float,3,2, map<size_t, float>> mat;
    mat.insertValueAtRowColumn(21.0f,2,1);
    mat.insertValueAtRowColumn(10.0f,1,0);
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
/*
bool matrix_map_container_insertAt_and_check_logic_transposed(){
    bool ok =true;
    Matrix<float,3,2, map<size_t, float>> mat;
    mat.insertValueAtRowColumn(21.0f,2,1);
    mat.insertValueAtRowColumn(10.0f,1,0);
    Matrix<float,3,2, map<size_t, float>> mat2 = mat.logicTransposed();
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
}*/
bool matrix_map_container_insertAt_and_check_transposed(){
    bool ok =true;
    Matrix<float,3,2, map<size_t, float>> mat;
    mat.insertValueAtRowColumn(21.0f,2,1);
    mat.insertValueAtRowColumn(10.0f,1,0);
    Matrix<float,2,3, map<size_t, float>> mat2 = mat.transposed<map<size_t, float>>();
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