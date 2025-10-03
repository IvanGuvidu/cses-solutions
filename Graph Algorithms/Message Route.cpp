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

int ult[max_size], viz[max_size];
vector <int> mc[max_size];

void bfs()
{
    queue <int> q;
    q.push(1);
    viz[1] = 1;
    while (!q.empty())
    {
        int nod = q.front();
        q.pop();
        for (auto f : mc[nod])
        {
            if (viz[f] == 0)
            {
                viz[f] = 1;
                ult[f] = nod;
                q.push(f);
            }
        }
    }
}

void solve() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ult[i] = -1;
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        mc[x].push_back(y);
        mc[y].push_back(x);
    }
    bfs();
    if (viz[n] == 0)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    vector <int> ans;
    int nod = n;
    while (nod != 1)
    {
        ans.push_back(nod);
        nod = ult[nod];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto f : ans)
    {
        cout << f << " ";
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