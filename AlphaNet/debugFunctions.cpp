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

//Headers
bool testMatrixAddition();



//Implementations
bool testMatrixAddition() {
    MatrixTools mt;

    Matrix m1;
    m1.vectorToMatrix(arr1, 3, 3);
    m1.print();

    cout << "  +" << endl;
    
    Matrix m2;
    m2.vectorToMatrix(arr2, 3, 3);
    m2.print();

    cout << "  ="  << endl;


    Matrix m3;
    m3.copy( mt.add(m1, m2) );

    m3.print();



    return 0;
}