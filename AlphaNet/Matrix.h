#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using namespace std;


//Matrix Class

class Matrix {
    private:
        const double e = 2.71828182845904523536;
        int row;
        int col;
        std::vector< std::vector<double> > matrix; //2-Dimensional Vector

        bool resize(int newRows, int newCols);
        bool canMult(Matrix m2);
        bool canAdd(Matrix m2);
        bool canSubtract(Matrix m2);
    public:
        //Constructors
        Matrix();
        Matrix(int r, int c);

        //Methods
        void randomize();
        void randomize(int minVal, int maxVal);
        void print();
        void clear();

        bool vectorToMatrix(std::vector< std::vector<double> >  newMatrix, int arrayRows, int arrayCols);
        bool copy(Matrix fromMatrix);
        //array[] MatrixToArray();


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

        //Operator Overloads
        //Matrix operator+(Matrix rhs);
        Matrix operator*(Matrix rhs);

        void operator=(Matrix rhs);


};

#include "Matrix.cpp"


#endif // MATRIX_H
