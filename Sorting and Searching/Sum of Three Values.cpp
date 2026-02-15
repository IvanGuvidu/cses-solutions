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

const int max_size = 5e4 + 20, mod = 1e9 + 7;

pair <int, int> v[max_size];

void solve() 
{
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int x = k - v[i].first - v[j].first;
            int l = 1, r = n, pos = 0;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (v[m].first < x)
                {
                    l = m + 1;
                }
                else
                {
                    pos = m;
                    r = m - 1;
                }
            }
            if (pos != 0 && v[pos].first == x && pos != i && pos != j)
            {
                cout << v[i].second << ' ' << v[j].second << ' ' << v[pos].second;
                return;
            }
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