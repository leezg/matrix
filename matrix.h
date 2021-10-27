//
// Created by lee on 2021/10/26.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include "usedPackage.h"

class Matrix {
private:
    vector<vector<double>> matrixA;
    void setMatrixByCoordinate(int, int, double);
public:
    Matrix();
    double getMatrixByCoordinate(int, int);
    vector<double> matrixMultArr(vector<double>);
    void printMatrix();
};






#endif //MATRIX_MATRIX_H
