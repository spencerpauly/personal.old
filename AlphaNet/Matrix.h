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

        //Mutators
        void setMatrix(int rPos, int cPos, double value);

        //Accessors
        int getRow();
        int getCol();
        std::vector< std::vector<double> > getMatrix(); //Should be re-looked at when it's actually needed




};

#endif // MATRIX_H
