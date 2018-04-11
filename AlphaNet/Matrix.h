#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "MatrixTools.h"

using namespace std;

//Matrix Class

class Matrix {
    private:
        const double e = 2.71828182845904523536;
        int row;
        int col;
        std::vector< std::vector<double> > matrix; //2-Dimensional Vector
    public:
        //Constructors
        Matrix(){}
        Matrix(int r, int c);

        //Methods
        void randomize();
        void randomize(int minVal, int maxVal);
        void print();
        void clear();

        bool vectorToMatrix(std::vector< std::vector<double> >  newMatrix, int arrayRows, int arrayCols);
        //array[] MatrixToArray();

        //bool canMult(Matrix& m2);
        //bool mult(Matrix& m2, Matrix& result);


        //Mutators
        void setMatrix(int rPos, int cPos, double value);
        void setAll(double value);
        void setRows(int newRowCount);
        void setCols(int newColCount);
        void setValue(int rPos, int cPos, double newValue);


        //Accessors
        int getRows();
        int getCols();
        double getValue(int rPos, int cPos);
        double getMean();
        //std::vector< std::vector<double> > getMatrix(); //Should be re-looked at when it's actually needed




};

#endif // MATRIX_H
