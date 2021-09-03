#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
#include <atcoder/convolution>
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
#define show(x) cout << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
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

// dp[h][l][r] =
//      Σ(dp[h][l][k] * dp[h+1][k+1][r]) // インデックスk-1まではh以上、kはh、k+1以降はh+1以上
//      + dp[h+1][l][r] // 全てh+1以上
// dp[h][m] =
//      Σ[1~k~m](dp[h][k-1] * dp[h+1][m-k]) // インデックスk-1まではh以上、kはh、k+1以降はh+1以上
//      + dp[h+1][m] // 全てh+1以上
// = Σ[k=0..m](dp[h+1][m-k] * dp[h][k-1])
// = Σ[k=0..m](dp[h+1][k] * dp[h][m-k-1])
// = Σ[k=1..m+1](dp[h+1][k-1] * dp[h][m-k])

vector<mint> polynomial_inverse(vector<mint> C, int L){
    // (C[0] + C[1] * x + ... * C[N-1] * x^(N-1)) * P(x) == 1 (mod x^L) を満たす、L-1 次以下の多項式 P(x) を計算量 O(N log N) で求める
    // C[0] == 1である必要あり
    int N = C.size();
    vector<mint> A(L * 4);
    A.resize(2);
    A = { 1, 0 };
    int level = 0;
    while((1 << level) < L) {
        int CS = min(1 << (level + 1), N);

        vector<mint> resizedC(C.begin(), C.begin() + CS);
        vector<mint> P = convolution(A, resizedC);
        vector<mint> Q(1 << (level + 1));

        Q[0] = 1;
        srep(j, 1 << level, 1 << (level + 1)){
            Q[j] = -P[j];
        }
        A = convolution(A, Q);
        A.resize(1 << (level + 2));
        ++level;
    }

    A.resize(L);
    return A;
}

void solve()
{
    ll N;
    int K;
    cin >> N >> K;
    vector<vector<mint>> dp(K + 1);
    dp[K] = {1, 1, 1};
    rrep1(i, K - 1){
        int limit = min(N, (ll)(K / i)); // 実現可能な長さの上限(過ぎてたら0)
        vector<mint> C(dp[i + 1].size());
        C[0] = 1;
        rep1(j, dp[i + 1].size() - 1){
            C[j] = -dp[i + 1][j];
        }

        vector<mint> G = polynomial_inverse(C, limit + 2);
        dp[i] = G;
    }

    // ここまででdp[1], dp[2], ..., dp[K]は求まってる。
    // dp[0]を求める
    int S = min(ll(K), N); // 長さの上限。

    // N + S + 1について、S + 1を下回るまで右シフトしていきtrackに格納
    vl track = { N + S + 1 };
    while(track.back() >= S + 1) {
        track.eb(track.back() / 2LL);
    }
    reverse(rng(track));

    vector<mint> CL(S + 2);
    CL[0] = 1;
    rep1(i, S + 1){
        CL[i] = -dp[1][i];
    }

    vector<mint> GL = polynomial_inverse(CL, S + 2);

    reverse(rng(CL));

    vector<mint> poly(S + 1);

    // track[0]はS + 1を下回っている.
    poly[track[0]] = 1;

    rep1(i, track.size() - 1){
        poly = convolution(poly, poly);
        if(track[i] % 2 == 1){
            poly.insert(poly.begin(), 0);
        } else {
            poly.eb(0);
        }

        vector<mint> p1(poly.begin() + (S + 1), poly.end());
        reverse(rng(p1));

        vector<mint> p2 = convolution(p1, GL);
        p2.resize(S + 1);
        reverse(rng(p2));

        vector<mint> p3 = convolution(p2, CL);
        rep(j, 2 * S + 1){
            poly[j] -= p3[j];
        }
        poly.resize(S + 1);
    }
    cout << poly[S].val() << "\n";
    return;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}