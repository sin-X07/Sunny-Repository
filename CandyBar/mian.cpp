#include<iostream>
#include"CandyBar.h"

int main() {
    int n = 3;
    CandyBar* snack = new CandyBar[n];
    snack[0] = CandyBar("Mocha Munch", 2.3, 350);
    snack[1] = CandyBar("Mocha Munch", 2.3, 350);
    snack[2] = CandyBar("Mocha Munch", 2.3, 350);

    for (int i=0; i<n; i++) {
        std::cout << i + 1 <<std::endl;
        std::cout << "Brand: " << snack[i].brand <<std::endl;
        std::cout << "mass: " << snack[i].mass << std::endl;
        std::cout << "calorie: " << snack[i].calorie <<std::endl;
    }

    delete[] snack;

    return 0;
}