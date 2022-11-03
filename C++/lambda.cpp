#include <bits/stdc++.h>

using namespace std;

int count(vector<int>& values, function<bool(int)> check) // bool (*check)(int x)
{
    int ans = 0;
    
    for (int num : values)
    {
        ans += check(num);
    }
    
    return ans;
}

bool isPositive(int x)
{
    return (x > 0);
}

class isPowerOf5
{
public:
    bool operator()(int x)
    {
        return (x % 5 == 0);
    }
    
};

int main()
{
    vector<int> values {1, 2, -1, -7, 3, -6, 5};
    
    // Function Pointers
    cout << count(values, isPositive);
    
    cout << "\n";
    
    // Functor
    isPowerOf5 obj;
    cout << count(values, obj);
    
    cout << "\n";
    
    // Lambda Functions
    auto isEven = [](int x) -> bool { 
        return ((x % 2) == 0);
    };
    cout << count(values, isEven);
    
    return 0;
}