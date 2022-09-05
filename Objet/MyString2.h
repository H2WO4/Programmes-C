#include "MyString.h"

class MyString2 : public MyString
{
public:
    MyString2();

    MyString2(char* content);

    void display() override;
};