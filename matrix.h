//
// Created by lee on 2021/10/26.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

static double matrixA[501][5];
static double numA[501];
static double numB = 0.16;
static double numC = -0.064;

void initNumA();
void initMatrix();
void setMatrixByCoordinate(int, int, double);
double getMatrixByCoordinate(int, int);
//void printMatrix();


#endif //MATRIX_MATRIX_H
