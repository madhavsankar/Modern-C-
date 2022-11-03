#include <bits/stdc++.h>

using namespace std;

class ClassName
{
    public:
    ClassName() = default;
    ClassName(const ClassName& b)
    {
        cout << "Copy Constructor called.\n";
    }

    ClassName(ClassName&& a)
    {
        cout << "Move Constructor called.\n";
    }
};

class ClassName2
{
    public:
    ClassName2() = default;
    ClassName2(const ClassName2& b)
    {
        cout << "Copy Constructor called.\n";
    }

    ClassName2(ClassName2&& a) noexcept
    {
        cout << "Move Constructor called.\n";
    }
};

int main()
{
    vector<ClassName> v(10);
    v.resize(v.capacity() + 1);
    
    cout << "\n";
    
    vector<ClassName2> v2(10);
    v2.resize(v2.capacity() + 1);

    return 0;
}

/*
OUTPUT:

Copy called if there is any chance of move constructor failing. 
->Atomicity needs to be maintained.

Copy Constructor called.
Copy Constructor called.
Copy Constructor called.
Copy Constructor called.
Copy Constructor called.
Copy Constructor called.
Copy Constructor called.
Copy Constructor called.
Copy Constructor called.
Copy Constructor called.

Move Constructor called.
Move Constructor called.
Move Constructor called.
Move Constructor called.
Move Constructor called.
Move Constructor called.
Move Constructor called.
Move Constructor called.
Move Constructor called.
Move Constructor called.
*/