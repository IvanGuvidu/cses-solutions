#include <iostream>
 
using namespace std;
 
#define ll long long
#define pii pair <int,int>
#define pll pair <ll, ll>
#define vi vector <int>
 
const int max_size = 1e2 + 1, max_dp = 1e6 + 1, INF = 1e9;
 
int c[max_size], dp[max_dp];
 
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= t; i++)
    {
        dp[i] = INF;
    }
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - c[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    if (dp[t] == INF)
    {
        dp[t] = -1;
    }
    cout << dp[t];
    return 0;
}