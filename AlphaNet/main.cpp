#include <iostream>

#include "Matrix.cpp"
#include "MatrixMath.cpp"
#include "NeuralNet.cpp"

using namespace std;

void testFunction();

/*
Limitations:
- We're building this to work with only 2 layers, no hidden layer.
- Max 10 nodes per layer.




*/

int main()
{
    NeuralNet net;

    net.create(10,10);

    net.test();

    net.run(20);
}
