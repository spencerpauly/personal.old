#include "MatrixTools.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>


//Constructors


//Methods
/*
void MatrixMath::add(std::vector< std::vector<double> >& m1, std::vector< std::vector<double> >& m2) {
    if (canAdd(m1,m2) == true) {
        for (int i = 0; i < m1.size(); i++) {
            for (int j = 0; j < m1[0].size(); j++) {
                cout << m1[i][j] + m2[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Error: 2 Matrices not compatible for adding" << endl;
    }
}

void MatrixMath::mult(std::vector< std::vector<double> >& m1, std::vector< std::vector<double> >& m2, std::vector< std::vector<double> >& output) {
    if (canMult(m1,m2) == true) {
        //Loop through the # of columns of Matrix1
        for (int i = 0; i < m1.size(); i++) {
            //Loop through # of rows of Matrix2
            for (int j = 0; j < m2[0].size(); j++) {
                //Loop through # of rows of Matrix1
                for (int k = 0; k < m1[0].size(); k++) {
                    output[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }

        //Print out the output Matrix
        for (int i = 0; i < output.size(); i++) {
            for (int j = 0; j < output[0].size(); j++) {
                cout << output[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Error: 2 Matrices not compatible for multiplying" << endl;
    }
}

bool MatrixMath::canAdd(std::vector< std::vector<double> >& m1, std::vector< std::vector<double> >& m2) {
    if (m1.size() == m2.size() && m1[0].size() == m2[0].size())
        return true;
    //if not true then...
    return false;
}

bool MatrixMath::canMult(std::vector< std::vector<double> >& m1, std::vector< std::vector<double> >& m2) {
    if (m1.size() == m2[0].size()) //Check if the rows of the 1st matrix will multiply with the columns of the 2nd
        return true;
    //if not true then...
    return false;
}
*/


//Mutators




//Accessors


