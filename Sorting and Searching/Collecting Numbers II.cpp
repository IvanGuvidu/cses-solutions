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

long long v[max_size], poz[max_size];

void solve() 
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        poz[v[i]] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (poz[i] < poz[i - 1])
        {
            ans++;
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        set <pair <int, int>> upd;
        if (v[x] > 1)
        {
            upd.insert({v[x] - 1, v[x]});
        }
        if (v[x] < n)
        {
            upd.insert({v[x], v[x] + 1});
        }
        if (v[y] > 1)
        {
            upd.insert({v[y] - 1, v[y]});
        }
        if (v[y] < n)
        {
            upd.insert({v[y], v[y] + 1});
        }
        for (auto f : upd)
        {
            if (poz[f.second] < poz[f.first])
            {
                ans--;
            }
        }
        swap(v[x], v[y]);
        poz[v[x]] = x;
        poz[v[y]] = y;
        for (auto f : upd)
        {
            if (poz[f.second] < poz[f.first])
            {
                ans++;
            }
        }
        cout << ans;
        cout << "\n";
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