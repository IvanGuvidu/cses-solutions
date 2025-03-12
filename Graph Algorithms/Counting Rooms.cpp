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

const int max_size = 1e3 + 20;

int viz[max_size][max_size], n, m,
dx[] = {-1, 0, 1, 0},
dy[] = {0, 1, 0, -1};

void dfs (int x, int y)
{
    viz[x][y] = 1;
    for (int k = 0; k < 4; k++)
    {
        int i = x + dx[k], j = y + dy[k];
        if (i > 0 && j > 0 && i <= n && j <= m && viz[i][j] == 0)
        {
            dfs(i, j);
        }
    }
}

void solve ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == '#')
            {
                viz[i][j + 1] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (viz[i][j] == 0)
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
}

int main ()
{
    #ifdef LOCAL
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    //cin >> T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}