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
#define show(x) cerr << #x << " = " << x << endl;
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

using mint = modint1000000007;
int N;
vl A, imosA;

vector<vector<mint>> dp;

void solve()
{
    cin >> N;

    rep(i, N){
        ll a;
        cin >> a;
        A.eb(a);
    }
    imosA.eb(0);
    rep(i, N){
        imosA.eb(imosA.back() + A[i]);
    }

    vvi memo(N+1, vi(N+1, -1)); // memo[n][k] = x: xはimosA[n]-imosA[x]%k==0なる最大のx
    rep1(k, N){
        vvi modVal2IndexArray(k);
        rep(n, N + 1){
            modVal2IndexArray[imosA[n] % k].eb(n);
        }

        rep(i, k){
            rep1(j, sz(modVal2IndexArray[i]) - 1){
                int X = modVal2IndexArray[i][j]; // mod kがiとなるインデックス
                int prevX = modVal2IndexArray[i][j - 1]; // mod kがiとなる1個前のインデックス

                memo[X][k] = prevX;
            }
        }
    }

    // dp[k][n]: A[0]~A[n-1]を1~Kのグループに分ける場合の数
    dp = vector<vector<mint>>(3001, vector<mint>(3001, 0));
    dp[0][0] = 1;
    rep1(k, N){
        rep1(n, N){
            int x = memo[n][k];
            if(x == -1){ // kの倍数となる部分列が無い
                continue;
            }

            dp[k][n] = dp[k-1][x] + dp[k][x];
        }
    }
    mint ans = 0;
    rep1(k, N){
        ans += dp[k][N];
    }
    cout << ans.val() << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}