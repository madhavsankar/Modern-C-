#include <bits/stdc++.h>

using namespace std;

class Parent
{
    public:
    virtual void fun()
    {
        cout<< "Parent called.\n";
    }
};

class Child : public Parent
{
    public:
    void fun()
    {
        cout << "Child called.\n";
    }
};

class Sibling : public Parent
{
    public:
    void fun()
    {
        cout << "Sibling called.\n";
    }
};

int main()
{
    Parent* p = new Parent();
    Parent* c = new Child();
    Sibling* s = new Sibling();
    
    // 1. Convert a sibling type to child.
    
    Child* child = reinterpret_cast<Child*>(s);
    child->fun();
    
    // Not allowed by static cast!
    // Child* child = static_cast<Child*>(s);
    // child->fun();
    
    // 2. Convert a parent type to child.
    Child* cpp = static_cast<Child*>(p); // Not safe!
    cpp->fun();
    
    // Not allowed by Dynamic Cast!
    // Child* cpp2 = dynamic_cast<Child*>(p);
    // cpp2->fun();
    
    // 3. Convert a parent type (which is child originally) to child.
    Child* cpc = dynamic_cast<Child*>(c); // Safe!
    cpc->fun();
    
    return 0;
}

/*
Output:
Sibling called.
Parent called.
Child called.
*/