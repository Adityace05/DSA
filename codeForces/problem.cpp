#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        long long n;
        cin >> n;
        long long ans = 4LL * n * n - 4LL * n + 1LL;
        cout << ans << '\n';
    }
    return 0;
}
