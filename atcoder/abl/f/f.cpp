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

#ifndef TO_BE_SUBMITTED
#include <bits/stdc++.h>
using namespace std;
#endif

#include <atcoder/modint>

// 二項係数ライブラリ
template <class mint, atcoder::internal::is_static_modint_t<mint> * = nullptr>
struct BinomialCoefficient
{
    vector<mint> fact_, fact2_, inv_, finv_;
    constexpr BinomialCoefficient(int n) noexcept : fact_(n, 1), fact2_(n, 1), inv_(n, 1), finv_(n, 1)
    {
        int MOD = mint::mod();

        fact2_[2] = 2;
        for (int i = 2; i < n; i++)
        {
            fact_[i] = fact_[i - 1] * i;
            if(i > 2){
                fact2_[i] = fact2_[i - 2] * i;
            }
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
    constexpr mint fact2(int n) const noexcept
    {
        if (n < 0)
            return 0;
        return fact2_[n];
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

int N;
vi A;
using mint = modint998244353;
using vm = vector<mint>;
BinomialCoefficient<mint> bC(300000);

void solve()
{
    cin >> N;
    {
        map<int, int> mp;
        rep(i, 2 * N){
            int x;
            cin >> x;
            mp[x]++;
        }

        for(auto elem : mp){
            A.eb(elem.sc);
        }
    }

    int M = sz(A);
    sort(rng(A));

    vector<vm> B(M);
    rep(m, M){
        int a = A[m];
        int l = a / 2; // 最大何ペア作れるか

        B[m] = vm(l + 1); // 0 ~ lペア

        B[m][0] = 1; // 0ペアの組み方は1通り
        rep1(i, l){
            B[m][i] = bC.com(a, 2 * i) * bC.fact2(2 * i - 1); // iペアの組み方を計算
        }
    }

    for(int m = 0; m < sz(B) - 1; m += 2){
        B.eb(convolution(B[m], B[m + 1]));
    }

    vm C = B.back();
    rep(i, sz(C)){ // iペア以外の数を掛け込む
        int k = N - i;
        if(k > 0){
            C[i] *= bC.fact2(2 * k - 1);
        }
    }

    mint ans = 0;
    rep(i, sz(C)){
        ans += (i % 2 == 0 ? C[i] : -C[i]);
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