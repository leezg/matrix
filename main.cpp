#include <iostream>
#include "matrix.h"

using namespace std;

void testPrint() {
    for (int i = 1; i <= 501; i++) {
        int j = i - 2;
        for (; j <= i + 2; j++) {
            printf("%20.12lf", getMatrixByCoordinate(i, j));
        }
        cout << endl;
    }
}

int main() {
    initNumA();
    initMatrix();
//    testPrint();
    return 0;
}
