#include <bits/stdc++.h>

using namespace std;

class ClassName
{
    public:
    ClassName()
    {
        cout << "Constructor called.\n";
    }
    
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
    
    ~ClassName()
    {
        cout << "Destructor called.\n";
    }
};

int main()
{
    stack<ClassName> st;
    
    cout<<"Push:\n";
    st.push(ClassName());
    cout<<"\n";
    
    cout<<"Top Copy:\n";
    ClassName temp = st.top();
    cout<<"\n";
    
    cout<<"Top Reference:\n";
    ClassName& temp2 = st.top();
    // If we pop it, do not use the reference.
    cout<<"\n";
    
    cout<<"Pop:\n";
    st.pop();
    cout<<"\n";

    return 0;
}

/*
OUTPUT:

Push:
Constructor called.
Move Constructor called.
Destructor called. // Temporary ClassName object destroyed.

Top Copy:
Copy Constructor called.

Top Reference:

Pop:
Destructor called. // Popped ClassName object destroyed

Destructor called. // Temporary ClassName object created in Top Copy destroyed
*/