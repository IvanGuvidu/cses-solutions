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

struct str{
    int x, room;
    bool operator < (const str &other) const{
        return x > other.x;
    }
};

struct interval {
    int x, y, idx;
    bool operator < (const interval &other) const {
        return x < other.x;
    }
};

priority_queue<str> pqliber, pqocup;
int ans[max_size];
interval v[max_size];

void solve() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        pqliber.push({i, i});
    }
    int mx = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].x >> v[i].y;
        v[i].idx = i;
    }
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        x = v[i].x;
        y = v[i].y;
        while (!pqocup.empty() && pqocup.top().x < x)
        {
            int room = pqocup.top().room;
            pqocup.pop();
            pqliber.push({room, room});
        }
        mx = max(mx, pqliber.top().x);
        ans[v[i].idx] = pqliber.top().room;
        pqocup.push({y, pqliber.top().room});
        pqliber.pop();
    }
    cout << mx << "\n";
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