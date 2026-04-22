#include<iostream>
#include<string>
#include"Person.h"

int main()
{
    AddressManager abs;
    int select = 0;

    while(true) {
        abs.showMenu();
        std::cout << "请输入您的需求:";
        std::cin >> select;

        switch(select) {
            case 1:  //添加联系人
                abs.addPerson();
                abs.pauseAndContinue();
                abs.clearAndContinue();
                break;
            case 2:  //删除联系人
                abs.deletePerson();
                abs.pauseAndContinue();
                abs.clearAndContinue();
                break;
            case 3:  //查找联系人
                abs.searchPerson();
                abs.pauseAndContinue();
                abs.clearAndContinue();
                break;
            case 4:  //显示联系人
                abs.showPerson();
                abs.pauseAndContinue();
                abs.clearAndContinue();
                break;
            case 5:  //修改联系人
                abs.modifyPerson();
                abs.pauseAndContinue();
                abs.clearAndContinue();
                break;
            case 6:  //清除所有联系人
                abs.clearAddressBooks();
                abs.pauseAndContinue();
                abs.clearAndContinue();
                break;
            case 0:  //退出程序
                std::cout << "文件已保存" << std::endl;
                std::cout << "欢迎下次使用(按下回车结束)" << std::endl;
                abs.saveToFile();
                abs.pauseAndContinue();
                return 0;
            default:
                std::cout << "超出能力范围" << std::endl;
                abs.pauseAndContinue();
                abs.clearAndContinue();
                break;
        }
    }
    return 0;
}