#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>

#include "Matrix.h"
#include "MatrixTools.h"

using namespace std;

//Global Variables
std::vector< std::vector<double> > testData1 = { {4,0,4},
                                            {0,4,0},
                                            {2,2,2} };

std::vector< std::vector<double> > testData2 = { {1,2,3,1,1},
                                                 {9,3,5,1,1},
                                                 {3,4,1,1,1} };

//Headers
bool testMatrixAdd();
bool testMatrixMult();
bool testMatrixToolsAdd();
bool testMatrixToolsMult();




//Implementations
bool testMatrixAdd() {

    MatrixTools mt;

    Matrix m1;
    m1.vectorToMatrix(testData1, 3, 3);
    m1.print();

    cout << "  *" << endl;

    Matrix m2;
    m2.vectorToMatrix(testData2, 3, 3);
    m2.print();

    cout << "  ="  << endl;

    Matrix m3;
    m3 = mt.mult(m1,m2);
    m3.print();

    return 0;
}

bool testMatrixMult() {

    MatrixTools mt;

    Matrix m1;
    m1.vectorToMatrix(testData1, 3, 3);
    m1.print();

    cout << "  *" << endl;

    Matrix m2;
    m2.vectorToMatrix(testData2, 3, 5);
    m2.print();

    cout << "  ="  << endl;

    Matrix m3;
    m3 = m1 * m2;
    m3.print();

    return 0;
}

bool testMatrixToolsAdd() {

    MatrixTools mt;

    Matrix m1;
    m1.vectorToMatrix(testData1, 3, 3);
    m1.print();

    cout << "  +" << endl;

    Matrix m2;
    m2.vectorToMatrix(testData2, 3, 3);
    m2.print();

    cout << "  ="  << endl;

    Matrix m3;
    m3 = mt.add(m1,m2);
    m3.print();

    return 0;
}

bool testMatrixToolsMult() {
    
    MatrixTools mt;

    Matrix m1;
    m1.vectorToMatrix(testData1, 3, 3);
    m1.print();

    cout << "  *" << endl;

    Matrix m2;
    m2.vectorToMatrix(testData2, 3, 5);
    m2.print();

    cout << "  ="  << endl;

    Matrix m3;
    m3 = mt.mult(m1,m2);
    m3.print();

    return 0;
}