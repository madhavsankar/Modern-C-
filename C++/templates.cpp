#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Printer
{
    T x;
    
    public:
    
    Printer(T x) : x(x) {}
    
    T GetValue() const
    {
        return x;
    }
    
    void print() const
    {
        cout << "Value of x is " << x << ".\n";
    }
};

class ClassName
{
    double x;
    
    public:
    
    ClassName(double x) : x(x) {}
    
    string toString() const
    {
        return "ClassValue: " + to_string(x);
    }
};

ostream& operator<<(ostream& out, const ClassName& className)
{
    out << className.toString();
    return out;
}


int main()
{
    Printer<double> a(2);
    Printer<string> b("hi");
    Printer<ClassName> c(ClassName(2));
    
    a.print();
    b.print();
    c.print();
    
    return 0;
}