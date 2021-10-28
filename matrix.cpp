//
// Created by lee on 2021/10/26.
//
#include "matrix.h"
#include <math.h>
#define E exp(-12)

void Matrix::setMatrixByCoordinate(int i_, int j_, double value) { //根据原坐标设值
    if (i_ < 0 || j_ < 0 || i_ >= maxLength || j_ >= maxLength) {
        return;
    }
    int i = i_;
    int j = j_ - i_ + 2;
    if (j < 0 || j >= 5) {
        return;
    }
    if (matrixA.size() <= i) {
        matrixA.push_back(vector<double>());
    }
    if (matrixA[i].size() > j) {
        matrixA[i][j] = value;
    } else {
        while (matrixA[i].size() < j) {
            matrixA[i].push_back(0);
        }
        matrixA[i].push_back(value);
    }
}

double Matrix::getMatrixByCoordinate(int i_, int j_) { //根据原坐标取值
    if (i_ < 0 || j_ < 0 || i_ >= maxLength || j_ >= maxLength) {
        return 0;
    }
    int i = i_;
    int j = j_ - i_ + 2;
    if (j < 0 || j >= 5) {
        return 0;
    }
    return matrixA[i][j];
}

//TODO: 检查矩阵
Matrix::Matrix() { //矩阵初始化
    for (int i = 0; i < maxLength; i++) {
        setMatrixByCoordinate(i, i - 2, numC);
        setMatrixByCoordinate(i, i -1, numB);
        setMatrixByCoordinate(i, i, numA[i - 1]);
        setMatrixByCoordinate(i, i + 1, numB);
        setMatrixByCoordinate(i, i + 2, numC);
    }
}

//TODO: 降低复杂度
vector<double> Matrix::matrixMultArr(vector<double> arr) {
    vector<double> ans;
    for (int i = 0; i < maxLength; i++) {
        ans.push_back(0);
        for (int j = 0; j < maxLength; j++) {
            ans.push_back(getMatrixByCoordinate(i + 1, j + 1) * arr[j]);
        }
    }
    return arr;
}

void Matrix::printMatrix() {
    for (int i = 0; i < maxLength; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%20.12lf", matrixA[i][j]);
        }
        cout << endl;
    }
}

void Matrix::LU_Factorization() {
    for (int i = 0; i < maxLength; i++) {
        matrixL.push_back(vector<double>());
        matrixU.push_back(vector<double>());
        for (int j = 0; j < maxLength; j++) {
            matrixL[i].push_back(0);
            matrixU[i].push_back(0);
        }
    }

    for (int i = 0; i < maxLength; i++) {
        matrixU[0][i] = getMatrixByCoordinate(0, i);
        matrixL[i][0] = getMatrixByCoordinate(i, 0);
    }

    for (int r = 1; r < maxLength; r++) {
        for (int i = r; i < maxLength; i++) {
            matrixU[r][i] = getMatrixByCoordinate(r, i) - sumLrkUki(r, i);
            if  (i == r) {
                matrixL[i][r] = 1;
            } else {
                matrixL[i][r] = (getMatrixByCoordinate(i, r) - sumLrkUki(r, i)) / matrixU[r][r];
            }
        }
    }
}

vector<vector<double>> Matrix::getMatrixA() {
    return matrixA;
}

vector<vector<double>> Matrix::getMatrixL() {
    return matrixL;
}

vector<vector<double>> Matrix::getMatrixU() {
    return matrixU;
}

double Matrix::sumLrkUki(int r, int i) {
    double re = 0;
    for (int k = 0; k < r; k++) {
        re += matrixL[r][k] + matrixU[k][i];
    }
    return re;
}