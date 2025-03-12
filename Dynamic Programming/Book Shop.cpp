#include <iostream>
 
using namespace std;
 
#define ll long long
#define pii pair <int,int>
#define pll pair <ll, ll>
#define vi vector <int>
 
const int max_size = 1e3 + 1, max_dp = 1e5 + 1, INF = 1e9, mod = 1e9 + 7;
 
int p[max_size], a[max_size], dp[max_size][max_dp];
 
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - p[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - p[i]] + a[i]);
            }
        }
    }
    cout << dp[n][t];
    return 0;
}