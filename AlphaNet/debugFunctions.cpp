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

std::vector< std::vector<double> > testData2 = { {1,1,1},
                                            //{1,1,1},
                                            {1,2,3} };

//Headers
bool testMatrixAddition();



//Implementations
bool testMatrixAddition() {
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
    m3 = m1+m2;
    m3.print();

    return 0;
}