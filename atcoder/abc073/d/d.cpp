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

const ll INF = 0xffffffffffffff;
int N, M, R;
vi X;
vi A, B, C;
vvl D1, D2;
int s, g;

void solve()
{
    cin >> N >> M >> R;

    s = N;
    g = N + 1;
    N += 2;

    rep(i, R){
        int x;
        cin >> x;
        X.eb(--x);
    }
    X.eb(s);
    X.eb(g);
    R += 2;

    D1 = vvl(N, vl(N, INF));

    rep(i, M){
        int a, b, c;
        cin >> a >> b >> c;
        A.eb(--a);
        B.eb(--b);
        C.eb(c);
        D1[a][b] = D1[b][a] = c;
    }

    rep(i, N){
        D1[i][i] = 0;
        D1[s][i] = 0;
        D1[i][g] = 0;
    }

    rep(k, N){
        rep(i, N){
            rep(j, N){
                chmin(D1[i][j], D1[i][k] + D1[k][j]);
            }
        }
    }

    // R: 頂点数
    // D2: 距離行列
    D2 = vvl(R, vl(R));
    rep(i, R){
        rep(j, R){
            D2[i][j] = D1[X[i]][X[j]];
        }
    }
    int S = R - 2;
    int G = R - 1;

    vvl dp(1 << R, vl(R, INF));
    dp[0][S] = 0;

    rep(s, 1 << R){
        rep(i, R){
            rep(j, R){
                int newS = (s | (1 << j));
                chmin(dp[newS][j], dp[s][i] + D2[i][j]);
            }
        }
    }

    cout << dp[bn(R)][G] << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}