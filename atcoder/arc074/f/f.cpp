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
#include <atcoder/maxflow>
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
#define show(x) cout << #x << " = " << x << endl;
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

const ll inf = 0xfffffff;
int H, W;
vector<string> S;
int N;
int sN, tN;

void solve()
{
    cin >> H >> W;
    N = H * W + H + W;
    mf_graph<ll> mfg(N);
    S = vector<string>(H);
    rep(h, H){
        cin >> S[h];
    }

    rep(h, H){
        rep(w, W){
            int n = h * W + w;
            int tateN = H * W + w;
            int yokoN = H * W + W + h;

            if(S[h][w] == 'o'){
                mfg.add_edge(n, tateN, inf);
                mfg.add_edge(tateN, n, 1);

                mfg.add_edge(n, yokoN, inf);
                mfg.add_edge(yokoN, n, 1);
            }

            if(S[h][w] == 'S'){
                mfg.add_edge(n, tateN, inf);
                mfg.add_edge(tateN, n, inf);

                mfg.add_edge(n, yokoN, inf);
                mfg.add_edge(yokoN, n, inf);
                sN = n;
            }
            if(S[h][w] == 'T'){
                mfg.add_edge(n, tateN, inf);
                mfg.add_edge(tateN, n, inf);

                mfg.add_edge(n, yokoN, inf);
                mfg.add_edge(yokoN, n, inf);
                tN = n;
            }
        }
    }

    ll ans = mfg.flow(sN, tN);
    if(ans >= inf){
        ans = -1LL;
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