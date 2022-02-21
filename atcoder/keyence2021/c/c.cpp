#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
#include <atcoder/modint>
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

using mint = modint998244353;
int H, W, K;
vector<string> grid;
vector<vector<mint>> dp;
vvi imos;

int getImos(int h, int w){
    if(h < 0 || w < 0){
        return 0;
    }

    return imos[h][w];
}

int count(int h1, int w1, int h2, int w2){ // 矩形領域に含まれる.の数を返す
    return getImos(h2, w2) - getImos(h2, w1 - 1) - getImos(h1 - 1, w2) + getImos(h1 - 1, w1 - 1);
}

void solve()
{
    cin >> H >> W >> K;
    grid = vector<string>(H);
    dp = vector<vector<mint>>(H + 1, vector<mint>(W + 1, 0));
    imos = vvi(H, vi(W));

    rep(h, H){
        rep(w, W){
            grid[h].push_back('.');
        }
    }

    rep(k, K){
        int h, w;
        char c;
        cin >> h >> w >> c;
        grid[--h][--w] = c;
    }

    dp[H - 1][W - 1] = 1;
    if(grid[H - 1][W - 1] == '.'){
        dp[H - 1][W - 1] = 3;
    }

    rep(h, H){
        rep(w, W){
            if(grid[h][w] == '.'){
                imos[h][w]++;
            }
        }
    }
    rep(h, H){
        rep(w, W){
            imos[h][w] += getImos(h - 1, w) + getImos(h, w - 1) - getImos(h - 1, w - 1);
        }
    }

    mint m3 = 3;

    rrep(h, H){
        rrep(w, W){
            if(h == H - 1 && w == W - 1){
                continue;
            }

            mint rVal = dp[h][w + 1] * m3.pow(count(h + 1, w, H - 1, w));
            mint dVal = dp[h + 1][w] * m3.pow(count(h, w + 1, h, W - 1));

            if(grid[h][w] == 'R'){
                dp[h][w] = rVal;
            }

            if(grid[h][w] == 'D'){
                dp[h][w] = dVal;
            }

            if(grid[h][w] == 'X'){
                dp[h][w] = rVal + dVal;
            }

            if(grid[h][w] == '.'){
                dp[h][w] = (rVal + dVal) * 2;
            }

            // show(h);
            // show(w);
            // show(dp[h][w].val());
        }
    }

    // rep(h, H){
    //     rep(w, W){
    //         cout << dp[h][w].val() << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[0][0].val() << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}