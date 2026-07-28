#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    vector<int> arr = {6, 8, 0, 1, 3};
    int n = arr.size();
    vector<int> ans;
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) // 0(n) not 0(n^2)
    {
        while (s.size() > 0 && s.top() <= arr[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}