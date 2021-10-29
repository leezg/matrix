//
// Created by lee on 2021/10/26.
//

#include "powerMethod.h"

double iter(int &k, Matrix* matrix, vector<double> u) {
    vector<double> y;
    double uNorm = getVectorNorm(u);
    double betaK_1 = 0;
    double betaK;

    while (k < maxIterTimes) {
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

Lambda power() {
    Matrix* matrixA = new Matrix();
    int k = 1;
    //TODO: set u
    vector<double> u;
    double beta;
    Lambda lambda;
    beta = iter(k, matrixA, u);
    if (k < maxIterTimes) {
        double lambdaA, lambdaB;
        lambdaA = beta;
        matrixA->plusIdentityMatrix(-lambdaA);
        k = 1;
        beta = iter(k, matrixA, u);
        if (k < maxIterTimes) {
            lambdaB = beta + lambdaA;
            lambda.lambda1 = min(lambdaA, lambdaB);
            lambda.lambda501 = max(lambdaA, lambdaB);
        } else {
            cout << "调整u" << endl;
        }
    } else {
        //TODO: 矩阵变换
        k = 1;
        beta = iter(k, matrixA, u);
        if (k < maxIterTimes) {
            lambda.lambda1 = sqrt(beta);
            lambda.lambda501 = lambda.lambda1;
        } else {
            cout << "调整u" << endl;
        }
    }
    return lambda;
}

