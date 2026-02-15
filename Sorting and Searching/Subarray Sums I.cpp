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

int v[max_size];

void solve() 
{
    int n;
    long long k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int l = 1;
    long long sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += v[i];
        while (sum > k)
        {
            sum -= v[l];
            l++;
        }
        if (sum == k)
        {
            ans++;
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