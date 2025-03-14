#include <iostream>
 
using namespace std;
 
const int rmax = 18, max_size = 2e5 + 1;
 
int rmq[rmax][max_size], lg[max_size];
 
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> rmq[0][i];
    }
    for (int i = 2; i <= n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    for (int e = 1; (1 << e) <= n; e++)
    {
        for (int i = 1; i <= n - (1 << e) + 1; i++)
        {
            int l = (1 << (e - 1));
            rmq[e][i] = min(rmq[e - 1][i], rmq[e - 1][i + l]);
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int diff = y - x + 1;
        int l = lg[diff];
        int sh = diff - (1 << l);
        cout << min(rmq[l][x], rmq[l][x + sh]) << '\n';
    }
    return 0;
}