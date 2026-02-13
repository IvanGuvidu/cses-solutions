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

const int max_size = 2e5 + 20, mod = 1e9 + 7;

int v[max_size], inv[max_size];
map <int, int> fr;

long long lgput (long long baza, long long ord)
{
    long long ans = 1;
    while (ord > 0)
    {
        if (ord % 2 == 1)
        {
            ans = (ans * baza) % mod;
        }
        baza = (baza * baza) % mod;
        ord /= 2;
    }
    return ans;
}

void solve() 
{
    long long n;
    cin >> n;
    long long ans = 1;
    for (long long i = 1; i <= n; i++)
    {
        inv[i] = lgput(i, mod - 2);
    }
    for (long long i = 1; i <= n; i++)
    {
        cin >> v[i];
        fr[v[i]]++;
        ans = (ans * inv[fr[v[i]]]) % mod;
        ans = (ans * (fr[v[i]] + 1)) % mod;
    }
    ans -= 1;
    if (ans < 0)
    {
        ans += mod;
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