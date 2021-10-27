//
// Created by lee on 2021/10/26.
//
#include "matrix.h"
#include <math.h>
#define E exp(-12)

void initNumA() {
    for (int i_ = 0; i_ < 501; i_++) {
        int i = i_ + 1;
        numA.push_back((1.64 - 0.024 * i) * sin(0.2 * i) - 0.64 * exp(0.1 / i));
    }
}

void setMatrixByCoordinate(int i_, int j_, double value) { //根据原坐标设值
    if (i_ < 1 || j_ < 1 || i_ > 501 || j_ > 501) {
        return;
    }
    int i = i_ - 1;
    int j = j_ - i_ + 2;
    if (j < 0 || j >= 5) {
        return;
    }
    matrixA[i][j] = value;
}

double getMatrixByCoordinate(int i_, int j_) { //根据原坐标取值
    if (i_ < 1 || j_ < 1 || i_ > 501 || j_ > 501) {
        return 0;
    }
    int i = i_ - 1;
    int j = j_ - i_ + 2;
    if (j < 0 || j >= 5) {
        return 0;
    }
    return matrixA[i][j];
}

void initMatrix() { //矩阵初始化
    for (int i = 1; i <= 501; i++) {
        setMatrixByCoordinate(i, i - 2, numC);
        setMatrixByCoordinate(i, i -1, numB);
        setMatrixByCoordinate(i, i, numA[i - 1]);
        setMatrixByCoordinate(i, i + 1, numB);
        setMatrixByCoordinate(i, i + 2, numC);
    }
}

//TODO: 降低复杂度
double* matrixAmultArr(double arr[501]) {
    vector<double> ans;
    for (int i = 0; i < 501; i++) {
        ans.push_back(0);
        for (int j = 0; j < 501; j++) {
            ans.push_back(getMatrixByCoordinate(i + 1, j + 1) * arr[j]);
        }
    }
    return arr;
}

//void printMatrix() {
//    for (int i = 0; i < 501; i++) {
//        for (int j = 0; j < 5; j++) {
//            printf("%20.12lf", matrixA[i][j]);
//        }
//        cout << endl;
//    }
//}
