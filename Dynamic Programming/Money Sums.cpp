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

const long long max_size = 1e2 + 20, mod = 1e9 + 7, INF = 1e18, vmax = 1e7 + 5;

int dp[vmax], v[max_size];

void solve ()
{
    int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        s += v[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= v[i]; j--)
        {
            if (dp[j - v[i]] == 1)
            {
                dp[j] = 1;
            }
        }
    }
    vector <int> ans;
    for (int i = 1; i <= s; i++)
    {
        if (dp[i] == 1)
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto f : ans)
    {
        cout << f << " ";
    }
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