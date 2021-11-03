#include "powerMethod.h"
#include "inversePowerMethod.h"
#include <cstdio>
#include <cstdlib>
#include "usedPackage.h"

double condA_2;
double detA;

void initNumA() {
    for (int i_ = 0; i_ < 501; i_++) {
        int i = i_ + 1;
        numA.push_back((1.64 - 0.024 * i) * sin(0.2 * i) - 0.64 * exp(0.1 / i));
    }
}

void fprintAnswer(Lambda lambda, vector<double> lambdaT) {
    FILE *fp;
    fp = fopen("./answer.csv", "w+");
    if (fp == NULL) {
        printf("null");
    }
    fprintf(fp, "lambda1,%20.12le\n", lambda.lambda1);
    fprintf(fp, "lambda501,%20.12le\n", lambda.lambda1);
    fprintf(fp, "lambdas,%20.12le\n", lambdaT[0]);
    for (int i = 1; i < lambdaT.size(); i++) {
        fprintf(fp, "lambdai_%d,%20.12le\n", i, lambdaT[i]);
    }
    fprintf(fp, "condA_2,%20.12le\n", condA_2);
    fprintf(fp, "detA,%20.12le\n", detA);
    fclose(fp);
}

void printAnswer(Lambda lambda, vector<double> lambdaT) {
    printf("\\lambda_1,%20.12le\n", lambda.lambda1);
    printf("\\lambda_{501},%20.12le\n", lambda.lambda1);
    printf("\\lambda_s,%20.12le\n", lambdaT[0]);
    for (int i = 1; i < lambdaT.size(); i++) {
        printf("\\lambda_i_{%d},%20.12le\n", i, lambdaT[i]);
    }
    printf("cond(A)_2,%20.12le\n", condA_2);
    printf("detA,%20.12le\n", detA);
}

void countCandD(Lambda lambda, vector<double> lambdaT) {
    double absLambdaM = max(abs(lambda.lambda1), abs(lambda.lambda501));
    condA_2 = absLambdaM / abs(lambdaT[0]);
    Matrix matrix = Matrix();
    matrix.LU_Factorization();
    detA = matrix.getDetA();
}

int main() {
    Lambda lambda;
    vector<double> lambdaT;
    initNumA();
    lambda = power();
    lambdaT = inversePower(lambda);
    countCandD(lambda, lambdaT);
    printAnswer(lambda, lambdaT);
    return 0;
}
