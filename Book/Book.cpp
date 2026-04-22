#include"Book.h"
#include<vector>

Book::Book(std::string title, std::string isbn, double price)
    :title(title), isbn(isbn), price(price) {}

void Book::display() const {
    std::cout << "   书名:" << title
              << "   ISBN:" << isbn
              << "   价格:" << price << std::endl;
}