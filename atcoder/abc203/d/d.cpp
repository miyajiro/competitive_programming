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
#define show(x) cout << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T>>
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

int N, K;
vector<vl> A;
vvi imos;

bool ok(ll val){ // 中央値val
    imos = vvi(N+2, vi(N+2, 0));

    rep1(h, N){
        rep1(w, N){
            imos[h][w] = (A[h-1][w-1] <= val);
        }
    }

    rep1(h, N){
        rep1(w, N){
            imos[h][w] += imos[h][w-1];
        }
    }

    rep1(w, N){
        rep1(h, N){
            imos[h][w] += imos[h-1][w];
        }
    }

    int minKosu = ((K * K + 1) / 2);

    rep1(gh, N - K + 1){
        rep1(gw, N - K + 1){
            int kosu = imos[gh + K - 1][gw + K - 1] - imos[gh + K - 1][gw - 1] - imos[gh - 1][gw + K - 1] + imos[gh - 1][gw - 1];
            if(kosu >= minKosu){
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin >> N >> K;
    A = vector<vl>(N, vl(N));

    rep(i, N){
        rep(j, N){
            cin >> A[i][j];
        }
    }

    ll l = -1LL;
    ll r = 1e9;

    while(r - l > 1LL){
        ll mid = (r + l) / 2LL;
        if(ok(mid)){
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}