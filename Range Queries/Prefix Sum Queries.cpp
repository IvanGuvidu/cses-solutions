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
 
const long long INF = 1e18 + 2, max_size = 2e5 + 20, max_seg = 8e5 + 20;

long long seg[max_seg], lazy[max_seg], sp[max_size], v[max_size];

void init (int l, int r, int nod)
{
    if (l == r)
    {
        seg[nod] = sp[l];
        return;
    }
    int m = (l + r) / 2;
    init(l, m, 2 * nod);
    init(m + 1, r, 2 * nod + 1);
    seg[nod] = max(seg[2 * nod], seg[2 * nod + 1]);
}

void push (int l, int r, int nod)
{
    if (l != r)
    {
        seg[2 * nod] += lazy[nod];
        lazy[2 * nod] += lazy[nod];
        seg[2 * nod + 1] += lazy[nod];
        lazy[2 * nod + 1] += lazy[nod];
    }
    lazy[nod] = 0;
}

void upd (int l, int r, int st, int dr, long long val, int nod)
{
    if (st <= l && r <= dr)
    {
        seg[nod] += val;
        lazy[nod] += val;
        return;
    }
    push(l, r, nod);
    int m = (l + r) / 2;
    if (st <= m)
    {
        upd(l, m, st, dr, val, 2 * nod);
    }
    if (dr > m)
    {
        upd(m + 1, r, st, dr, val, 2 * nod + 1);
    }
    seg[nod] = max(seg[2 * nod], seg[2 * nod + 1]);
}

long long query (int l, int r, int st, int dr, int nod)
{
    if (st == 0 && dr == 0)
    {
        return 0;
    }
    if (st <= l && r <= dr)
    {
        return seg[nod];
    }
    push(l, r, nod);
    long long m = (l + r) / 2, ans1 = -INF, ans2 = -INF;
    if (st <= m)
    {
        ans1 = query(l, m, st, dr, 2 * nod);
    }
    if (dr > m)
    {
        ans2 = query(m + 1, r ,st, dr, 2 * nod + 1);
    }
    return max(ans1, ans2);
}

void solve() 
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sp[i] = sp[i - 1] + v[i];
    }
    init(1, n, 1);
    while (q--)
    {
        long long op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            upd(1, n, x, n, y - v[x], 1);
            v[x] = y;
        }
        else
        {
            long long mx = query(1, n, x, y, 1), border = query(1, n, x - 1, x - 1, 1);
            cout << max(mx - border, 0LL) << '\n';
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