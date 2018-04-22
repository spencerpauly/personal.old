/** @file
 *
 *  NeuralNet class definition.
 *
 *  @author Spencer Pauly
 *
 *  @date 7 Feb 2018
 *
 *  @version 1.0 */

#ifndef NEURALNET_H
#define NEURALNET_H

#include <vector>
#include <iostream>

#include "Matrix.h"
#include "MatrixTools.h"


/*
Future Updates:
    - have create() method just ask for a config file for the neural net and use those variables.
    - 
*/

using namespace std;


class NeuralNet {
    private:
        static const int NETWORK_LAYERS = 3;
        Matrix layer[NETWORK_LAYERS];

        const int epochs = 10000;

        //Methods
        //void runIteration(); // 1. Do the calculator math, 2. Save ending values, 3. Calculate best genetic changes to undergo
        
    public:
        //Constructors
        NeuralNet();
        //Methods
        bool create(); //Will be outsourced to another class, basically sets all variables
        bool train(); //Run 1 iteration of the neural net.

        bool run(Matrix inputData); //Run 1 iteration of the neural net.
        void test() { cout << "It works." << endl; }

        //Mutators
        setEpochs();


        //Accessors

};

#include "NeuralNet.cpp"

#endif // NEURALNET_H