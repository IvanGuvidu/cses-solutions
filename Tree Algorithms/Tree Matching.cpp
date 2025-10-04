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

int dp[2][max_size];
// 0 - uncoupled
// 1 - coupled
vector <int> mc[max_size];

void dfs (int nod, int par)
{
    for (auto f : mc[nod])
    {
        if (f == par)
        {
            continue;
        }
        dfs(f, nod);
        dp[0][nod] += max(dp[0][f], dp[1][f]);
    }
    for (auto f : mc[nod])
    {
        if (f == par)
        {
            continue;
        }
        dp[1][nod] = max(dp[1][nod], dp[0][nod] + dp[0][f] + 1 - max(dp[0][f], dp[1][f]));
    }
}

void solve() 
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mc[x].push_back(y);
        mc[y].push_back(x);
    }
    dfs(1, 0);
    cout << max(dp[0][1], dp[1][1]);
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