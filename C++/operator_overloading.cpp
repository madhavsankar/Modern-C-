#include <bits/stdc++.h>

using namespace std;

class ClassName
{
    double x;
    
    public:
    
    ClassName() = default;
    
    ClassName(double x) : x(x) {}
    
    ClassName(const ClassName& b)
    {
        cout << "Copy Constructor called.\n";
        this->x = b.x;
    }

    ClassName(ClassName&& a)
    {
        cout << "Move Constructor called.\n";
        this->x = a.x;
    }
    
    string toString() const
    {
        return "Value of x is " + to_string(x) + ".\n";
    }
    
    const ClassName& operator=(const ClassName& b)
    {
        cout << "Copy Assignment Operator called.\n";
        this->x = b.x;
        return *this;
    }
    
    ClassName& operator!()
    {
        x = 1 / x;
        return *this;
    }

    // Prefix: ++ClassName
    ClassName& operator++()
    {
        x++;
        cout << "Prefix ++ Operator called.\n";
        return *this;
    }

    // Postfix: ClassName++
    ClassName& operator++(int)
    {
        x++;
        cout << "Postfix ++ Operator called.\n";
        return *this;
    }
    
    friend ClassName operator+(const ClassName& a, const ClassName& b);
};

ostream& operator<<(ostream& out, const ClassName& className)
{
    out << className.toString();
    return out;
}

ClassName operator+(const ClassName& a, const ClassName& b)
{
    return ClassName(a.x + b.x);
}

int main()
{
    ClassName a = ClassName(2);
    
    ClassName b = ClassName(3);
    
    cout << a + b;
    
    cout << !a;

    cout << ++a;
    
    cout << a++;
    
    return 0;
}