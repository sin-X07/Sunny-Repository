#include<iostream>
#include"cylinder.h"

void Cylinder::setValues(double r, double h) {
    radius = r;
    height = h;
}

double Cylinder::cylinderArea() {
    return 2 * PI * radius * (radius + height);
}

double Cylinder::cylinderVolume() {
    return PI * radius * radius * height;
}