#include <iostream>
#include <time.h>
#include <random>

#include "Matrix.cpp"
#include "MatrixMath.cpp"
#include "NeuralNet.cpp"

using namespace std;

/*
Limitations:
- We're building this to work with only 2 layers, no hidden layer.
- Max 100 nodes per layer.
*/

/*
int main()
{
    NeuralNet net;

    net.create(10,10);

    net.test();

    net.run(20);
}
*/

//Sigmoid essentials
const double e = 2.71828182845904523536;

double sigmoid(double x, bool deriv = false) {
    if (deriv == true) {
        return (x * (1-x));
    }

    return (1/(1 + pow(e,-x)));
}

//Input Matrix
double x_array[4][3] = {{0,0,1},
                        {0,1,1},
                        {1,0,1},
                        {1,1,1}};

//Output Matrix
double y_array[4][1] = {{0},
                        {1},
                        {1},
                        {0}};

//Seed (for debugging)
const double SEED = 1;

//Bias
const double BIAS = 1;

//Iterations Config
const int TOTAL_ITERATIONS = 60000;
const int PRINT_ITERATIONS = 10000;

//MAIN

int main() 
{
    srand(SEED);

    Matrix x(4,3);
    Matrix y(4,1);

    //Fill X matrix
    for (int currentRow = 0; currentRow < 4; currentRow++) {
        for (int currentCol = 0; currentCol < 3; currentCol++) {
            x.setMatrix(currentRow, currentCol, x_array[currentRow][currentCol]);
        }
    }
    cout << "x: " << endl;
    x.print();

    //Fill Y matrix
    for (int currentRow = 0; currentRow < 4; currentRow++) {
        for (int currentCol = 0; currentCol < 1; currentCol++) {
            y.setMatrix(currentRow, currentCol, y_array[currentRow][currentCol]);
        }
    }
    cout << "y: " << endl;
    y.print();

    //Synapses
    Matrix syn0(3,4);
    Matrix syn1(4,1);

    syn0.randomize(0,1);
    syn1.randomize(0,1);
        //need to do something with a bias here

    //Training
    for (int i = 0; i < TOTAL_ITERATIONS; i++) {

        //Layers
        Matrix l1(5,5);

        MatrixMath mmath;
        //mmath.mult(x.getMatrix(), syn0.getMatrix(), l1.getMatrix());

        /* Okay so here we ran into a problem where we need to
        go back and merge the MatrixMath and matrix classes
        together or else this will be a pain in the a**. */

    }

    Matrix test1(3,3);
    Matrix test2(3,3);
    test1.randomize(1,5);
    test2.randomize(1,5);

    Matrix result(3,3);

    cout << "Success: " << test1.mult(test2,result) << endl;
    result.print();

    return 0;
}