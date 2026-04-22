#ifndef ADDRESSBOOKS_H
#define ADDRESSBOOKS_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

struct member {
    std::string m_name;
    std::string m_sex;
    int m_age;
    std::string m_address;
    std::string m_phoneNumber;
};

class AddressManager {
public:
    AddressManager();
    ~AddressManager();

    void showMenu();
    void addPerson();
    void deletePerson();
    void searchPerson();
    void showPerson();
    void modifyPerson();
    void clearAddressBooks();
    void pauseAndContinue();
    void clearAndContinue();
    void saveToFile();

private:
    member* memberArray;
    int m_size;
    int m_capacity;
};

#endif