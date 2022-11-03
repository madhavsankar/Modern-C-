#include <bits/stdc++.h>

using namespace std;

class ClassName
{
    public:
    ClassName()
    {
        cout << "Created.\n";
    }
    
    ~ClassName()
    {
        cout << "Deleted.\n";
    }
};

class Parent
{
    public:
    unique_ptr<ClassName> uptr = nullptr;
    
    Parent()
    {
        uptr = make_unique<ClassName>();
    }
};

class Child : public Parent
{
    public:
    Child()
    {
        shared_ptr<ClassName> sptr = move(uptr);
    }
};

int main()
{
    unique_ptr<Parent> pptr = make_unique<Parent>();
    unique_ptr<Child> cptr = make_unique<Child>();
    
    return 0;
}