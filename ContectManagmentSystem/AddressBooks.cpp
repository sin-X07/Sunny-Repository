#include<iostream>
#include "Person.h"

AddressManager::AddressManager() {
    this->m_size = 0;
    this->m_capacity = 10;
    this->memberArray = new member[this->m_capacity];

    std::ifstream ifs;
    ifs.open("addressbook.txt", std::ios::in);
    if (!ifs.is_open()) {
        std::cout << "欢迎使用！正在为您创建文档..." << std::endl;
        return;
    }

    member temp;
    while (ifs >> temp.m_name >> temp.m_sex >> temp.m_age >> temp.m_address >>temp.m_phoneNumber) {
        if (this->m_size == this->m_capacity) {
            int newCapacity = this->m_capacity + 10;
            member* newtemp = new member[newCapacity];
            for (int i=0;i<newCapacity;i++) {
                newtemp[i] = this->memberArray[i];
            }
            delete[] this->memberArray;
            this->memberArray = newtemp;
            this->m_capacity = newCapacity;
            std::cout << "(注：空间不足，以自动扩容至" << newCapacity << "单元)" <<std::endl;
        }
        this->memberArray[this->m_size] = temp;
        this->m_size++;
    }
}

void AddressManager::saveToFile() {
    std::ofstream ofs;
    ofs.open("addressbook.txt", std::ios::out);

    if (!ofs.is_open()) {
        std::cout << "文件打开失败，无法保存！" << std::endl;
        return;
    }

    for (int i=0;i<this->m_size;i++) {
        ofs << this->memberArray[i].m_name << "\t"
            << this->memberArray[i].m_sex << "\t"
            << this->memberArray[i].m_age << "\t"
            << this->memberArray[i].m_address << "\t"
            << this->memberArray[i].m_phoneNumber << std::endl;
    }

    ofs.close();
}

AddressManager::~AddressManager() {
    if (this->memberArray != nullptr) {
        delete[] this->memberArray;
        this->memberArray = nullptr;
    }
}

void AddressManager::showMenu() {
    std::cout << "---------------------" << std::endl;
    std::cout << "-----1.添加联系人-----" << std::endl;
    std::cout << "-----2.删除联系人-----" << std::endl;
    std::cout << "-----3.查找联系人-----" << std::endl;
    std::cout << "-----4.显示联系人-----" << std::endl;
    std::cout << "-----5.修改联系人-----" << std::endl;
    std::cout << "-----6.清空联系人-----" << std::endl;
    std::cout << "-----0.退出程序-------" << std::endl;
    std::cout << "---------------------" << std::endl;
    return;
}

void AddressManager::addPerson() {
    if (this->m_size == this->m_capacity) {
        int newCapacity = this->m_capacity + 10;
        member* newtemp = new member[newCapacity];
        for (int i=0;i<newCapacity;i++) {
            newtemp[i] = this->memberArray[i];
        }
        delete[] this->memberArray;
        this->memberArray = newtemp;
        this->m_capacity = newCapacity;
        std::cout << "(注：空间不足，以自动扩容至" << newCapacity << "单元)" <<std::endl;
    }
    std::cout << "请输入姓名：";
    std::cin >> this->memberArray[this->m_size].m_name;
    std::cout << "请输入性别：";
    std::cin >> this->memberArray[this->m_size].m_sex;
    std::cout << "请输入年龄：";
    std::cin >> this->memberArray[this->m_size].m_age;
    std::cout << "请输入住址：";
    std::cin >> this->memberArray[this->m_size].m_address;
    std::cout << "请输入手机号：";
    std::cin >> this->memberArray[this->m_size].m_phoneNumber;
    this->m_size++;
    std::cout << "添加成功!" << std::endl;
    return;
}

