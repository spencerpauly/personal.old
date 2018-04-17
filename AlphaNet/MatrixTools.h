#ifndef MATRIXTOOLS_H
#define MATRIXTOOLS_H

#include <vector>
#include "Matrix.h"

class Matrix;

using namespace std;

//MatrixTools Class

class MatrixTools {
    private:
        bool canMult(Matrix m1, Matrix m2);
        bool canScalarMult(Matrix m1, Matrix m2);
        bool canAdd(Matrix m1, Matrix m2);
        bool canSubtract(Matrix m1, Matrix m2);

        const double e = 2.71828182845904523536;


    public:
        //Constructors
        MatrixMath(){};

        //Methods
        Matrix mult(Matrix m1, Matrix m2);
        Matrix add(Matrix m1, Matrix m2);
        Matrix scalarMult(Matrix m1, Matrix m2);
        Matrix intAdd(Matrix m1, int num);

        
        Matrix sigmoid(Matrix oldMatrix, bool deriv);
        Matrix transpose(Matrix oldMatrix);
        //Matrix subtract(Matrix m1, Matrix m2);
        
        //Matrix scalarAdd(const Matrix m1, double val);
        //Matrix scalarSubtract(const Matrix m1, double val);

};

#include "MatrixTools.cpp"

#endif // MATRIXTOOLS_H
