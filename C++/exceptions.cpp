#include<bits/stdc++.h>
using namespace std;

class MyException: public exception
{
    public:
    virtual const char* what() const throw()
    {
        return "Error name";
    }
};

void fun()
{
    throw MyException();
}

int main()
{
    try
    {
        fun();
    }
    catch(exception& e)
    {
        cout << e.what() << "\n";
    }
    

    return 0;
}