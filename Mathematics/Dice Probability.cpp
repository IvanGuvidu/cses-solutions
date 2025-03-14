#include <iostream>
#include <iomanip>
 
using namespace std;
 
const int max_dp = 1e2 + 1, max_scor = 6e2 + 1;
 
long double dp[max_dp][max_scor];
 
int main ()
{
    int n, a, b;
    cin >> n >> a >> b;
    dp[1][1] = (long double) 1 / 6;
    dp[1][2] = (long double) 1 / 6;
    dp[1][3] = (long double) 1 / 6;
    dp[1][4] = (long double) 1 / 6;
    dp[1][5] = (long double) 1 / 6;
    dp[1][6] = (long double) 1 / 6;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= 6 * i; j++)
        {
            long double s = 0;
            for (int k = 1; k <= min(j - 1, 6); k++)
            {
                s += dp[i - 1][j - k];
            }
            dp[i][j] = (long double) s / 6;
        }
    }
    long double ans = 0;
    for (int i = a; i <= b; i++)
    {
        ans += dp[n][i];
    }
    cout << fixed << setprecision(6) << ans;
    return 0;
}