#include <bits/stdc++.h>
#define fr first
#define sc second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define forin(i, v) for (auto i : v)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define snuke srand((unsigned)clock() + (unsigned)time(NULL));
#define show(x) cout << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;

int par[100000];
int N, M;
vi X, Y, Z;

void init()
{
    rep(i, N)
        par[i] = i;
}

int find(int v)
{
    if (par[v] == v)
        return v;
    return par[v] = find(par[v]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    par[y] = x;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    cin >> N >> M;
    init();
    rep(i, M)
    {
        X.pb(0);
        Y.pb(0);
        Z.pb(0);
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--;
        Y[i]--;
        unite(X[i], Y[i]);
    }

    int ans = 1;
    rep(i, N)
    {
        if (!same(0, i))
            ans++;
        unite(0, i);
    }
    cout << ans << endl;
    return 0;
}