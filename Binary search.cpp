#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 4, 5, 6, 7, 8, 0, 1, 2};
    int n = 9, i = 0, j = n - 1;
    int target = 0;
    int mid = n;

    cin >> target;

    while (i <= j)
    {
        mid = (i + j) / 2; // use this, mid=i+(j-i)/2
        if (j < arr[mid])
        {
            i = mid + 1;
        }
        else if (i > arr[mid])
        {
            j = mid - 1;
        }
        else
        {

            cout << mid << endl;
            break;
        }
    }

    return 0;
}

// Using recursion
/** #include <iostream>
using namespace std;

int recBinary(int arr[], int tar, int st, int ed)
{

    int mid;

    while (st <= ed)
    {
        mid = st + (ed - st) / 2;
        if (tar > arr[mid])
        {
            return recBinary(arr, tar, mid + 1, ed);
        }
        else if (tar < arr[mid])
        {
            return recBinary(arr, tar, st, mid - 1);
        }
        else
        {

            return mid;
        }
    }
}

int main()
{
    int arr[] = {-1, 0, 3, 4, 5, 9, 12};
    int n = 7, i = 0, j = n - 1;
    int target, ans = 0;
    int mid = n;

    target = 12;

    cout << recBinary(arr, target, i, j) << endl;

    return 0;
} */