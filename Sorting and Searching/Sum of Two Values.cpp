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
 
const int INF = 2e9 + 2, max_size = 2e5 + 20;

int a[max_size];

void solve() 
{
    int n, x, ans1 = -1, ans2 = -1;
    cin >> n >> x;
    map <int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (mp[x - a[i]] != 0)
        {
            ans1 = mp[x - a[i]];
            ans2 = i;
            break;
        }
        mp[a[i]] = i;
    }
    if (ans1 == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << ans1 << " " << ans2;
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