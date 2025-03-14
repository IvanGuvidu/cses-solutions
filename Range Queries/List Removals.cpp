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
 
const int max_size = 2e5 + 20, max_seg = 8e5 + 20;
 
int apos[max_seg], v[max_size];
 
void init (int l, int r, int nod)
{
    if (l == r)
    {
        apos[nod] = 1;
        return;
    }
    int m = (l + r) / 2;
    init(l, m, 2 * nod);
    init(m + 1, r, 2 * nod + 1);
    apos[nod] = apos[2 * nod] + apos[2 * nod + 1];
}
 
int query (int l, int r, int val, int nod)
{
    if (l == r)
    {
        return l;
    }
    int m = (l + r) / 2;
    if (val <= apos[2 * nod])
    {
        return query(l, m, val, 2 * nod);
    }
    return query(m + 1, r, val - apos[2 * nod], 2 * nod + 1);
}
 
void upd (int l, int r, int pos, int nod)
{
    if (l == r)
    {
        apos[nod] = 0;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m)
    {
        upd(l, m, pos, 2 * nod);
    }
    else
    {
        upd(m + 1, r, pos, 2 * nod + 1);
    }
    apos[nod] = apos[2 * nod] + apos[2 * nod + 1];
}
 
void solve ()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    init(1, n, 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int pos = query(1, n, x, 1);
        cout << v[pos] << " ";
        upd(1, n, pos, 1);
    }
}
 
int main ()
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