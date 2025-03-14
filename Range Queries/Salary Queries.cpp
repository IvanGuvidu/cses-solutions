#include <bits/stdc++.h>
 
using namespace std;
 
const int max_size = 2e5 + 1, INF = 1e9;
 
int salariu[max_size];
 
struct arb{
    int l, r, val;
    arb * rs, * ls;
    arb()
    {
        val = 0;
        rs = 0;
        ls = 0;
    }
};
 
arb * t = new arb;
 
void upd (arb * nod, int val, int poz)
{
    if (nod -> l == nod -> r)
    {
        nod -> val += val;
        return;
    }
    nod -> val += val;
    int m = (nod -> l + nod -> r) / 2;
    if (poz <= m)
    {
        if (nod -> ls == 0)
        {
            nod -> ls = new arb;
            nod -> ls -> l = nod -> l;
            nod -> ls -> r = m;
        }
        upd(nod -> ls, val, poz);
    }
    else
    {
        if (nod -> rs == 0)
        {
            nod -> rs = new arb;
            nod -> rs -> l = m + 1;
            nod -> rs -> r = nod -> r;
        }
        upd(nod -> rs, val, poz);
    }
}
 
int querry (arb * nod, int st, int dr)
{
    if (st <= nod -> l && nod -> r <= dr)
    {
        return nod -> val;
    }
    int ans = 0, m = (nod -> l + nod -> r) / 2;
    if (st <= m)
    {
        if (nod -> ls != 0)
        {
            ans += querry(nod -> ls, st, dr);
        }
    }
    if (dr > m)
    {
        if (nod -> rs != 0)
        {
            ans += querry(nod -> rs, st, dr);
        }
    }
    return ans;
}
 
int main ()
{
    t -> l = 1;
    t -> r = INF;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> salariu[i];
        upd(t, 1, salariu[i]);
    }
    while (q--)
    {
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        if (ch == '!')
        {
            upd(t, -1, salariu[x]);
            salariu[x] = y;
            upd(t, 1, y);
        }
        else
        {
            cout << querry(t, x, y) << '\n';
        }
    }
    return 0;
}