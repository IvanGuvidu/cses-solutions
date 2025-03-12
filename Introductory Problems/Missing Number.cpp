#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
vector <int> v;
 
int main ()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    if (v[0] != 1)
    {
        cout << 1;
        return 0;
    }
    if (v[n - 2] != n)
    {
        cout << n;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] != v[i + 1] - 1)
        {
            cout << v[i] + 1;
            break;
        }
    }
    return 0;
}