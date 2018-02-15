#ifndef MATRIXMATH_H
#define MATRIXMATH_H

#include <vector>
using namespace std;

//MatrixMath Class

class MatrixMath {
    private:

    public:
        //Constructors
        MatrixMath(){};

        //Methods
        void add(std::vector< std::vector<double> >& m1, std::vector< std::vector<double> >& m2);
        void mult(std::vector< std::vector<double> >& m1, std::vector< std::vector<double> >& m2, std::vector< std::vector<double> >& output);

        bool canAdd(std::vector< std::vector<double> >& m1, std::vector< std::vector<double> >& m2);
        bool canMult(std::vector< std::vector<double> >& m1, std::vector< std::vector<double> >& m2);

        //Mutators


        //Accessors

};

#endif // MATRIXMATH_H
