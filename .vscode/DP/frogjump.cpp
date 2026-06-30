#include <iostream>
#include <vector>
using namespace std;
int INT_MAX = 1e9;
// tabulation method
int main()
{ // time complexity 0(n) and space complexity 0(1) 
    vector<int> cost = {30, 10, 60, 10, 60, 50};
    int n = cost.size();
    // vector<int> dp(n, -1);

    int prev = 0;
    int prev2 = 0;

    for (int i = 0; i < n; i++)
    {
        int fs = prev + abs(cost[i] - cost[i - 1]);
        int Ss = INT_MAX;
        if (i > 1)
        {
            Ss = prev2 + abs(cost[i] - cost[i - 2]);
        }

        int curr = min(fs, Ss);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}