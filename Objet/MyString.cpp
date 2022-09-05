#include <cstring>
#include <iostream>

#include "MyString.h"

//　Constructors
MyString::MyString()
{
    _content = nullptr;
}

MyString::MyString(const char* content)
{
    _content = new char[strlen(content)];

    char* i_point = const_cast<char*>(content);
    char* o_point = _content;

    while (*i_point != '\0')
    {
        *( o_point++ ) = *( i_point++ );
        _size++;
    }
}

MyString::MyString(const MyString& other)
{
    std::cout << "lol ";

    _size = other._size;
    _content = new char[other._size];

    char* o_point = _content;
    for (char* i_point = other._content; i_point < other._content + other._size; i_point++, o_point++)
        *( o_point ) = *( i_point );
}


// Methods
void MyString::display()
{
    char* point = _content;

    while (*point != '\0')
        std::cout << *( point++ );
}


// Operators
MyString& MyString::operator=(const MyString& other)
{
    if (this == &other)
        return *this;

    this->_size = other._size;
    delete(this->_content);
    this->_content = new char[other._size];

    char* o_point = _content;
    for (char* i_point = other._content; i_point < other._content + other._size; i_point++, o_point++)
        *( o_point ) = *( i_point );

    return *this;
}

bool MyString::operator==(const MyString& other) const
{
    if (_size != other._size)
        return false;

    char* point_a = _content;
    char* point_b = other._content;

    while (*point_a != '\0')
        if (*( point_a++ ) != *( point_b++ ))
            return false;

    return true;
}

bool MyString::operator!=(const MyString& other) const
{
    return !( other == *this );
}