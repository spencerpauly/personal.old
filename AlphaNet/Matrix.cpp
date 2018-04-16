#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>

#include "PrecondViolatedExcep.h"

using namespace std;

//Constructors

Matrix::Matrix() {
    row = 0;
    col = 0;

}


Matrix::Matrix(int r, int c) {
    row = r;
    col = c;
    //Set # of rows for matrix
    matrix.resize(row);
    for (int i = 0; i < row; i++) {
        //Set # of columns for matrix
        matrix[i].resize(col);
    }
}

//Private Methods
bool Matrix::resize(int newRows, int newCols) {
    row = newRows;
    col = newCols;

    matrix.clear();

    //Set # of rows for matrix
    matrix.resize(row);
    for (int i = 0; i < row; i++) {
        //Set # of columns for matrix
        matrix[i].resize(col);
    }
}  

bool Matrix::canAdd(Matrix m2) {

    if (row != m2.getRows() || col != m2.getCols() ) {
        string message("MatrixTools::add() called with invalid Matrices. ");
        throw PrecondViolatedExcep(message);
    }

    return true;
}



//Debug Methods
void Matrix::randomize() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void Matrix::randomize(int minVal, int maxVal) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = (rand() % (maxVal-minVal)) + minVal; //Does not work with doubles
        }
    }
}

void Matrix::print() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//Methods

void Matrix::clear() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = 0;
        }
    }
    resize(0,0);
}

bool Matrix::vectorToMatrix(std::vector< std::vector<double> >  newMatrix, int arrayRows, int arrayCols) {
    resize(arrayRows, arrayCols);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = newMatrix[i][j];
        }
    }
}


// const Matrix operator*(const Matrix& lhs,
//                          const Matrix& rhs) {

//    return this.mult(rhs,lhs);
// }


// Matrix Matrix::mult(Matrix& m1, Matrix& m2) {
//     if (canMult(m1,m2)) {
//         result.setRows(row);
//         result.setCols(m2.getCols());
//         cout << "row: " << row << "col: " << m2.getCols() << endl;
//         //Loop through the # of rows of Matrix1
//         for (int i = 0; i < row; i++) {
//             //Loop through # of cols of Matrix2
//             for (int j = 0; j < m2.getCols(); j++) {
//                 //Loop through # of cols of Matrix1
//                 for (int k = 0; k < col; k++) {
//                     double newVal = matrix[i][k] * m2.getValue(k,j);
//                     //DEBUG
//                     //cout << "new val [" << i << "][" << j << "] = " << newVal << endl;
//                     result.addVal(i,j, newVal);
//                 }
//             }
//         }
//         return true;
//     }
// }

//Mutators
void Matrix::setMatrix(int rPos, int cPos, double value) {
    matrix[rPos][cPos] = value;
}

void Matrix::setAll(double value) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = value;
        }
    }
}

void Matrix::setRows(int newRowCount) {
    resize(newRowCount, col);
}

void Matrix::setCols(int newColCount) {
    resize(row, newColCount);
}

void Matrix::setValue(int rPos, int cPos, double newValue) {
    matrix[rPos][cPos] = newValue;
}


//Accessors
int Matrix::getRows() {
    return row;
}

int Matrix::getCols() {
    return col;
}

double Matrix::getValue(int rPos, int cPos) {
    return matrix[rPos][cPos];
}

double Matrix::getMean() {
    double mean = 0;
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            count++;
            mean += matrix[i][j];
        }
    }
    mean = mean/count;
    return mean;
}

// std::vector< std::vector<double> > Matrix::getMatrix() {
//     return matrix;
// }

bool Matrix::copy(Matrix fromMatrix) {
    resize(fromMatrix.getRows(), fromMatrix.getCols() );
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = fromMatrix.getValue(i, j);
        }
    }
}

//Operator Overloads
Matrix Matrix::operator+(Matrix rhs) {
    canAdd(rhs);

    Matrix newMatrix(row, col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            double newVal = matrix[i][j] + rhs.getValue(i,j);

            newMatrix.setValue(i,j, newVal);
        }
    }

    return newMatrix;
}

// Matrix Matrix::operator*(Matrix rhs) {
//     canMult(rhs);

//     Matrix newMatrix(row, rhs.getCols() );

//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//             double newVal = matrix[i][j] + rhs.getValue(i,j);

//             newMatrix.setValue(i,j, newVal);
//         }
//     }

//     return newMatrix;
// }

void Matrix::operator=(Matrix rhs) {
    copy(rhs);
}




