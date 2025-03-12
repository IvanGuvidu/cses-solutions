#include <iostream>
#include <string>
 
using namespace std;
 
#define ll long long
#define pii pair <int,int>
#define pll pair <ll, ll>
#define vi vector <int>
 
const int max_size = 1e3 + 1, INF = 1e9, mod = 1e9 + 7;
 
ll dp[max_size][max_size];
string a[max_size];
 
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dp[0][0] = 1;
    if (a[0][0] == '*')
    {
        dp[0][0] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[0][i] == '.')
        {
            dp[0][i] = dp[0][i - 1];
        }
        else
        {
            dp[0][i] = 0;
        }
        if (a[i][0] == '.')
        {
            dp[i][0] = dp[i - 1][0];
        }
        else
        {
            dp[i][0] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] == '.')
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}

