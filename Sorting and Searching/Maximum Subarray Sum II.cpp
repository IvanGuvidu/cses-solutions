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

const long long max_size = 2e5 + 20, mod = 1e9 + 7, INF = 1e18;

long long v[max_size], sp[max_size];
deque <long long> dq;

void solve ()
{
    long long n, l, r;
    cin >> n >> l >> r;
    for (long long i = 1; i <= n; i++)
    {
        cin >> v[i];
        sp[i] = sp[i - 1] + v[i];
    }
    long long ans = -INF;
    for (long long i = 1; i <= n; i++)
    {
        if (i - l >= 0)
        {
            while (!dq.empty() && sp[dq.back()] > sp[i - l])
            {
                dq.pop_back();
            }
            dq.push_back(i - l);
        }
        if (!dq.empty())
        {
            ans = max(ans, sp[i] - sp[dq.front()]);
        }
        if (!dq.empty() && dq.front() == i - r)
        {
            dq.pop_front();
        }
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