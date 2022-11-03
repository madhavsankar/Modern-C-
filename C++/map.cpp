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
    
    const ClassName& operator=(const ClassName& b)
    {
        cout << "Copy Assignment Operator called.\n";
        return *this;
    }
};

class ClassName2
{
    public:
    int x;
    
    ClassName2() = default;
    
    ClassName2(int x)
    {
        this->x = x;
    }
    
    ClassName2(const ClassName2& b)
    {
        cout << "Copy Constructor called.\n";
    }

    ClassName2(ClassName2&& a)
    {
        cout << "Move Constructor called.\n";
    }
    
    const ClassName2& operator=(const ClassName2& b)
    {
        cout << "Copy Assignment Operator called.\n";
        return *this;
    }
    
    bool operator<(const ClassName2& b) const
    {
        // Now x is the key. So 2 objects with same x will be considered same.
        return this->x < b.x;
    }
};

int main()
{
    map<int, ClassName> mp;
    
    mp[2] = ClassName(); 
    cout << "\n";
    
    mp.insert(make_pair(1, ClassName()));
    cout << "\n";
    
    mp.emplace(3, ClassName());
    
    cout << "\n\n\n";
    
    map<ClassName2, int> mp2;
    
    mp2[ClassName2(1)] = 1;
    cout << "\n";
    
    mp2.insert(make_pair(ClassName2(2), 2));
    cout << "\n";
    
    mp2.emplace(ClassName2(), 3);

    return 0;
}

/*
OUTPUT:

I. Object as Value
1. []
Copy Assignment Operator called.

2. insert
Move Constructor called.
Move Constructor called.

3. emplace
Move Constructor called.

II. Object as Key
1. []
Move Constructor called.

2. insert
Move Constructor called.
Move Constructor called.

3. emplace
Move Constructor called.

*/