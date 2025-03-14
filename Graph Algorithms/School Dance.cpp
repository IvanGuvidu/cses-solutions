#include <bits/stdc++.h>
 
using namespace std;
 
const int max_size = 5e2 + 1;
 
int l[max_size], r[max_size], uz[max_size];
vector <int> mc[max_size];
 
bool pairup (int nod)
{
    if (uz[nod])
    {
        return false;
    }
    uz[nod] = 1;
    for (auto f : mc[nod])
    {
        if (r[f] == 0)
        {
            l[nod] = f;
            r[f] = nod;
            return true;
        }
    }
    for (auto f : mc[nod])
    {
        if (pairup(r[f]))
        {
            l[nod] = f;
            r[f] = nod;
            return true;
        }
    }
    return false;
}
 
int main ()
{
    int n, m, q;
    cin >> n >> m >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        mc[x].push_back(y);
    }
    while (1)
    {
        bool ok = false;
        for (int i = 1; i <= n; i++)
        {
            uz[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!l[i])
            {
                ok |= pairup(i);
            }
        }
        if (!ok)
        {
            break;
        }
    }
    int cuplaj = 0;
    for (int i = 1; i <= n; i++)
    {
        if (l[i] > 0)
        {
            cuplaj++;
        }
    }
    cout << cuplaj << '\n';
    for (int i = 1; i <= n; i++)
    {
        if (l[i] > 0)
        {
            cout << i << " " << l[i] << '\n';
        }
    }
    return 0;
}