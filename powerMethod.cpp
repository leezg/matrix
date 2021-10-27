//
// Created by lee on 2021/10/26.
//

#include "powerMethod.h"

double iter(int &k, Matrix* matrix, vector<double> u) {
    vector<double> y;
    double uNorm = getVectorNorm(u);
    double betaK_1 = 0;
    double betaK;

    while (k < 10000) {
        y = vectorNumberMult(u, uNorm, '/');
        u = matrix->matrixMultArr(y);
        betaK = vectorMult(y, u);
        if (checkE(betaK, betaK_1)) {
            return betaK;
        }
        k++;
    }

    return -1;
}

Lamda power() {
    Matrix* matrixA = new Matrix();
    int k = 1;
    vector<double> u;
    double beta;
    Lamda lamda;
    beta = iter(k, matrixA, u);
    if (k < 10000) {
        double lamdaA, lamdaB;
        lamdaA = beta;
        //TODO: 矩阵变换
        k = 1;
        beta = iter(k, matrixA, u);
        if (k < 10000) {
            lamdaB = beta + lamdaA;
            lamda.lamda1 = min(lamdaA, lamdaB);
            lamda.lamda501 = max(lamdaA, lamdaB);
        } else {
            cout << "调整u" << endl;
        }
    } else {
        //TODO: 矩阵变换
        k = 1;
        beta = iter(k, matrixA, u);
        if (k < 10000) {
            lamda.lamda1 = sqrt(beta);
            lamda.lamda501 = lamda.lamda1;
        } else {
            cout << "调整u" << endl;
        }
    }
    return lamda;
}

