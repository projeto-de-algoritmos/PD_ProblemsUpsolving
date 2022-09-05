// Problem link: https://cses.fi/problemset/task/1635
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, x;
    cin >> n >> x;
    ll coins[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (ll i = 1; i <= x; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
                dp[i] = (dp[i] + dp[i - coins[j]]) % 1000000007;
        }
    }
    cout << dp[x] << endl;

    return 0;
}
