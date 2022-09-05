#include <iostream>
#include <cstring>

#include "MyString2.h"

using namespace std;

MyString doSomething(MyString arg)
{
    return arg;
}

int main(int argc, char** argv)
{
    MyString a("Hello");
    MyString b("World");

    b = a;

    b.display();
    cout << endl;

    a._content[2] = 'c';

    b.display();

    return 0;
}