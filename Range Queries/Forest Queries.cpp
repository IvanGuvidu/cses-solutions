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
 
const int INF = 2e9 + 2, max_size = 1e3 + 20;

int a[max_size][max_size], sp[max_size][max_size];

void solve() 
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            if (s[j - 1] == '*')
            {
                a[i][j] = 1;
            }
            sp[i][j] = sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1] + a[i][j];
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sp[x2][y2] - sp[x1 - 1][y2] - sp[x2][y1 - 1] + sp[x1 - 1][y1 - 1] << '\n';
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