//
// Created by lee on 2021/10/26.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include "usedPackage.h"

class Matrix {
private:
    vector<vector<double>> matrixA;
    vector<vector<double>> matrixL;
    vector<vector<double>> matrixU;
    void setMatrixByCoordinate(int, int, double);
    double sumLktUtj(int, int);
    double sumLjtUtk(int, int);
public:
    Matrix();
    Matrix(int i);
    double getMatrixByCoordinate(int, int);
    vector<double> matrixMultArr(vector<double>);
    void printMatrix();
    void LU_Factorization();
    vector<double> LU_Solve(vector<double>);
    void plusIdentityMatrix(double);
};






#endif //MATRIX_MATRIX_H
