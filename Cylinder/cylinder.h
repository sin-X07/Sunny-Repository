#ifndef CYLINDER_H
#define CYLINDER_H

#define PI 3.14159

class Cylinder {
public:
	double cylinderArea();
    double cylinderVolume();
    void setValues(double r, double h);

private:
    double radius;        
    double height;
};

#endif