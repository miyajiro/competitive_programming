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

#ifndef TO_BE_SUBMITTED
#include <bits/stdc++.h>
using namespace std;
#endif

template <unsigned mod>
struct RollingHash
{
    vector<unsigned> hashed, power;

    inline unsigned mul(unsigned a, unsigned b) const
    {
        unsigned long long x = (unsigned long long)a * b;
        unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
        asm("divl %4; \n\t"
            : "=a"(d), "=d"(m)
            : "d"(xh), "a"(xl), "r"(mod));
        return m;
    }

    RollingHash(const string &s, unsigned base = 2)
    {
        int sz = (int)s.size();
        hashed.assign(sz + 1, 0);
        power.assign(sz + 1, 0);
        power[0] = 1;
        for (int i = 0; i < sz; i++)
        {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if (hashed[i + 1] >= mod)
                hashed[i + 1] -= mod;
        }
    }

    /**
     * 区間[l, r) のハッシュ値を返す
     * O(1)
     */
    unsigned get(int l, int r) const
    {
        unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if (ret >= mod)
            ret -= mod;
        return ret;
    }

    /**
     * ハッシュ値h1と長さh2lenのハッシュ値h2を結合する
     * O( log N )
     */
    unsigned connect(unsigned h1, int h2, int h2len) const
    {
        unsigned ret = mul(h1, power[h2len]) + h2;
        if (ret >= mod)
            ret -= mod;
        return ret;
    }

    /**
     * LCP (Longest Common Prefix)
     * 区間[l1, r1)とハッシュテーブルがbからなる区間[l2, r2]の文字列の最長共通接頭辞の長さを求める
     * O( log N )
     */
    int LCP(const RollingHash<mod> &b, int l1, int r1, int l2, int r2)
    {
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while (high - low > 1)
        {
            int mid = (low + high) / 2;
            if (get(l1, l1 + mid) == b.get(l2, l2 + mid))
                low = mid;
            else
                high = mid;
        }
        return (low);
    }
};

using RH = RollingHash<1000000007>;


int N;
const int M = 30;
vi A, B;
vector<string> sA(30), sB(30), sBInv(30);
vector<RH> rhA(30, RH("")), rhB(30, RH("")), rhBInv(30, RH(""));

void solve()
{
    cin >> N;
    rep(i, N){
        int a;
        cin >> a;
        A.pb(a);
        rep(m, M){
            sA[m] += to_string((a >> m) & 1);
        }
    }
    rep(i, N){
        int b;
        cin >> b;
        B.pb(b);
        rep(m, M){
            sB[m] += to_string((b >> m) & 1);
            sBInv[m] += to_string(1 - ((b >> m) & 1));
        }
    }

    rep(m, M){
        rhA[m] = RH(sA[m]);
        rhB[m] = RH(sB[m]);
        rhBInv[m] = RH(sBInv[m]);
    }

    rep(k, N){
        int x = 0;
        rep(m, M){
            unsigned int hashA1 = rhA[m].get(k, N);
            unsigned int hashA2 = rhA[m].get(0, k);
            unsigned int hashA = rhA[m].connect(hashA1, hashA2, k);
            unsigned int hashB = rhB[m].get(0, N);
            unsigned int hashBInv = rhBInv[m].get(0, N);
            if(hashA == hashBInv){
                x |= 1 << m;
            } else if(hashA != hashB) {
                goto nextK;
            }
        }
        cout << k << " " << x << "\n";

        nextK:
            ;
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}