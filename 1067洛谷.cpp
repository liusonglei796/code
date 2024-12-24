#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> coefficients(n + 1);
    for (int i = n; i >= 0; --i) {
        std::cin >> coefficients[i];
    }

    std::stringstream ss;
    for (int i = n; i >= 0; --i) {
        if (coefficients[i]!= 0) {
            if (ss.tellp() > 0) {
                if (coefficients[i] > 0) {
                    ss << "+";
                } else {
                    ss << "-";
                }
            } else if (coefficients[i] < 0) {
                ss << "-";
            }

            int absCoefficient = abs(coefficients[i]);
            if (absCoefficient!= 1 || i == 0) {
                ss << absCoefficient;
            }
            if (i > 0) {
                ss << "x";
                if (i > 1) {
                    ss << "^" << i;
                }
            }
        }
    }

    if (ss.str().empty()) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << ss.str() << std::endl;
    }

    return 0;
}