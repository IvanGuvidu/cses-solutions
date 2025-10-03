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

pair <int, int> v[max_size];
int dp[max_size];

bool cmp (pair <int, int> x, pair <int, int> y)
{
    if (x.second != y.second)
    {
        return x.second < y.second;
    }
    return x.first < y.first;
}

void solve() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v + 1, v + n + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int st = 0, e = 25;
        while (e >= 0)
        {
            if (st + (1 << e) < i && v[st + (1 << e)].second <= v[i].first)
            {
                st += (1 << e);
            }
            e--;
        }
        dp[i] = max(dp[i - 1], dp[st] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans;
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