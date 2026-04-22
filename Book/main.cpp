#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include"Book.h"

void menu(std::vector<Book>& library) {
    std::cout << "--- 图书管理系统 ---" << std::endl;
    std::cout << "1.展示书库\n"
                 "2.查找书籍\n"
                 "3.添加书籍\n"
                 "4.删除书籍\n" 
                 "0.退出\n"
                 "-------------------" <<std::endl;
    std::cout << "输入您的需求:";
}

void displayLibrary(std::vector<Book>& library) {
    for(const auto& book : library) {
        book.display();
    }
}

void searchBook(std::vector<Book>& library) {
    std::string searchTitle;
    std::cout << "请输入您想要查找的书籍名称:";

    // 清除缓冲区
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    // 读到换行符为止，防止漏掉书名空格符
    std::getline(std::cin, searchTitle);

    for(const auto& book : library) {
        if(book.getTitle() == searchTitle) {
            std::cout << "找到书籍:" << std::endl;
            book.display();
            break;
        } else {
            std::cout << "未找到" << searchTitle <<std::endl;
        }
    }
}

void addBook(std::vector<Book>& library) {
    std::string title;
    std::string isbn;
    double price;
    
    std::cout << "请输入书籍信息:" << std::endl;
    std::cout << "书名:";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin, title);
    std::cout << "ISBN:";
    std::cin >> isbn;
    std::cout << "价格:";
    std::cin >> price;

    library.emplace_back(title, isbn, price);
    std::cout << "添加成功!" <<std::endl;
}

void deleteBook(std::vector<Book>& library) {
    std::string target;
    std::cout << "请输入书籍名称:";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin, target);

    // 迭代器，查找书籍
    auto it = std::find_if(library.begin(), library.end(), [&](const Book& b) {
        return b.getTitle() == target;
    });

    if(it != library.end()) {
        library.erase(it);
        std::cout << "删除成功!" << std::endl;
    } else {
        std::cout << "未找到" << target << std::endl;
    }

}

int main()
{
    std::vector<Book> library;

    library.push_back(Book("C++ Primer", "978-0321714114", 128.0));
    library.push_back(Book("Effective C++", "978-0596000271", 68.5));

    int choice;
    bool running = true;

    while(running) {
        menu(library);
        std::cin >> choice;

        switch(choice) {
            case 1:
                displayLibrary(library);
                break;
            case 2:
                searchBook(library);
                break;
            case 3:
                addBook(library);
                break;
            case 4:
                deleteBook(library);
                break;
            case 0:
                running = false;
                break;
            default:
                std::cout << "无效输入!请重新选择!" <<std::endl;
                break;
        }
    }

    return 0;
}