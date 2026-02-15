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

const int max_size = 2e5 + 20;

long long v[max_size];

void solve ()
{
    int n, k;
    cin >> n >> k;
    long long mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    long long l = mx, r = 1e18, ans = 0;
    while (l <= r)
    {
        long long m = (l + r) / 2;
        long long sum = 0, ct = 1;
        for (int i = 1; i <= n; i++)
        {
            sum += v[i];
            if (sum > m)
            {
                sum = v[i];
                ct++;
            }
        }
        if (ct <= k)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans << "\n";
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
    int T;
    //cin >> T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}