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

int v[max_size];
map <int, int> fr;

void solve() 
{
    int n;
    cin >> n;
    int l = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        fr[v[i]]++;
        while (fr[v[i]] > 1)
        {
            fr[v[l]]--;
            l++;
        }
        ans += i - l + 1;
    }
    cout << ans;
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