#include <bits/stdc++.h>
#include <atcoder/all>
#define fr first
#define sc second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rrep1(i, n) for (int i = (n); i >= 1; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
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
using namespace atcoder;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vp = vector<P>;
using vlp = vector<LP>;
inline int getInt()
{
    int x;
    scanf("%d", &x);
    return x;
}
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

ll N, K;
ll H, W;
vv(ll) A;
v(string) grid;

int main()
{
    cin >> H >> K;
    W = H;

    rep(h, H){
        A.pb(vl());
        rep(w, W){
            ll a;
            cin >> a;
            A[h].pb(a);
        }
    }

    const ll BIGNUM = (1e+9) + 10;
    // [0, H): y座標
    // [H, H + W): x座標
    // N - 2: from
    // N - 1: to
    N = H + W + 2;
    ll source = N - 2;
    ll sink = N - 1;
    mcf_graph<ll, ll> mcf(N);

    rep(h, H){
        mcf.add_edge(source, h, K, 0);
    }

    rep(w, W){
        mcf.add_edge(H + w, sink, K, 0);
    }

    rep(h, H){
        rep(w, W){
            mcf.add_edge(h, H + w, 1, BIGNUM - A[h][w]);
        }
    }

    mcf.add_edge(source, sink, 0xfffffffffffff, BIGNUM);

    LP res = mcf.flow(source, sink, N * K);
    ll ans = BIGNUM * res.fr - res.sc;

    rep(h, H){
        grid.pb("");
        rep(w, W){
            grid[h] += ".";
        }
    }

    for(auto edge : mcf.edges()){
        if(edge.from == source || edge.to == sink){
            continue;
        }

        if(edge.flow == 0){
            continue;
        }

        grid[edge.from][edge.to - H] = 'X';
    }

    cout << ans << endl;
    rep(h, H){
        cout << grid[h] << endl;
    }

    return 0;
}