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
 
const int INF = 2e9 + 2, max_size = 1e5 + 20;

int viz[max_size], root[max_size];
vector <int> mc[max_size];

void dfs (int nod)
{
    viz[nod] = 1;
    for (auto f : mc[nod])
    {
        if (viz[f] == 0)
        {
            dfs(f);
        }
    }
}

void solve() 
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        mc[x].push_back(y);
        mc[y].push_back(x);
    }
    int ct = 0;
    for (int i = 1; i <= n; i++)
    {
        if (viz[i] == 0)
        {
            ct++;
            root[ct] = i;
            dfs(i);
        }
    }
    vector <pair <int, int>> ans;
    for (int i = 2; i <= ct; i++)
    {
        ans.push_back({root[1], root[i]});
    }
    cout << ct - 1 << '\n';
    for (auto f : ans)
    {
        cout << f.first << " " << f.second << '\n';
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