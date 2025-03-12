#include <iostream>
 
using namespace std;
 
#define ll long long
#define pii pair <int,int>
#define pll pair <ll, ll>
#define vi vector <int>
 
const int max_dp = 1e6 + 1, INF = 1e9, mod = 1e9 + 7;
 
int dp[max_dp];
 
int ans (int n)
{
    int x = n, rez = INF;
    while (x > 0)
    {
        int r = x % 10;
        if (r != 0)
        {
            rez = min(rez, dp[n - r]);
        }
        x /= 10;
    }
    if (rez == INF)
    {
        rez = 0;
    }
    return rez;
}
 
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = ans(i) + 1;
    }
    cout << dp[n];
    return 0;
}