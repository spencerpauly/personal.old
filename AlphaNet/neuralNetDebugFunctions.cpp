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

//Sigmoid essentials
const double e = 2.71828182845904523536;

// double sigmoid(double x, bool deriv = false) {

//     if (deriv == true) {
//         return (x * (1-x));
//     }

//     return (1/(1 + pow(e,-x)));
// }

//Input Matrix
std::vector< std::vector<double> > x_array = { {0,0,1},
                                               {0,1,1},
                                               {1,0,1},
                                               {1,1,1} };

//Output Matrix
std::vector< std::vector<double> > y_array = { {0},
                                               {1},
                                               {1},
                                               {0} };

//Seed (for debugging)
const double SEED = 12;

//Bias
const double BIAS = 1;

//Iterations Config
const int TOTAL_ITERATIONS = 60000;
const int PRINT_ITERATIONS = 10000;


//Headers
bool runNeuralNet();

//Implimentation
bool runNeuralNet(){

    srand(SEED);

    Matrix x;
    Matrix y;

    MatrixTools np;

    //Fill X matrix
    x.vectorToMatrix(x_array, 4, 3);
    cout << "x: " << endl;
    x.print();

    //Fill Y matrix
    y.vectorToMatrix(y_array, 4, 1);
    cout << "y: " << endl;
    y.print();
    
    //Initialize Layers
    Matrix l0;
    Matrix l1;
    Matrix l2;
    Matrix l2_delta;
    Matrix l1_error;
    Matrix l1_delta;
    Matrix l2_error(l2.getRows(), l2.getCols());


    //Synapses
    Matrix syn0(3,4);
    Matrix syn1(4,1);

    syn0.randomize(0,20);
    syn1.randomize(0,20);
        //need to do something with a bias here

    //Training
    for (int i = 0; i < TOTAL_ITERATIONS; i++) {

        //Layers
         l0 = x;
         l1 = np.intAdd(np.sigmoid(l0 * syn0), 1);
         l2 = np.intAdd(np.sigmoid(l1 * syn1), 1);

        //Backpropagation

        l2_error = y - l2;
        if ((i % PRINT_ITERATIONS) == 0) {
            //l2.print();
            //l2_error.print();
            cout << "Error at [" << i << "]: " << l2_error.getMean() << endl;
        }

        //Calculate deltas (difference in quantity every time)
        l2_delta = np.scalarMult(l2_error, np.sigmoid(l2, true) );
        l1_error = l2_delta * (np.transpose(syn1) );
        l1_delta = np.scalarMult(l1_error, np.sigmoid(l1, true) );

        //Update our synapses
        syn1 = syn1 + (np.transpose(l1) * l2_delta );
         //
        if ((i % PRINT_ITERATIONS) == 0) {
            (np.transpose(l1) * l2_delta ).print();
        }
        syn0 = syn0 + (np.transpose(l0) * l1_delta );
        
        // if ((i % PRINT_ITERATIONS) == 0) {
        //     syn1.print();
        // }

    }

    cout << "Output after training: " << endl;
    l2.print();

    return 0;

}
