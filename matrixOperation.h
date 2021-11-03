//
// Created by lee on 2021/10/26.
//

#ifndef MATRIX_MATRIXOPERATION_H
#define MATRIX_MATRIXOPERATION_H

#include "usedPackage.h"

//两个向量的内积
double vectorMult (vector<double>, vector<double>);
//计算向量的范数
double getVectorNorm (vector<double>);
//向量数乘
vector<double> vectorNumberMult(vector<double>, double, char);
//检查误差
bool checkE(double, double);
//选定初始迭代向量
vector<double> initU(int);

#endif //MATRIX_MATRIXOPERATION_H
