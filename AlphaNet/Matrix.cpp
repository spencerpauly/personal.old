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

/*
<-------------------------------------------------------------->
      __  __       _        _           _____ _
     |  \/  |     | |      (_)         / ____| |
     | \  / | __ _| |_ _ __ ___  __   | |    | | __ _ ___ ___
     | |\/| |/ _` | __| '__| \ \/ /   | |    | |/ _` / __/ __|
     | |  | | (_| | |_| |  | |>  <    | |____| | (_| \__ \__ \
     |_|  |_|\__,_|\__|_|  |_/_/\_\    \_____|_|\__,_|___/___/

 <-------------------------------------------------------------->
*/

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

//Methods
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
    if (row == m2.getCols()) //Check if the rows of the 1st matrix will multiply with the columns of the 2nd
        return true;
    //if not true then...
    return false;

}
bool Matrix::add(Matrix& m2, Matrix& result) {

}
bool Matrix::subtract(Matrix& m2, Matrix& result) {
    return true;

}
bool Matrix::mult(Matrix& m2, Matrix& result) {
    if (!canMult(m2)) {
        return false;
    } else {
        //Loop through the # of columns of Matrix1
        for (int i = 0; i < row; i++) {
            //Loop through # of rows of Matrix2
            for (int j = 0; j < m2.getCols(); j++) {
                //Loop through # of rows of Matrix1
                for (int k = 0; k < row; k++) {
                    result.setRows(i);
                    result.setCols(j);

                    double newVal = result.getValue(i,j) + ((matrix[i][k]) * (m2.getValue(k,j)));

                    result.setMatrix(i,j, newVal);
                    //result[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        return true;
    }
}

bool Matrix::multIdentity(Matrix& result) {
    //Create identity matrix
    Matrix identity(row, row);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (i == j) {
                identity.setMatrix(i,j,1);
            } else {
                identity.setMatrix(i,j,0);
            }
        }
    }
    identity.print();
    return mult(identity, result);
}





//Mutators
void Matrix::setMatrix(int rPos, int cPos, double value) {
    matrix[rPos][cPos] = value;
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


std::vector< std::vector<double> > Matrix::getMatrix() {
    return matrix;
}





