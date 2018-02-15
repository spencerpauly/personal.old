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

using namespace std;


class NeuralNet{
    private:
        static const int NETWORK_LAYERS = 2;
        int s1;
        int s2;
        int epochs;
        int input[];
        vector<double> currentWeights;

        //Methods
        //void runIteration(); // 1. Do the calculator math, 2. Save ending values, 3. Calculate best genetic changes to undergo
        void calculateIteration();
        void saveData();
        void evolutionAlgorithm();
        
    public:
        //Constructors

        //Methods
        bool create(int nodes1, int nodes2);
        bool run(int numberOfEpochs); //Run 1 iteration of the neural net.
        void test() { cout << "It works." << endl; }

        //Mutators
        setEpochs();


        //Accessors

};

#endif // MATRIX_H