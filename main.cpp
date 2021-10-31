#include "powerMethod.h"
#include "inversePowerMethod.h"
#include "usedPackage.h"

double condA_2;
double detA;

void initNumA() {
    for (int i_ = 0; i_ < 501; i_++) {
        int i = i_ + 1;
        numA.push_back((1.64 - 0.024 * i) * sin(0.2 * i) - 0.64 * exp(0.1 / i));
    }
}

void printAnswer(Lambda lambda, vector<double> lambdaT) {
    printf("lambda1:\t%20.12lf\n", lambda.lambda1);
    printf("lambda501:\t%20.12lf\n", lambda.lambda1);
    printf("lambdas:\t%20.12lf\n", lambdaT[0]);
    for (int i = 1; i < lambdaT.size(); i++) {
        printf("lambdai_%d:\t%20.12lf\n", i, lambdaT[i]);
    }
    printf("condA_2:\t%20.12lf\n", condA_2);
    printf("detA:\t%20.12lf\n", detA);
}

double countCandD(Lambda lambda, vector<double> lambdaT) {
    double absLambdaM = max(abs(lambda.lambda1), abs(lambda.lambda501));
    condA_2 = absLambdaM / abs(lambdaT[0]);
    detA = 1;
    for (int i = 1; i < lambdaT.size(); i++) {
        detA *= lambdaT[i];
    }
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
