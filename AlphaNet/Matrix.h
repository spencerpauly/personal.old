#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

//Matrix Class

class Matrix {
    private:
        int name;
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
        bool copy(Matrix& result); 
        bool canAdd(Matrix& m2);
        bool canSubtract(Matrix& m2);
        bool canMult(Matrix& m2);
        bool add(Matrix& m2, Matrix& result);
        bool subtract(Matrix& m2, Matrix& result);
        bool mult(Matrix& m2, Matrix& result);
        void clear();




        //Mutators
        void setMatrix(int rPos, int cPos, double value);
        void setRows(int newRowCount);
        void setCols(int newColCount);

        //Accessors
        int getRow();
        int getCol();
        std::vector< std::vector<double> > getMatrix(); //Should be re-looked at when it's actually needed




};

#endif // MATRIX_H
