#include<iostream>
#include<string>

void swap(int &a, int &b){
    int temp=b;
    b=a;
    a=temp;
}

int main()
{
    int a=1, b=2;
    swap(a, b);
    std::cout << "a=" << a << " b=" << b << std::endl;
    
    return 0;
}