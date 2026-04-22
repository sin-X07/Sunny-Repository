#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include<string>

class Book {
private:
    std::string title;
    std::string isbn;
    double price;

public:
    // 构造函数，创建对象
    Book(std::string title, std::string isbn, double price);
    
    // 打印
    void display() const;

    // 获取标题
    const std::string& getTitle() const {
    return title;
    }
};

#endif