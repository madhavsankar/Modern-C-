#include <bits/stdc++.h>

using namespace std;

class ClassName
{
    
};

void fun(const ClassName& c)
{
    cout << "Read-only Access.\n";
}

void fun(ClassName& c)
{
    cout << "Write Accesss.\n";
}

void fun(ClassName&& c)
{
    cout << "Move Accesss.\n";
}

template<typename T>
void callFun(T&& c)
{
    fun(forward<T>(c));
}

int main() {
    ClassName c;
    const ClassName constC;
    
    callFun(constC);
    callFun(c);
    callFun(move(c));
    
    return 0;
}