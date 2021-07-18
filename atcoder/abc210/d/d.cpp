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

int H, W;
ll C;
vvl A;
vvl B;
ll ans = 0xffffffffffff;

void solve()
{
    cin >> H >> W >> C;
    A = vvl(H);
    B = vvl(H);

    rep(h, H){
        rep(w, W){
            ll a;
            cin >> a;
            A[h].eb(a);
            B[h].eb(a);
        }
    }

    rep(w, W){ // タテ方向
        ll now = B[0][w];
        rep1(h, H - 1){ // 上から下
            now += C;
            chmin(ans, now + A[h][w]); // タテ移動のみ
            chmin(now, B[h][w]);
            B[h][w] = now;
        }

        rrep1(h, H - 1){ // 下から上
            now += C;
            chmin(now, B[h][w]);
            B[h][w] = now;
        }
    }

    rep(h, H){ // 横方向
        ll now = B[h][0];
        rep1(w, W - 1){ // 左から右
            now += C;
            chmin(ans, now + A[h][w]); // 横, 縦横
            chmin(now, B[h][w]);
        }

        now = B[h][W - 1];
        rrep(w, W - 1){ // 左から右
            now += C;
            chmin(ans, now + A[h][w]); // 横, 縦横
            chmin(now, B[h][w]);
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