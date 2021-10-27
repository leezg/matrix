//
// Created by lee on 2021/10/26.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <vector>
#include <iostream>

using namespace std;

static vector<vector<double>> matrixA;
static vector<double> numA;
static double numB = 0.16;
static double numC = -0.064;

void initNumA();
void initMatrix();
void setMatrixByCoordinate(int, int, double);
double getMatrixByCoordinate(int, int);
vector<double> matrixAmultArr(vector<double>);
void printMatrix();


#endif //MATRIX_MATRIX_H
