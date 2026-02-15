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

const int max_size = 1e4 + 20, mod = 1e9 + 7;

unordered_map<long long, pair <int, int>> mp;
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
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            long long sum = v[i] + v[j];
            if (mp.find(k - sum) != mp.end())
            {
                cout << mp[k - sum].first << " " << mp[k - sum].second << " " << i << " " << j;
                return;
            }
        }
        for (int j = 1; j < i; j++)
        {
            mp[v[i] + v[j]] = {j, i};
        }
    }
    cout << "IMPOSSIBLE";
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