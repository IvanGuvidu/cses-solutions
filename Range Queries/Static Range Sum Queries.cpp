#include <iostream>
 
using namespace std;
 
const int max_size = 2e5 + 1;
 
long long a[max_size], sp[max_size];
 
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sp[i] = sp[i - 1] + a[i];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sp[r] - sp[l - 1] << '\n';
    }
    return 0;
}