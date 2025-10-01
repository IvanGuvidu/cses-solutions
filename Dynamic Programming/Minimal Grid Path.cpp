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
 
const int INF = 2e9 + 2, max_size = 3e3 + 20;

int a[max_size][max_size], viz[max_size][max_size];
vector <pair <int, int>> nxt;
int ult[max_size][max_size],
dx[] = {1, 0},
dy[] = {0, 1};

void bfs (int n)
{
    nxt.push_back({1, 1});
    while (1)
    {
        vector <pair <int, int>> aux;
        int mn = 30;
        for (auto f : nxt)
        {
            int x = f.first, y = f.second;
            for (int k = 0; k < 2; k++)
            {
                int xv = x + dx[k], yv = y + dy[k];
                if (xv <= n && yv <= n && viz[xv][yv] == 0)
                {
                    viz[xv][yv] = 1;
                    if (a[xv][yv] < mn)
                    {
                        mn = a[xv][yv];
                        aux.clear();
                    }
                    if (a[xv][yv] == mn)
                    {
                        ult[xv][yv] = k;
                        aux.push_back({xv, yv});
                    }
                }
            }
        }
        nxt = aux;
        if (nxt.empty())
        {
            break;
        }
    }
    return;
}

void solve() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = (s[j - 1] - 'A');
            ult[i][j] = -1;
        }
    }
    bfs(n);
    string rez = "";
    int x = n, y = n;
    while (1)
    {
        rez = (char)('A' + a[x][y]) + rez;
        if (x == 1 && y == 1)
        {
            break;
        }
        int k = ult[x][y];
        x -= dx[k];
        y -= dy[k];
    }
    cout << rez;
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