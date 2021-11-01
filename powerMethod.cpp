//
// Created by lee on 2021/10/26.
//

#include "powerMethod.h"

double iter(int &k, Matrix* matrix, vector<double> u) {
    vector<double> y;
    double uNorm;
    double betaK_1 = 0;
    double betaK;

    while (k < maxIterTimes) {
        uNorm  = getVectorNorm(u);
        y = vectorNumberMult(u, uNorm, '/');
        u = matrix->matrixMultArr(y);
        betaK = vectorMult(y, u);
        if (checkE(betaK, betaK_1)) {
            return betaK;
        }
        betaK_1 = betaK;
        k++;
    }

    return -1;
}

double iter2(int &k, Matrix* matrix, vector<double> u) {
    vector<double> y;
    double uNorm;
    double betaK_1 = 0;
    double betaK;

    while (k < maxIterTimes) {
        uNorm = getVectorNorm(u);
        y = vectorNumberMult(u, uNorm, '/');
        u = matrix->matrixMultArr(y);
        u = matrix->matrixMultArr(u);
        betaK = vectorMult(y, u);
        if (checkE(betaK, betaK_1)) {
            return betaK;
        }
        betaK_1 = betaK;
        k++;
    }

    return -1;
}

Lambda power() {
    Matrix* matrixA = new Matrix();
    int k = 1;
    vector<double> u = initU(0);
    double beta;
    Lambda lambda;
    beta = iter(k, matrixA, u);
    if (k < maxIterTimes) {
        double lambdaA, lambdaB;
        lambdaA = beta;
        matrixA->plusIdentityMatrix(-lambdaA);
        k = 1;
        u = initU(1);
        beta = iter(k, matrixA, u);
        if (k < maxIterTimes) {
            lambdaB = beta + lambdaA;
            lambda.lambda1 = min(lambdaA, lambdaB);
            lambda.lambda501 = max(lambdaA, lambdaB);
        } else {
            cout << "调整u" << endl;
        }
    } else {
        k = 1;
        beta = iter2(k, matrixA, u);
        if (k < maxIterTimes) {
            lambda.lambda1 = sqrt(beta);
            lambda.lambda501 = lambda.lambda1;
        } else {
            cout << "调整u" << endl;
        }
    }
    return lambda;
}

