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

const long long max_size = 1e3 + 20;

int m, n, viz[max_size][max_size], v[max_size][max_size],
dx[] = {-1, 0, 1, 0},
dy[] = {0, 1, 0, -1};
queue <pair <int, int>> q;

void lee (int x, int y)
{
    q.push({x, y});
    viz[x][y] = 1;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int xv = x + dx[k], yv = y + dy[k];
            if (xv > 0 && yv > 0 && xv <= n && yv <= m && viz[xv][yv] == 0 && v[xv][yv] == 0)
            {
                viz[xv][yv] = viz[x][y] + 1;
                q.push({xv, yv});
            }
        }
    }
}

void solve ()
{
    cin >> n >> m;
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
            {
                v[i][j + 1] = -1;
                continue;
            }
            if (s[j] == 'A')
            {
                x1 = i;
                y1 = j + 1;
            }
            if (s[j] == 'B')
            {
                x2 = i;
                y2 = j + 1;
            }
        }
    }
    lee(x1, y1);
    if (viz[x2][y2] == 0)
    {
        cout << "NO";
        return;
    }
    vector <char> ans;
    int x = x2, y = y2;
    while (1)
    {
        if (x == x1 && y == y1)
        {
            break;
        }
        for (int k = 0; k < 4; k++)
        {
            int xv = x - dx[k], yv = y - dy[k];
            if (xv > 0 && yv > 0 && xv <= n && yv <= m && viz[xv][yv] + 1 == viz[x][y] && v[xv][yv] == 0)
            {
                if (k == 0)
                {
                    ans.push_back('U');
                }
                if (k == 1)
                {
                    ans.push_back('R');
                }
                if (k == 2)
                {
                    ans.push_back('D');
                }
                if (k == 3)
                {
                    ans.push_back('L');
                }
                x = xv;
                y = yv;
                break;
            }
        }
    }
    cout << "YES" << '\n' << viz[x2][y2] - 1 << '\n';
    reverse(ans.begin(), ans.end());
    for (auto f : ans)
    {
        cout << f;
    }
    cout << '\n';
}

signed main ()
{
    #ifdef LOCAL
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long T;
    //cin >> T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}