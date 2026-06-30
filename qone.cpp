#include <iostream>
using namespace std;

int main()
{
    int num[] = {5, 5, 22, 1, 5, 22};
    int num2[6];
    int j = 1;
    num2[0] = num[0];

    // After sorting
    int num3[] = {1, 5, 5, 5, 22, 22};
    int v = num3[0];

    for (int i = 0; i < 6; i++)
    {
        if (v != num3[i])
        {
            num2[j] = num3[i];
        }
    }

    return 0;
}
