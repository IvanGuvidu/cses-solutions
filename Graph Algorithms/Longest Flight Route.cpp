#include <bits/stdc++.h>
 
using namespace std;
 
const long long max_size = 1e5 + 1, INF = -1e9 + 1;
 
vector <long long> mc[max_size], topsort, sol;
long long dp[max_size], uz[max_size], ult[max_size];
 
void dfs (long long nod)
{
    //cout << nod << " ";
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
        dp[i] = INF;
        if (!uz[i])
        {
            //cout << i << " ";
            dfs(i);
        }
    }
    reverse(topsort.begin(), topsort.end());
    dp[1] = 1;
    /*
    for (auto f : topsort)
    {
        //cout << f << " ";
    }
    */
    for (auto f : topsort)
    {
        //cout << f << " ";
        if (mc[f].size() == 0)
            continue;
        for (auto ff : mc[f])
        {
            if (dp[ff] < dp[f] + 1)
            {
                dp[ff] = dp[f] + 1;
                ult[ff] = f;
            }
        }
    }
    if (dp[n] <= 0)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        int ind = n;
        while (ind != 1)
        {
            sol.push_back(ind);
            ind = ult[ind];
        }
        reverse(sol.begin(), sol.end());
        cout << sol.size() + 1 << '\n' << 1 << " ";
        for (auto f : sol)
        {
            cout << f << " ";
        }
    }
    return 0;
}