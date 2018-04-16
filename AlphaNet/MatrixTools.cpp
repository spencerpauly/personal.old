
#include "PrecondViolatedExcep.cpp"
#include "Matrix.h"

class Matrix;

using namespace std;

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

bool MatrixTools::canAdd(Matrix m1, Matrix m2) {

    if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols() ) {
        string message("MatrixTools::add() called with invalid Matrices. ");
        throw PrecondViolatedExcep(message);
    }

    return true;
}
