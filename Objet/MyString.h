#ifndef PROGRAMMES_C_MYSTRING_H
#define PROGRAMMES_C_MYSTRING_H

class MyString
{
public:
    int _size = 0;
    char* _content;

    static int count;

public:
    // Constructors
    MyString();

    MyString(const char* content);

    MyString(MyString const &other);

    // Methods
    virtual void display();

    // Operators
    MyString& operator=(const MyString& other);

    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
};

#endif