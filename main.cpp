#include "usedPackage.h"
#include "matrix.h"
#include "powerMethod.h"
#include "inversePowerMethod.h"

void initNumA() {
    for (int i_ = 0; i_ < 501; i_++) {
        int i = i_ + 1;
        numA.push_back((1.64 - 0.024 * i) * sin(0.2 * i) - 0.64 * exp(0.1 / i));
    }
}

int main() {
    initNumA();
    Lambda lambda = power();
    vector<double> lambdaT = inversePower(lambda);
    return 0;
}
