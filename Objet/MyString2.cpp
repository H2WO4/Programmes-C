#include <iostream>

#include "MyString2.h"

void MyString2::display()
{
    std::cout << "Hello ";
    MyString::display();
}

MyString2::MyString2(char* content) : MyString(content)
{
    (*_content)++;
}

MyString2::MyString2() : MyString()
{

}
