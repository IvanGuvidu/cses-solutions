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

vector <int> mc[max_size];
int ans[max_size], mxdown[2][max_size], best[max_size];

void dfsdown (int nod, int par)
{
    for (auto f : mc[nod])
    {
        if (f == par)
        {
            continue;
        }
        dfsdown(f, nod);
        if (mxdown[0][f] + 1 > mxdown[0][nod])
        {
            mxdown[1][nod] = mxdown[0][nod];
            mxdown[0][nod] = mxdown[0][f] + 1;
            best[nod] = f;
        }
        else
        {
            if (mxdown[0][f] + 1 > mxdown[1][nod])
            {
                mxdown[1][nod] = mxdown[0][f] + 1;
            }
        }
    }
}

void dfsup (int nod, int par, int bestup)
{
    ans[nod] = max(mxdown[0][nod], bestup);
    for (auto f : mc[nod])
    {
        if (f == par)
        {
            continue;
        }
        if (f != best[nod])
        {
            dfsup(f, nod, ans[nod] + 1);
        }
        else
        {
            dfsup(f, nod, max(mxdown[1][nod], bestup) + 1);
        }
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
    dfsdown(1, 0);
    dfsup(1, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
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