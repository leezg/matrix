//
// Created by lee on 2021/10/27.
//

#ifndef MATRIX_USEDPACKAGE_H
#define MATRIX_USEDPACKAGE_H

#include <math.h>
#include <vector>
#include <iostream>
#define E pow(10, -12)
#define maxLength 501
#define maxIterTimes 10000

using namespace std;

extern vector<double> numA;
static double numB = 0.16;
static double numC = -0.064;

struct Lambda {
    double lambda1;
    double lambda501;
};


#endif //MATRIX_USEDPACKAGE_H
