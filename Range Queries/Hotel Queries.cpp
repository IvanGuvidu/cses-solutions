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

int v[max_size], seg[max_seg];

void init (int l, int r, int nod)
{
    if (l == r)
    {
        seg[nod] = v[l];
        return;
    }
    int m = (l + r) / 2;
    init(l, m, 2 * nod);
    init(m + 1, r, 2 * nod + 1);
    if (seg[2 * nod] >= seg[2 * nod + 1])
    {
        seg[nod] = seg[2 * nod];
    }
    else
    {
        seg[nod] = seg[2 * nod + 1];
    }
}

int query (int l, int r, int val, int nod)
{
    if (l == r)
    {
        return l;
    }
    int m = (l + r) / 2;
    if (seg[2 * nod] >= val)
    {
        return query(l, m, val, 2 * nod);
    }
    else
    {
        return query(m + 1, r, val, 2 * nod + 1);
    }
}

void upd (int l, int r, int poz, int val, int nod)
{
    if (l == r)
    {
        seg[nod] -= val;
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
    if (seg[2 * nod] >= seg[2 * nod + 1])
    {
        seg[nod] = seg[2 * nod];
    }
    else
    {
        seg[nod] = seg[2 * nod + 1];
    }
}

void solve() 
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    init(1, n, 1);
    while (q--)
    {
        int x;
        cin >> x;
        if (seg[1] < x)
        {
            cout << 0 << " ";
            continue;
        }
        int poz = query(1, n, x, 1);
        cout << poz << " ";
        upd(1, n, poz, x, 1);
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