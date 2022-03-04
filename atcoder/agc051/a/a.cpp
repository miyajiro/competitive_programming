#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
#include <atcoder/modint>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
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
#define newline cout << "\n"
#define newlineErr cerr << "\n"

using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vp = vector<P>;
using vlp = vector<LP>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;

using mint = modint998244353;
using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;

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

int d;
mint ans = 2;

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

BinomialCoefficient<mint> bi(2000001);

void solve()
{
    cin >> d;
    ans = bi.com(2 * d, d) * ((mint)(2)).inv();
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