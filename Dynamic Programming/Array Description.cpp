#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
#define lsb(x) (x & (-x))

const long long max_size = 1e5 + 20, vmax = 105, mod = 1e9 + 7;

long long dp[max_size][vmax], v[max_size];

void solve ()
{
    long long n, t;
    cin >> n >> t;
    for (long long i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    if (v[1] == 0)
    {
        for (long long i = 1; i <= t; i++)
        {
            dp[1][i] = 1;
        }
    }
    else
    {
        dp[1][v[1]] = 1;
    }
    for (long long i = 2; i <= n; i++)
    {
        if (v[i] != 0)
        {
            for (long long j = v[i] - 1; j <= v[i] + 1; j++)
            {
                dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][j]) % mod;
            }
            continue;
        }
        for (long long j = 1; j <= t; j++)
        {
            for (long long k = j - 1; k <= j + 1; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
            }
        }
    }
    if (v[n] != 0)
    {
        cout << dp[n][v[n]];
        return;
    }
    long long ans = 0;
    for (long long i = 1; i <= t; i++)
    {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans;
}

signed main ()
{
    #ifdef LOCAL
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long T;
    //cin >> T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}