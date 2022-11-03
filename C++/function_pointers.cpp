#include <bits/stdc++.h>

using namespace std;

bool isPositive(int x)
{
    return (x > 0);
}

bool isEven(int x)
{
    return ((x % 2) == 0);
}

int count(vector<int>& values, bool (*check)(int x))
{
    int ans = 0;
    
    for (int num : values)
    {
        ans += check(num);
    }
    
    return ans;
}

int main()
{
    bool (*funptr)(int) = isPositive;
    cout << funptr(5) << "\n";
    
    vector<int> values {1, 2, -1, -7, 3, -6, 5};
    
    cout << count(values, isPositive) << "\n";
    cout << count(values, isEven) << "\n";
    
    return 0;
}