void AddressManager::deletePerson() {
    if (this->m_size == 0) {
        std::cout << "当前无成员" << std:: endl;
        return;
    } else {
        std::string deleteName;
        std::cout << "请输入您想要删除的用户：";
        std::cin >> deleteName;
        for (int i=0;i<this->m_size;i++) {
            if (deleteName == this->memberArray[i].m_name) {
                for (int j=i;j<this->m_size-1;j++) {
                    this->memberArray[j] = this->memberArray[j+1];
                }
                this->m_size--;
                std::cout << "删除成功！" << std::endl;
                return;
            }
        }
        std::cout << "未找到名为" << deleteName << "的用户" << std::endl;
        return;
    }
}

void AddressManager::searchPerson() {
    if (this->m_size == 0) {
        std::cout << "当前无成员" << std:: endl;
        return;
    } else {
        std::string searchName;
        std::cout << "请输入您想要查找的用户：";
        std::cin >> searchName;
        for (int i=0;i<this->m_size;i++) {
            if (searchName == this->memberArray[i].m_name) {
                std::cout << "找到用户：" << std::endl;
                std::cout << this->memberArray[i].m_name << "\t" 
                          << this->memberArray[i].m_sex << "\t" 
                          << this->memberArray[i].m_age << "\t" 
                          << this->memberArray[i].m_address << "\t" 
                          << this->memberArray[i].m_phoneNumber << std::endl;
                return;
            }
        }
        std::cout << "未找到用户" << searchName << std::endl;
        return;
    }
}

void AddressManager::showPerson() {
    if (this->m_size == 0) {
        std::cout << "当前无成员" << std:: endl;
        return;
    }
    for (int i=0;i<this->m_size;i++) {
        std::cout << i+1 << "." << this->memberArray[i].m_name << "\t" 
                  << this->memberArray[i].m_sex << "\t" 
                  << this->memberArray[i].m_age << "\t" 
                  << this->memberArray[i].m_address << "\t" 
                  << this->memberArray[i].m_phoneNumber << std::endl;
    }
    return;
}

void AddressManager::modifyPerson() {
    if (this->m_size == 0) {
        std::cout << "当前无成员" << std:: endl;
        return;
    } else {
        std::string modifyName;
        std::cout << "请输入您想要更改的用户：";
        std::cin >> modifyName;
        for (int i=0;i<this->m_size;i++) {
            if (modifyName == this->memberArray[i].m_name) {
                std::cout << "找到用户：" << this->memberArray[i].m_name << "\t" 
                          << this->memberArray[i].m_sex << "\t" 
                          << this->memberArray[i].m_age << "\t" 
                          << this->memberArray[i].m_address << "\t" 
                          << this->memberArray[i].m_phoneNumber << std::endl;
                std::cout << "更改如下：" <<std::endl;
                std::cout << "请输入姓名：";
                std::cin >> this->memberArray[i].m_name;
                std::cout << "请输入性别：";
                std::cin >> this->memberArray[i].m_sex;
                std::cout << "请输入年龄：";
                std::cin >> this->memberArray[i].m_age;
                std::cout << "请输入住址：";
                std::cin >> this->memberArray[i].m_address;
                std::cout << "请输入手机号：";
                std::cin >> this->memberArray[i].m_phoneNumber;
                std::cout << "更改成功！" << std::endl;
                return;
            }
        }
        std::cout << "未找到用户" << modifyName << std::endl;
        return;
    }
}

void AddressManager::clearAddressBooks() {
    std::cout << "确定清空吗？(Yes/No)" << std::endl;
    std::string select;
    std::cin >> select;
    if (select == "Yes" || select == "yes") {
        this->m_size = 0;
        std::cout << "通讯录已清空！" << std::endl;
        return;
    }
    return;
}

void AddressManager::pauseAndContinue() {
    std::cout << "按下回车键继续" << std::endl;
    std::cin.ignore();
    std::cin.get();
}

void AddressManager::clearAndContinue() {
    std::cout << "\033[2J\033[H";
}