#include<iostream>
#include<vector>

int main()
{
    std::cout << "开始吃内存，打开任务管理器观察，按下回车开始" << std::endl;
    std::cin.get();

    while (true) {
        double* leak = new double[1024 * 10 / sizeof(double)];
        leak[0] = 1.234;

        if (leak == nullptr) {
            std::cout << "内存申请失败！" << std::endl;
            break;
        }

        // 释放内存
        delete[] leak;
        leak = nullptr;
    }

    return 0;
}