
#include "PrecondViolatedExcep.h"
#include "Matrix.h"

class Matrix;

using namespace std;

bool MatrixTools::canAdd(Matrix m1, Matrix m2) {

    if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols() ) {
        string message("MatrixTools::add() called with invalid Matrices. ");
        throw PrecondViolatedExcep(message);
    }

    return true;
}

bool MatrixTools::canMult(Matrix m1, Matrix m2) {

    if (m1.getCols() != m2.getRows() ) {
        string message("MatrixTools::mult() called with invalid Matrices of size: ");
        message += to_string(m1.getRows());
        message += "x";
        message += to_string(m1.getCols());
        message += " & ";
        message += to_string(m2.getRows());
        message += "x";
        message += to_string(m2.getCols());

        throw PrecondViolatedExcep(message);
    }

    return true;
}

bool MatrixTools::canScalarMult(Matrix m1, Matrix m2) {

    if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols() ) {
        string message("MatrixTools::scalarMult() called with invalid Matrices. ");
        throw PrecondViolatedExcep(message);
    }

    return true;
}

Matrix MatrixTools::add(Matrix m1, Matrix m2) {

    canAdd(m1,m2);

    Matrix newMatrix(m1.getRows(), m1.getCols() );

    for (int i = 0; i < m1.getRows(); i++) {
        for (int j = 0; j < m1.getCols(); j++) {
            double newVal = m1.getValue(i,j) + m2.getValue(i,j);

            newMatrix.setValue(i,j, newVal);
        }
    }
    return newMatrix;

}

Matrix MatrixTools::mult(Matrix m1, Matrix m2) {

    canMult(m1,m2);

    Matrix newMatrix(m1.getRows(), m2.getCols() );
    newMatrix.setAll(0);

    double newVal(0);

    //Loop through the # of rows of Matrix1
    for (int i = 0; i < m1.getRows(); i++) {
        //Loop through # of cols of Matrix2
        for (int j = 0; j < m2.getCols(); j++) {
            //Loop through # of cols of Matrix1
            for (int k = 0; k < m1.getCols(); k++) {
                newVal = m1.getValue(i,k) * m2.getValue(k,j);

                newMatrix.setValue(i,j, newMatrix.getValue(i,j) + newVal);
            }
        }
    }

    return newMatrix;

}

Matrix MatrixTools::scalarMult(Matrix m1, Matrix m2) {

    canScalarMult(m1,m2);

    Matrix newMatrix(m1.getRows(), m1.getCols() );

    for (int i = 0; i < m1.getRows(); i++) {
        for (int j = 0; j < m1.getCols(); j++) {
            double newVal = m1.getValue(i,j) * m2.getValue(i,j);

            newMatrix.setValue(i,j, newVal);
        }
    }
    return newMatrix;
}

Matrix MatrixTools::intAdd(Matrix m1, int num) {

    Matrix newMatrix(m1.getRows(), m1.getCols() );

    for (int i = 0; i < m1.getRows(); i++) {
        for (int j = 0; j < m1.getCols(); j++) {
            double newVal = m1.getValue(i,j) + num;

            newMatrix.setValue(i,j, newVal);
        }
    }
    return newMatrix;
}



Matrix MatrixTools::sigmoid(Matrix old, bool deriv = false) {

    int rows = old.getRows();
    int cols = old.getCols();

    Matrix newMatrix(rows, cols);

    double oldVal;
    double newVal;
    
    if (deriv == true) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                oldVal = old.getValue(i,j);
                newVal = oldVal * (1-oldVal);
                newMatrix.setValue(i, j, newVal);
            }
        }
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                oldVal = old.getValue(i,j);
                newVal =  (1 / (1 + pow(e,-oldVal)));
                newMatrix.setValue(i, j, newVal);
            }
        }
    }

    return newMatrix;
}

Matrix MatrixTools::transpose(Matrix oldMatrix) {

    int rows = oldMatrix.getRows();
    int cols = oldMatrix.getCols();

    Matrix newMatrix(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newMatrix.setValue(j, i, oldMatrix.getValue(i,j));
        }
    }

    return newMatrix;
}
