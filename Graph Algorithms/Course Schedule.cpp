#include <bits/stdc++.h>
 
using namespace std;
 
const int max_size = 1e5 + 1;
 
vector <int> mc[max_size], topsort;
int uz[max_size];
 
void dfs (int nod)
{
    //cout << nod << " ";
    uz[nod] = 1;
    for (auto f : mc[nod])
    {
        if (!uz[f])
        {
            dfs(f);
        }
    }
    topsort.push_back(nod);
}
 
int main ()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        mc[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!uz[i])
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        uz[i] = 0;
    }
    bool ok = true;
    reverse(topsort.begin(), topsort.end());
    for (auto f : topsort)
    {
        //cout << f << " ";
        uz[f] = 1;
        for (auto ff : mc[f])
        {
            if (uz[ff] == 1)
            {
                //cout << f << " " << ff << '\n';
                ok = false;
                break;
            }
        }
    }
    if (!ok)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (auto f : topsort)
        {
            cout << f << " ";
        }
    }
    return 0;
}