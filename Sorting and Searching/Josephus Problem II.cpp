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

const int max_size = 2e5 + 20, mod = 1e9 + 7;

int seg[4 * max_size];

void init (int l, int r, int nod)
{
    if (l == r)
    {
        seg[nod] = 1;
        return;
    }
    int m = (l + r) / 2;
    init(l, m, 2 * nod);
    init(m + 1, r, 2 * nod + 1);
    seg[nod] = seg[2 * nod] + seg[2 * nod + 1];
}

int upd (int l, int r, int poz, int nod)
{
    if (l == r)
    {
        seg[nod] = 0;
        return l;
    }
    int m = (l + r) / 2;
    seg[nod]--;
    if (poz <= seg[2 * nod])
    {
        return upd(l, m, poz, 2 * nod);
    }
    else
    {
        return upd(m + 1, r, poz - seg[2 * nod], 2 * nod + 1);
    }
}

void solve() 
{
    int n, k;
    cin >> n >> k;
    init(1, n, 1);
    int poz = 1;
    for (int i = 1; i <= n; i++)
    {
        poz = (poz + k) % (n - i + 1);
        if (poz == 0)
        {
            poz = n - i + 1;
        }
        cout << upd(1, n, poz, 1) << " ";
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