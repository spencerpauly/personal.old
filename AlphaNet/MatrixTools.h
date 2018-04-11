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
        bool canAdd(Matrix m1, Matrix m2);
        bool canSubtract(Matrix m1, Matrix m2);
    public:
        //Constructors
        MatrixMath(){};

        //Matrix& mult(const Matrix& m1, const Matrix& m2);
        Matrix add(Matrix m1, Matrix m2);
        //Matrix& subtract(const Matrix& m1, const Matrix& m2);
        
        //Matrix scalarAdd(const Matrix& m1, const double val);
        //Matrix scalarSubtract(const Matrix& m1, const double val);

        //Matrix inverse(const Matrix& m1);


        //Mutators


        //Accessors

};

#endif // MATRIXTOOLS_H
