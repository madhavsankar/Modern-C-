#include <bits/stdc++.h>

using namespace std;

class ClassName
{
    int x = 1;
    int y = 2;

public:
    void printValues()
    {
        // Capture this. (Always as reference).
        auto fun = [this](){
            cout << x << " " << y << "\n";
        };
        
        fun();
    }
};

int main()
{
    // Lambda captures
    int x = 0, y = 0;
    
    auto print = [x, &y]() -> void { 
        cout << x << " " << y << "\n";
    };
    // x value copied into another variable here.
    // y is passed by reference.
    
    print();
    
    x = 1;
    y = 1;
    
    print();
    
    // Default and override
    auto print2 = [=, &y]() -> void { 
        cout << x << " " << y << "\n";
    };
    
    x = 2;
    y = 2;
    
    print2();
    
    auto print3 = [&, x]() -> void { 
        cout << x << " " << y << "\n";
        y = 4; // Works
        // x = 5; Error
    };
    
    x = 3;
    y = 3;
    
    print3();
    
    return 0;
}

/*
OUTPUT:
x y
0 0
0 1
1 2
2 3
*/