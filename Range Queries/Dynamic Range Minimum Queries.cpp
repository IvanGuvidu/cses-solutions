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
 
const int INF = 2e9 + 2, max_size = 2e5 + 20, max_seg = 8e5 + 20;

int seg[max_seg];

void upd (int l, int r, int poz, int val, int nod)
{
    if (l == r)
    {
        seg[nod] = val;
        return;
    }
    int m = (l + r) / 2;
    if (poz <= m)
    {
        upd(l, m, poz, val, 2 * nod);
    }
    else
    {
        upd(m + 1, r, poz, val, 2 * nod + 1);
    }
    seg[nod] = min(seg[2 * nod], seg[2 * nod + 1]);
}

int query (int l, int r, int st, int dr, int nod)
{
    if (st <= l && r <= dr)
    {
        return seg[nod];
    }
    int m = (l + r) / 2, ans1 = INF, ans2 = INF;
    if (st <= m)
    {
        ans1 = query(l, m, st, dr, 2 * nod);
    }
    if (dr > m)
    {
        ans2 = query(m + 1, r, st, dr, 2 * nod + 1);
    }
    return min(ans1, ans2);
}

void solve() 
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        upd(1, n, i, x, 1);
    }
    while (q--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            upd(1, n, x, y, 1);
        }
        else
        {
            cout << query(1, n, x, y, 1) << '\n';
        }
    }
}
  
signed main() 
{ 
#ifdef LOCAL 
    freopen("test.in", "r", stdin); 
    freopen("test.out", "w", stdout); 
#endif // LOCAL 
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0); 
    long long tt; 
    //cin >> tt; 
    tt = 1; 
    while (tt--) 
    { 
        solve(); 
    } 
    return 0; 
}