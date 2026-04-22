#include<iostream>
#include<string>

int main() {
    std::string firstName, lastName, fullName;

    std::cout << "Enter your first name: ";
    std::cin >> firstName;
    std::cout << "Enter your last name: ";
    std::cin >> lastName;
    fullName = lastName + ", " + firstName;
    std::cout << "Here's the information in a single string: " << fullName << std::endl;

    return 0;
}