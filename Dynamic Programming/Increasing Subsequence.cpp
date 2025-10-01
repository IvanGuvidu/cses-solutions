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

int v[max_size], best[max_size];

void solve() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        best[i] = INF;
    }
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int e = 25, st = 0;
        while (e >= 0)
        {
            if (st + (1 << e) <= mx && v[i] > best[st + (1 << e)])
            {
                st += (1 << e);
            }
            e--;
        }
        st++;
        best[st] = min(best[st], v[i]);
        mx = max(mx, st);
    }
    cout << mx;
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