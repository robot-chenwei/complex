#include "equation.h"

int main() {
    complex c1(1.0, 1.0);
    std::cout << c1.Re << " + " << c1.Im << " i" << std::endl;
    complex c2 = power(c1, 3.0);
    std::cout << c2.Re << " + " << c2.Im << " i" << std::endl;
    complex c3 = power(c2, 1.0/3.0);
    std::cout << c3.Re << " + " << c3.Im << " i" << std::endl;

    complex ans[4];
    equation e1(1.0, 1.0);
    int size = e1.roots(ans);
    std::cout << "ans size : " << size << std::endl;
    for (int i = 0; i < size; ++ i)
        std::cout << ans[i] << ", ";
    std::cout << std::endl;

    equation e2(1.0, 0.0, 1.0);
    size = e2.roots(ans);
    std::cout << "ans size : " << size << std::endl;
    for (int i = 0; i < size; ++ i)
        std::cout << ans[i] << ", ";
    std::cout << std::endl;

    equation e3(1.0, 0.0, 0.0, 1.0);
    size = e3.roots(ans);
    std::cout << "ans size : " << size << std::endl;
    for (int i = 0; i < size; ++ i)
        std::cout << ans[i] << ", ";
    std::cout << std::endl;

    equation e4(1.0, .0, .0, .0, -1.0);
    size = e4.roots(ans);
    std::cout << "ans size : " << size << std::endl;
    for (int i = 0; i < size; ++ i)
        std::cout << ans[i] << ", ";
    std::cout << std::endl;

    return 0;
}