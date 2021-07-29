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

#ifndef TO_BE_SUBMITTED
#include <bits/stdc++.h>
using namespace std;
#endif

#include <atcoder/modint>

// 二項係数ライブラリ
template <class mint, atcoder::internal::is_static_modint_t<mint> * = nullptr>
struct BinomialCoefficient
{
    vector<mint> fact_, inv_, finv_;
    constexpr BinomialCoefficient(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1)
    {
        int MOD = mint::mod();
        for (int i = 2; i < n; i++)
        {
            fact_[i] = fact_[i - 1] * i;
            inv_[i] = -inv_[MOD % i] * (MOD / i);
            finv_[i] = finv_[i - 1] * inv_[i];
        }
    }
    constexpr mint com(int n, int k) const noexcept
    {
        if (n < k || n < 0 || k < 0)
            return 0;
        return fact_[n] * finv_[k] * finv_[n - k];
    }
    constexpr mint fact(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return fact_[n];
    }
    constexpr mint inv(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return inv_[n];
    }
    constexpr mint finv(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return finv_[n];
    }
};

using mint = modint998244353;
int R, G, B, K, X, Y, Z, N;
int minR, minG, minB;

void input(){
    cin >> R >> G >> B >> K >> X >> Y >> Z;
}

void solve()
{
    input();
    N = R + G + B;
    BinomialCoefficient<mint> bC(N);
    minR = K - Y;
    minG = K - Z;
    minB = K - X;

    vector<mint> r(R + 1), g(G + 1), b(B + 1);
    rep(i, R + 1){
        if(i < minR){
            r[i] = 0;
        } else {
            r[i] = bC.com(R, i);
        }
    }

    rep(i, G + 1){
        if(i < minG){
            g[i] = 0;
        } else {
            g[i] = bC.com(G, i);
        }
    }

    rep(i, B + 1){
        if(i < minB){
            b[i] = 0;
        } else {
            b[i] = bC.com(B, i);
        }
    }

    auto rg = convolution(r, g);
    auto rgb = convolution(rg, b);

    cout << rgb[K].val() << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}