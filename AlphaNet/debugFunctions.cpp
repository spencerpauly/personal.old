#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>

#include "Matrix.h"
#include "MatrixMath.h"

using namespace std;

//Global debug variables
bool checkMatrixMultVar = 0;

//Debug functions
void generalDebug();
void checkMatrixMult();

void generalDebug() {
    if (checkMatrixMultVar == true)
        checkMatrixMult();
    
}


//Debug function implimentations
void checkMatrixMult() {
    Matrix test1(3,2);
    test1.randomize(1,3);
    test1.print();

    Matrix test2(2,2);
    test2.randomize(1,3);
    test2.print();


    Matrix result(3,3);
    cout << "Success: " << test1.mult(test2,result) << endl;
    result.print();

}