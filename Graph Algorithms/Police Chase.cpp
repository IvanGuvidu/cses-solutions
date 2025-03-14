#include <bits/stdc++.h>
 
using namespace std;
 
const int max_size = 5e2 + 1, INF = 1e9 + 1;
 
int cap[max_size][max_size], viz[max_size], t[max_size], n, afisat[max_size][max_size];
vector <int> mc[max_size];
 
bool bfs ()
{
    for (int i = 1; i <= n; i++)
    {
        viz[i] = 0;
        t[i] = 0;
    }
    viz[1] = 1;
    queue <int> q;
    q.push(1);
    while (!q.empty())
    {
        int nod = q.front();
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
 
void mincut ()
{
    for (int i = 1; i <= n; i++)
    {
        viz[i] = 0;
    }
    viz[1] = 1;
    queue <int> q;
    q.push(1);
    while (!q.empty())
    {
        int nod = q.front();
        q.pop();
        for (auto f : mc[nod])
        {
            if (!viz[f] && cap[nod][f] > 0)
            {
                viz[f] = 1;
                q.push(f);
            }
        }
    }
}
 
int main ()
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        mc[x].push_back(y);
        mc[y].push_back(x);
        cap[x][y]++;
        cap[y][x]++;
    }
    int ans = 0;
    while (bfs())
    {
        for (auto f : mc[n])
        {
            if (!viz[f] || cap[f][n] <= 0)
            {
                continue;
            }
            t[n] = f;
            int nod = n, mn = INF;
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
    cout << ans << '\n';
    mincut();
    for (int i = 1; i <= n; i++)
    {
        //cout << viz[i] << " ";
        for (auto f : mc[i])
        {
            if (afisat[i][f] || afisat[f][i])
            {
                continue;
            }
            if (viz[i] == 1 && viz[f] == 0)
            {
                cout << i << " " << f << '\n';
                afisat[i][f] = 1;
                afisat[f][i] = 1;
            }
        }
    }
    return 0;
}