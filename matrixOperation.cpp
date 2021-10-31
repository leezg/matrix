//
// Created by lee on 2021/10/26.
//

#include "matrixOperation.h"

double vectorMult(vector<double>v1, vector<double> v2) {
    double sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        sum += v1[i] * v2[i];
    }
    return sum;
}

double getVectorNorm(vector<double> arr) {
    return sqrt(vectorMult(arr, arr));
}

vector<double> vectorNumberMult(vector<double> v, double times, char op) {
    vector<double> ans;
    switch (op) {
        case '*': {
            for (int i = 0; i < v.size(); i++) {
                ans.push_back(v[i] * times);
            }
        }
            break;
        case '/': {
            for (int i = 0; i < v.size(); i++) {
                ans.push_back(v[i] / times);
            }
        }
            break;
        default:
            break;
    }
    return ans;
}

bool checkE(double betaK, double betaK_1) {
    if (abs(betaK - betaK_1) / abs(betaK) < E) {
        return true;
    }
    return false;
}

vector<double> initU(int seed) {
    vector<double> u;
    switch (seed) {
        case 1:
            for (int i = 0; i < maxLength; i++) {
                u.push_back(i);
            }
            break;
        default:
            for (int i = 0; i < maxLength; i++) {
                u.push_back(1);
            }
            break;
    }

    return u;
}

void printVextor(vector<double> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}