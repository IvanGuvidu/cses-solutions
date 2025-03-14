#include <bits/stdc++.h>
 
using namespace std;
 
const long long max_size = 1e5 + 1, mod = 1e9 + 7;
 
vector <long long> mc[max_size], invmc[max_size], topsort;
long long dp[max_size], uz[max_size];
 
void dfs (long long nod)
{
    uz[nod] = 1;
    for (auto f : mc[nod])
    {
        if (uz[f] == 0)
        {
            dfs(f);
        }
    }
    topsort.push_back(nod);
}
 
int main ()
{
    long long n, m;
    cin >> n >> m;
    while (m--)
    {
        long long x, y;
        cin >> x >> y;
        mc[x].push_back(y);
    }
    dp[1] = 1;
    for (long long i = 1; i <= n; i++)
    {
        if (!uz[i])
        {
            dfs(i);
        }
    }
    reverse(topsort.begin(), topsort.end());
    for (auto f : topsort)
    {
        for (auto ff : mc[f])
        {
            dp[ff] = (dp[ff] + dp[f]) % mod;
        }
    }
    cout << dp[n];
    return 0;
}