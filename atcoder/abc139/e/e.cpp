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
#include <atcoder/scc>
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
// #define show(x) cerr << #x << " = " << x << endl;
#define show(x) cerr << "";
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

int N;
vvi A;
vector<P> Ps;
int M;
vvi G;

P dfs(int now, int prev){
    P res = P(0, -1);

    int cnt = -1;
    if(prev == -1){
        cnt++;
    }
    cnt += sz(G[now]);
    if(cnt == 0){
        return P(0, now);
    }

    for(auto nex : G[now]){
        if(nex == prev){
            continue;
        }

        chmax(res, dfs(nex, now));
    }
    res.fr++;
    return res;
}

void solve()
{
    cin >> N;
    A = vvi(N, vi(N - 1, 0));
    rep(i, N){
        srep(j, i + 1, N){
            Ps.eb(P(i, j));
            show(Ps.back().fr);
            show(Ps.back().sc);
        }
    }
    M = sz(Ps);
    scc_graph sg(M);
    G = vvi(M);

    rep(x, N){
        rep(j, N - 1){
            cin >> A[x][j];
            A[x][j]--;
            if(j > 0){
                int y1 = A[x][j - 1];
                int y2 = A[x][j];

                P p1 = P(min(x, y1), max(x, y1));
                P p2 = P(min(x, y2), max(x, y2));

                int n1 = lower_bound(rng(Ps), p1) - Ps.begin();
                int n2 = lower_bound(rng(Ps), p2) - Ps.begin();

                show(x);
                show(y1);
                show(y2);
                show(n1);
                show(n2);

                G[n1].eb(n2);
                sg.add_edge(n1, n2);
            }
        }
    }

    rep(i, M){
        show(i);
        for(auto nex : G[i]){
            show(nex);
        }
    }

    vvi _scc = sg.scc();
    if(_scc.size() < M){
        cout << "-1\n";
        return;
    }

    vi T;
    vi dp;
    for(auto s : _scc){
        T.eb(s[0]);
        dp.eb(1);
    }

    int ans = 0;
    for(auto t : T){
        for(auto nex : G[t]){
            chmax(dp[nex], dp[t] + 1);
            chmax(ans, dp[nex]);
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