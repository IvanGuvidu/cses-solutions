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

const int max_size = 2e5 + 20;

int v[max_size], a[max_size], ans[max_size];

void solve() 
{
    int n, q;
    cin >> n >> q;
    set <int> s;
    for (int i = 1; i <= q; i++)
    {
        cin >> v[i];
        a[i] = v[i];
        s.insert(v[i]);
    }
    int rez = 0;
    sort(a + 1, a + q + 1);
    for (int i = 1; i <= q; i++)
    {
        rez = max(rez, a[i] - a[i - 1]);
    }
    rez = max(rez, n - a[q]);
    for (int i = q; i > 0; i--)
    {
        ans[i] = rez;
        auto it = s.find(v[i]);
        int x, y;
        auto it2 = it;
        it2++;
        if (it2 != s.end())
        {
            y = *it2;
        }
        else
        {
            y = n;
        }
        it2 = it;
        if (it2 != s.begin())
        {
            it2--;
            x = *it2;
        }
        else
        {
            x = 0;
        }
        rez = max(rez, y - x);
        s.erase(it);
    }
    for (int i = 1; i <= q; i++)
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