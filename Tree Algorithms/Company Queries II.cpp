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
 
const int INF = 2e9 + 2, max_size = 2e5 + 20, rmax = 23;

int rmq[rmax][2 * max_size], lvl[max_size], poz[max_size], lg[2 * max_size], timp;
vector <int> mc[max_size];

bool cmp (int x, int y)
{
    return lvl[x] < lvl[y];
}

void dfs (int nod)
{
    timp++;
    rmq[0][timp] = nod;
    poz[nod] = timp;
    for (auto f : mc[nod])
    {
        lvl[f] = lvl[nod] + 1;
        dfs(f);
        rmq[0][++timp] = nod;
    }
}

void solve() 
{
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        mc[x].push_back(i);
    }
    dfs(1);
    for (int i = 2; i <= timp; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    for (int e = 1; e < rmax; e++)
    {
        for (int i = 1; i + (1 << e) - 1 <= timp; i++)
        {
            rmq[e][i] = min(rmq[e - 1][i], rmq[e - 1][i + (1 << (e - 1))], cmp);
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x = poz[x];
        y = poz[y];
        if (x > y)
        {
            swap(x, y);
        }
        int diff = y - x + 1, e = lg[diff];
        cout << min(rmq[e][x], rmq[e][y - (1 << e) + 1], cmp) << '\n';
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