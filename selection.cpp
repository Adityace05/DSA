#include <iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    int smallest;
    for (int i = 0; i < n; i++)
    {
        smallest = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }
        swap(arr[smallest], arr[i]);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};

    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}