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
 
const int INF = 2e9 + 2;
 
typedef struct treap* arb;
 
arb nou, tr;
 
struct treap{
    int pos, sz, prio;
    char val;
    arb ls, rs;
    treap (char x)
    {
        val = x;
        prio = 1 + (rand() % INF);
        sz = 1;
        ls = nou;
        rs = nou;
    }
};
 
void init ()
{
    nou = new treap(0);
    nou->sz = 0;
    tr = nou;
}
 
int getsz (arb x)
{
    if (x == nou)
    {
        return 0;
    }
    return x->sz;
}
 
void recalc (arb x)
{
    if (x == nou)
    {
        return;
    }
    x->sz = getsz(x->ls) + getsz(x->rs) + 1;
}
 
arb join (arb x, arb y)
{
    if (x == nou)
    {
        return y;
    }
    if (y == nou)
    {
        return x;
    }
    if (x->prio > y->prio)
    {
        x->rs = join(x->rs, y);
        recalc(x);
        return x;
    }
    else
    {
        y->ls = join(x, y->ls);
        recalc(y);
        return y;
    }
}
 
pair <arb, arb> split (arb x, int val)
{
    if (x == nou)
    {
        return {nou, nou};
    }
    int lsz = getsz(x->ls);
    if (val <= lsz)
    {
        pair <arb, arb> aux = split(x->ls, val);
        x->ls = aux.second;
        recalc(x);
        return {aux.first, x};
    }
    pair <arb, arb> aux = split(x->rs, val - lsz - 1);
    x->rs = aux.first;
    recalc(x);
    return {x, aux.second};
}
 
arb ins (arb nod, int pos, char val)
{
    arb aux = new treap(val);
    pair <arb, arb> spl = split(tr, pos);
    return join(join(spl.first, aux), spl.second);
}
 
void afis (arb nod)
{
    if (nod == nou)
    {
        return;
    }
    afis(nod->ls);
    cout << nod->val;
    afis(nod->rs);
}
 
void solve() 
{
    int n, q;
    string s;
    cin >> n >> q >> s;
    init();
    for (int i = 0; i < n; i++)
    {
        tr = ins(tr, i, s[i]);
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        pair <arb, arb> aux1 = split(tr, x);
        pair <arb, arb> aux2 = split(aux1.second, y - x + 1);
        tr = join(join(aux1.first, aux2.second), aux2.first);
    }
    afis(tr);
}
  
signed main() 
{ 
#ifdef LOCAL 
    freopen("test.in", "r", stdin); 
    freopen("test.out", "w", stdout); 
#endif // LOCAL 
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0); 
    long long tt; 
    //cin >> tt; 
    tt = 1; 
    while (tt--) 
    { 
        solve(); 
    } 
    return 0; 
}