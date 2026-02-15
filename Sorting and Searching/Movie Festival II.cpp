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

pair <int, int> v[max_size];

void solve ()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v + 1, v + n + 1);
    multiset <int> s;
    int ans = k;
    for (int i = 1; i <= k; i++)
    {
        s.insert(v[i].second);
    }
    for (int i = k + 1; i <= n; i++)
    {
        auto it = s.begin();
        if (*it <= v[i].first)
        {
            s.erase(it);
            s.insert(v[i].second);
            ans++;
            continue;
        }
        auto it2 = s.rbegin();
        if (*it2 > v[i].second)
        {
            s.erase(--s.end());
            s.insert(v[i].second);
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