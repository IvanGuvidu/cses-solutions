#include <bits/stdc++.h>
 
using namespace std;
 
const long long max_size = 5e2 + 1, INF = 1e9 + 1;
 
long long cap[max_size][max_size], viz[max_size], t[max_size], n, afisat[max_size][max_size];
vector <long long> mc[max_size];
 
bool bfs ()
{
    for (long long i = 1; i <= n; i++)
    {
        viz[i] = 0;
        t[i] = 0;
    }
    viz[1] = 1;
    queue <long long> q;
    q.push(1);
    while (!q.empty())
    {
        long long nod = q.front();
        q.pop();
        for (auto f : mc[nod])
        {
            if (cap[nod][f] > 0 && !viz[f])
            {
                viz[f] = 1;
                t[f] = nod;
                if (f == n)
                {
                    return true;
                }
                q.push(f);
            }
        }
    }
    return false;
}
 
signed main ()
{
    long long m;
    cin >> n >> m;
    while (m--)
    {
        long long x, y, c;
        cin >> x >> y >> c;
        mc[x].push_back(y);
        mc[y].push_back(x);
        cap[x][y] += c;
    }
    long long ans = 0;
    while (bfs())
    {
        for (auto f : mc[n])
        {
            if (!viz[f] || cap[f][n] <= 0)
            {
                continue;
            }
            t[n] = f;
            long long nod = n, mn = INF;
            while (nod != 1)
            {
                mn = min(mn, cap[t[nod]][nod]);
                nod = t[nod];
            }
            ans += mn;
            if (mn <= 0)
            {
                continue;
            }
            nod = n;
            while (nod != 1)
            {
                cap[t[nod]][nod] -= mn;
                cap[nod][t[nod]] += mn;
                nod = t[nod];
            }
        }
    }
    cout << ans;
    return 0;
}