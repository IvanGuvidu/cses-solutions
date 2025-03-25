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

const long long max_size = 1e5 + 20, mod = 1e9 + 7;

struct str{
    long long x, y, c;
    bool operator < (const str & aux) const
    {
        return c < aux.c;
    }
};

long long t[max_size];
vector <str> mc;

long long rad (long long x)
{
    if (t[x] == x)
    {
        return x;
    }
    return t[x] = rad(t[x]);
}

void solve ()
{
    long long n, m;
    cin >> n >> m;
    while (m--)
    {
        long long x, y, c;
        cin >> x >> y >> c;
        mc.push_back({x, y, c});
    }
    sort(mc.begin(), mc.end());
    for (long long i = 1; i <= n; i++)
    {
        t[i] = i;
    }
    long long ans = 0, ct = 0;
    for (auto f : mc)
    {
        long long rx = rad(f.x), ry = rad(f.y);
        if (rx != ry)
        {
            ct++;
            ans += f.c;
            t[rx] = ry;
        }
    }
    if (ct != n - 1)
    {
        cout << "IMPOSSIBLE";
        return;
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