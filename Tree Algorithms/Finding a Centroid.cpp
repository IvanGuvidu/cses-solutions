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

int sz[max_size];
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
        sz[nod] += sz[f];
    }
    sz[nod]++;
}

int get_centroid (int nod, int par, int total)
{
    for (auto f : mc[nod])
    {
        if (f == par)
        {
            continue;
        }
        if (2 * sz[f] > total)
        {
            return get_centroid(f, nod, total);
        }
    }
    return nod;
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
    int c = get_centroid(1, 0, n);
    cout << c;
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