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

vector <int> mc[max_size];
int sz[max_size];

void dfs (int nod)
{
    sz[nod] = 1;
    for (auto f : mc[nod])
    {
        dfs(f);
        sz[nod] += sz[f];
    }
}

void solve ()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        mc[x].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << sz[i] - 1 << " ";
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