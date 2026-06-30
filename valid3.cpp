#include <iostream>

using namespace std;

int b10tob3(int n)
{
    int r = 0;
    int p = 1;
    while (n)
    {
        int k = n % 3;
        r = p * k + r;
        p *= 10;
        n /= 3;
    }

    return r;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    // cout << b10tob3(n) << '\n';
    n = b10tob3(n);

    while (n && ((n % 10) == 0))
    {
        n /= 10;
    }

    if (n % 10 == 1)
    {
        n /= 10;

        if (n == 0)
        {
            cout << "power of 3";
            return 0;
        }
    }

    cout << "not a power of 3";
    return 0;
}