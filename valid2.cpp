#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    while (n != 0 && ((n & 1) == 0))
    {
        n >>= 1;
    }

    if (n == 0)
    {
        cout << "not a power of 2\n";
        return 0;
    }

    if (n & 1 == 1)
    {
        n >>= 1;

        if (n != 0)
        {
            cout << "not a power of 2\n";
        }
        else
        {
            cout << "power of 2\n";
        }
    }
    else
    {
    }
    return 0;
}