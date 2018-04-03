#include "Matrix.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>


using namespace std;


//Constructors
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
    cout << endl;
}

//Methods

void Matrix::clear() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = 0;
        }
    }
    row = 0;
    col = 0;
}

bool Matrix::copy(Matrix& result) {
    return true;

}

bool Matrix::canAdd(Matrix& m2) {
    if (row == m2.getRows() && col == m2.getCols())
        return true;
    //if not true then...
    return false;
}

bool Matrix::canSubtract(Matrix& m2) { //stub
    return true;

}
bool Matrix::canMult(Matrix& m2) {
    if (col == m2.getRows()) //Check if the rows of the 1st matrix will multiply with the columns of the 2nd
        return true;
    //if not true then...
    return false;

}
bool Matrix::add(Matrix& m2, Matrix& result) {

}
bool Matrix::subtract(Matrix& m1, Matrix& m2) {
    //Impliment canSubtract here!
    for (int i = 0; i < m1.getRows(); i++) {
        for (int j = 0; j < m2.getCols(); j++) {
            matrix[i][j] = m1.getValue(i,j) - m2.getValue(i,j);
        }
    }
    return true;

}
bool Matrix::mult(Matrix& m2, Matrix& result) {
    if (!canMult(m2)) {
        return false;
    } else {
        result.setRows(row);
        result.setCols(m2.getCols());
        cout << "row: " << row << "col: " << m2.getCols() << endl;
        //Loop through the # of rows of Matrix1
        for (int i = 0; i < row; i++) {
            //Loop through # of cols of Matrix2
            for (int j = 0; j < m2.getCols(); j++) {
                //Loop through # of cols of Matrix1
                for (int k = 0; k < col; k++) {
                    double newVal = matrix[i][k] * m2.getValue(k,j);
                    //DEBUG
                    //cout << "new val [" << i << "][" << j << "] = " << newVal << endl;
                    result.addVal(i,j, newVal);
                }
            }
        }
        return true;
    }
}

bool Matrix::multTwo(Matrix& m1, Matrix& m2) {
    if (!m1.canMult(m2)) {
        return false;
    } else {
        row = (m1.getRows());
        col = (m2.getCols());
        cout << "row: " << m1.getRows() << "col: " << m2.getCols() << endl;
        //Loop through the # of rows of Matrix1
        for (int i = 0; i < m1.getRows(); i++) {
            //Loop through # of cols of Matrix2
            for (int j = 0; j < m2.getCols(); j++) {
                //Loop through # of cols of Matrix1
                for (int k = 0; k < m1.getCols(); k++) {
                    double newVal = m1.getValue(i,k) * m2.getValue(k,j);
                    //DEBUG
                    //cout << "new val [" << i << "][" << j << "] = " << newVal << endl;
                    matrix[i][j] += newVal;
                }
            }
        }
        return true;
    }

}


bool Matrix::multConst(double value) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] *= value;
        }
    }
}

bool Matrix::multIdentity(Matrix& result) {
    //Create identity matrix
    Matrix identity(col, col);
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < col; j++) {
            if (i == j) {
                identity.setMatrix(i,j,1);
            } else {
                identity.setMatrix(i,j,0);
            }
        }
    }
    identity.print();
    result.setRows(row);
    result.setCols(col);
    return mult(identity, result);
}

void Matrix::addVal(int rPos, int cPos, double val) {
    matrix[rPos][cPos] += val;
}

void Matrix::multVal(int rPos, int cPos, double val) {
    matrix[rPos][cPos] *= val;
}

void Matrix::sigmoid(bool deriv /* = false */) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            double x = matrix[i][j];
            if (deriv == true) {
                matrix[i][j] = (x * (1-x));
            } else {
                matrix[i][j] = (1/(1 + pow(e,-x)));
            }
        }
    }
}


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
    row = newRowCount;
}

void Matrix::setCols(int newColCount) {
    col = newColCount;
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

std::vector< std::vector<double> > Matrix::getMatrix() {
    return matrix;
}





