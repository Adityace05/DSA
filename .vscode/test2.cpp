#include <iostream>
#include <vector>
#include <string>
using namespace std;
int pivInd(vector<int> &arr, int st, int ed)
{
    int ind = st - 1;
    int piv = arr[ed];

    for (int i = st; i < ed; i++)
    {
        if (arr[i] <= arr[ed])
        {
            swap(arr[i], arr[ind]);
            ind++;
        }
    }

    ind++;
    swap(arr[ind], piv);
    return piv;
}

void quickSort(vector<int> &arr, int st, int ed)
{
    if (st < ed)
    {
        int piv = pivInd(arr, );
        quickSort(arr, st, piv - 1);
        quickSort(arr, piv + 1, ed);
    }
}
int main()
{
    vector<int> arr = {1, 5, 2, 7, 3, 8, 0} int n = arr.size() - 1;

    quickSort(arr, 0, );
}