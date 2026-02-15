#include <bits/stdc++.h> 
 
using namespace std; 

const int max_size = 2e5 + 20, mod = 1e9 + 7;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map <int, int, custom_hash> mp;
int v[max_size];

void solve() 
{
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    int ct = 0, l = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (mp.find(v[i]) == mp.end() || mp[v[i]] == 0)
        {
            ct++;
        }
        mp[v[i]]++;
        while (ct > k)
        {
            mp[v[l]]--;
            if (mp[v[l]] == 0)
            {
                ct--;
            }
            l++;
        }
        ans += (i - l + 1);
    }
    cout << ans << "\n";
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