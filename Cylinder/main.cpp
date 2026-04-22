#include<iostream>
#include"cylinder.h"

int main()
{
	Cylinder myCylinder;
	double r, h;
	
    std::cout << "radius:";
    std::cin >> r;
    std::cin.get();

    std::cout << "height:";
    std::cin >> h;
    std::cin.get();

    myCylinder.setValues(r, h);

    std::cout << "area:" << myCylinder.cylinderArea() << std::endl;
    std::cout << "volume:" << myCylinder.cylinderVolume() << std::endl;

    std::cout << "按下回车键退出..." << std::endl;
    std::cin.get();

	return 0;
}