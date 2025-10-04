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
 
const int INF = 2e9 + 2, max_size = 2e5 + 20, rmax = 22;

int t[rmax][max_size];

void solve() 
{
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        cin >> t[0][i];
    }
    for (int e = 1; e < rmax; e++)
    {
        for (int i = 1; i <= n; i++)
        {
            t[e][i] = t[e - 1][t[e - 1][i]];
        }
    }
    while (q--)
    {
        int x, k, e = 21;
        cin >> x >> k;
        while (k > 0)
        {
            if ((1 << e) <= k)
            {
                x = t[e][x];
                k -= (1 << e);
            }
            e--;
        }
        if (x == 0)
        {
            x = -1;
        }
        cout << x << '\n';
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