#include <bits/stdc++.h>

using namespace std;

class ClassName
{
    public:
    ClassName() = default;
    
    // We should be able to pass lvalue and rvalue => so const lvalue reference.
    ClassName(const ClassName& other) = default;
};

int main()
{
    ClassName className;
    
    // lvalue reference bind with lvalue
    ClassName &lClassName = className; 
    
    // const lvalue reference bind with rvalue
    const ClassName &lClassName2 = ClassName();
    
    // rvalue reference bind with moved lvalue.
    ClassName &&rClassName = move(className);
    
    // rvalue reference bind with rvalue.
    ClassName &&rClassName2 = ClassName();
    
    return 0;
}