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

long long v[max_size];

void solve() 
{
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    long long l = 1, r = 1e18, ans = 0;
    while (l <= r)
    {
        long long m = (l + r) / 2, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += m / v[i];
            if (sum >= k)
            {
                break;
            }
        }
        if (sum < k)
        {
            l = m + 1;
        }
        else
        {
            ans = m;
            r = m - 1;
        }
    }
    cout << ans << "\n";
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