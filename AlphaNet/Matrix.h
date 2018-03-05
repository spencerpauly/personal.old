#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

//Matrix Class

class Matrix {
    private:
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
        bool copy(Matrix& result); 

        bool canAdd(Matrix& m2);
        bool canSubtract(Matrix& m2); //stub
        bool canMult(Matrix& m2);
        bool add(Matrix& m2, Matrix& result);
        bool subtract(Matrix& m2, Matrix& result);
        bool mult(Matrix& m2, Matrix& result);

        bool multIdentity(Matrix& result);

        void addVal(int rPos, int cPos, double val);
        void multVal(int rPos, int cPos, double val);





        //Mutators
        void setMatrix(int rPos, int cPos, double value);
        void setRows(int newRowCount);
        void setCols(int newColCount);

        //Accessors
        int getRows();
        int getCols();
        double getValue(int rPos, int cPos);
        std::vector< std::vector<double> > getMatrix(); //Should be re-looked at when it's actually needed




};

#endif // MATRIX_H
