/** @file
 *
 *  NeuralNet class definition.
 *
 *  @author 
 *
 *  @date 2/7/2018, 11:02:43 PM
 *
 *  @version 1.0 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include "NeuralNet.h"

using namespace std;

//Constructors

NeuralNet::NeuralNet() {

}

//Methods

bool NeuralNet::create(int node1, int node2) {
    s1 = node1;
    s2 = node2;

    return true;
}

bool NeuralNet::run(int numberOfEpochs) {
    int runs = 0;
    while (runs < numberOfEpochs) {
        cout << "running epoch... " << endl;
        //
        calculateIteration();


        //
    runs++;
    }
    return true;
}

void NeuralNet::calculateIteration() {
    Matrix inputMatrix(10,1);

    //fill matrix
    for (int i = 0; i < 10; i++) {
        inputMatrix.setMatrix(0, i, input[i]);
    }

    

}

//Mutators

//Accessors
