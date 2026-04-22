#ifndef CANDYBAR
#define CANDYBAR

#include<string>

class CandyBar {
public:
    std::string brand;
    double mass;
    int calorie;

    CandyBar(){};
    CandyBar(std::string b, double m, int c) : brand(b), mass(m), calorie(c) {};
};


#endif