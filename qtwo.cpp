#include <iostream>
using namespace std;

int main()
{
    int arr1[6] = {5, 7, 8, 9, 1, 2};
    int arr2[5] = {1, 2, 3, 4, 5};
    int s1 = 6, s2 = 5;
    int k = 1, h = 0;
    int arr[s1];
    int target;

    for (int i = 0; i < s1; i++)
    {
        target = arr1[i];
        for (int j = 0; j < s2; j++)
        {
            if (arr2[j] == target)
            {
                arr[h] = target;
                h++;
            }
        }
    }
    for (int i = 0; i < h; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}