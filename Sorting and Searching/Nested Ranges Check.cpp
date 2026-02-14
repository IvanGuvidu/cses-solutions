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

struct str{
    int l, r, idx;
};

int ans[max_size];
str v[max_size];

bool cmp1 (str x, str y)
{
    if (x.l != y.l)
    {
        return x.l < y.l;
    }
    return x.r > y.r;
}

bool cmp2 (str x, str y)
{
    if (x.r != y.r)
    {
        return x.r < y.r;
    }
    return x.l > y.l;
}

void solve() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].l >> v[i].r;
        v[i].idx = i;
    }
    sort(v + 1, v + n + 1, cmp2);
    int mxl = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].l <= mxl)
        {
            ans[v[i].idx] = 1;
        }
        mxl = max(mxl, v[i].l);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
        ans[i] = 0;
    }
    cout << "\n";
    sort(v + 1, v + n + 1, cmp1);
    int mxr = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].r <= mxr)
        {
            ans[v[i].idx] = 1;
        }
        mxr = max(mxr, v[i].r);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
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