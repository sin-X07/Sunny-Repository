#include<iostream>
#include<string>
#include<windows.h>

class TempConverter{
private:
    double celsius;

public:
    TempConverter(){
        celsius = 0;
        std::cout << "机器人已启动,初始摄氏度已设为0" <<std::endl;
    }

    TempConverter(double initC){
        celsius = initC;
        std::cout << "机器人已启动,初始摄氏度已设为" << celsius <<std::endl;
    }

    void setCelsius(double c){
        celsius = c;
    }

    void showFahrenheit(){
        double f = celsius * 1.8 + 32;
        std::cout << "摄氏度" << celsius << "等于摄氏度" << f << std::endl;
    }

    void caculateAll(double celsius, double &f, double &k){
        f = celsius * 1.8 + 32;
        k = celsius + 273.15;
        std::cout << "华氏度" << f << std::endl;
        std::cout << "开尔文温度" << k <<std::endl;
    }

    ~TempConverter(){
        std::cout << "机器人关闭并回收项目" << std::endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    TempConverter myRobot(0);
    double inputTemp, f = 0, k = 0;

    std::cout << "请输入当前摄氏度：";
    std::cin >> inputTemp;

    myRobot.caculateAll(inputTemp, f, k);
    // TempConverter myRobot1;
    // TempConverter myRobot(23);
    // myRobot.setCelsius(inputTemp);
    // myRobot.showFahrenheit();

    return 0;
}