#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
// #include <atcoder/modint>
// #include <atcoder/dsu>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/scc>
// #include <atcoder/twosat>

namespace atcoder{};
using namespace atcoder;
using namespace std;

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
#define show(x) cerr << #x << " = " << x << "\n";
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
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

int N, M;
vl H, U, V;
vvi G;
vl J;
const ll INF = 0xffffffffffffff;

void solve()
{
    cin >> N >> M;
    G = vvi(N);
    J = vl(N, -INF);

    rep(i, N){
        ll h;
        cin >> h;
        H.eb(h);
    }
    rep(i, M){
        ll u, v;
        cin >> u >> v;
        U.eb(--u);
        V.eb(--v);
        G[u].eb(v);
        G[v].eb(u);
    }

    priority_queue<LP> pq;

    J[0] = 0;
    pq.push(LP(0, 0));
    ll ans = 0;

    while(!pq.empty()){
        LP lp = pq.top();
        pq.pop();
        int now = lp.sc;
        ll joy = lp.fr;

        chmax(ans, joy);
        if(J[now] > joy){
            continue;
        }

        for(auto nex : G[now]){
            if(H[now] > H[nex]){
                if(chmax(J[nex], J[now] + H[now] - H[nex])){
                    pq.push(LP(J[nex], nex));
                }
            } else {
                if(chmax(J[nex], J[now] + 2LL * H[now] - 2LL * H[nex])){
                    pq.push(LP(J[nex], nex));
                }
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}