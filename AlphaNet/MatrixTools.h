#ifndef MATRIXTOOLS_H
#define MATRIXTOOLS_H

#include <vector>
using namespace std;

//MatrixTools Class

class MatrixTools {
    private:
        canAdd();
        canSubtract();
        canMult();
    public:
        //Constructors
        MatrixMath(){};

        //Methods
        /*
        void add(std::vector< std::vector<double> >& m1, std::vector< std::vector<double> >& m2);
        void mult(std::vector< std::vector<double> >& m1, std::vector< std::vector<double> >& m2, std::vector< std::vector<double> >& output);

        bool canAdd(std::vector< std::vector<double> >& m1, std::vector< std::vector<double> >& m2);
        bool canMult(std::vector< std::vector<double> >& m1, std::vector< std::vector<double> >& m2);
        */

        mult();
        inverse();
        subtract();
        add();
        scalarAdd();

        //Mutators


        //Accessors

};

#endif // MATRIXTOOLS_H
