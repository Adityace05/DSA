#include <iostream>
#include <vector>
#include <string>
using namespace std;

class stack
{
    vector<int> v;

public:
    void push(int val)
    { // 0(1)
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v[v.size() - 1];
    }
    bool empty()
    {
        return v.size() == 0;
    }
};

int main()
{
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}