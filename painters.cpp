#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime)
{
    int painters = 1, time = 0;

    for (int i = 0; i < n; i++)
    {
        if (time + arr[i] <= maxAllowedTime)
        {
            time += arr[i];
        }
        else
        {
            painters++;
            time = arr[i];
        }
    }
    return painters <= m;
}

int minTimeToPaints(vector<int> &arr, int n, int m)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int st = arr[0], ed = sum, ans = -1; /** intesd of st=arr[0],we can find the max
                                         lengthed(i.e 40) because min time should be 40
                                         and we can find our time in 40-sum ***/

    while (st <= ed)
    {
        int mid = st + (ed - st) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            ed = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 40, 30, 20, 10};
    int n = 5, m = 2;

    cout << minTimeToPaints(arr, n, m) << endl;
}
