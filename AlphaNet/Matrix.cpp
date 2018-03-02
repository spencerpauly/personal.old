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


//Mutators
void Matrix::setMatrix(int rPos, int cPos, double value) {
    matrix[rPos][cPos] = value;
}


//Accessors
int Matrix::getRow() {
    return row;
}

int Matrix::getCol() {
    return col;
}

std::vector< std::vector<double> > Matrix::getMatrix() {
    return matrix;
}

