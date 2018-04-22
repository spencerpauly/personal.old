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

#include "Matrix.h"
#include "MatrixTools.h"

using namespace std;

//Constructors

NeuralNet::NeuralNet() {

}

//Methods

bool NeuralNet::create(Matrix inputData) {
    layer[0] = inputData;
    return true;
}

bool NeuralNet::train() {
    

    return true;
}

bool NeuralNet::run(Matrix inputData) {

    return true;
}

//Mutators

//Accessors
