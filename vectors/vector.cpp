#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int n = 5, h, sum = 0, max = -1000;
    int arr[5] = {1, 2, 3, 4, 5};
    int num[15];

    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            num[h] = sum;
            h++;
            sum = 0;
        }
    }
    for (int i = 0; i < 15; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
        }
    }
    cout << max << endl;
    return 0;
}