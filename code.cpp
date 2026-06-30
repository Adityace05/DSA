
#include <iostream>
using namespace std;

long long fact(int x)
{
    long long fact = 1;
    for (int i = 1; i <= x; i++)
    {
        fact *= i;
    }

    // cout << fact << '\n';

    return fact;
}

float ncr(int n, int r)
{
    long long fact_n = fact(n);
    long long fact_r = fact(r);
    long long fact_nr = fact(n - r);

    // cout << fact_n << '\t' << fact_r << '\t' << fact_nr << '\n';

    return (float)fact_n / (fact_r * fact_nr);
}

int main()
{
    int n = 20, r;
    cin >> r;

    cout << ncr(n, r) << endl;
    return 0;
}