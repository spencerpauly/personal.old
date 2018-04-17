
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
        string message("MatrixTools::mult() called with invalid Matrices. ");
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
