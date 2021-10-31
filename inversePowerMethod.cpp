//
// Created by lee on 2021/10/27.
//

#include "inversePowerMethod.h"

vector<double> mu;
vector<double> lambdaT;

double iter(int &k, Matrix* matrix, vector<double> &u) {
    vector<double> y;
    double uNorm;
    double betaK_1 = 0;
    double betaK;

    while (k < maxIterTimes) {
        uNorm = getVectorNorm(u);
        y = vectorNumberMult(u, uNorm, '/');
        u = matrix->LU_Solve(y);
        vector<double> t = matrix->matrixMultArr(u);
        betaK = vectorMult(y, u);
        if (checkE(betaK, betaK_1)) {
            return betaK;
        }
        betaK_1 = betaK;
        k++;
    }


    return -1;
}

void initMu(Lambda lambda) {
    mu.push_back(0);
    for (int i = 1; i < muNum; i++) {
        mu.push_back(lambda.lambda1 + i * (lambda.lambda501 - lambda.lambda1) / 40);
    }
}

vector<double> inversePower(Lambda lambda) {
    initMu(lambda);
    for (int t = 0; t < 40; t++) {
        Matrix *matrixA = new Matrix();
        matrixA->plusIdentityMatrix(-mu[t]);
        matrixA->LU_Factorization();
        vector<double> u = initU(0);
        double beta;
        int k = 1;
        beta = iter(k, matrixA, u);
        if (k < maxIterTimes) {
            lambdaT.push_back(1 / beta + mu[t]);
        } else {
//            lambdaT.push_back(0xFFFFFFF);
        }
    }
    return lambdaT;
}

