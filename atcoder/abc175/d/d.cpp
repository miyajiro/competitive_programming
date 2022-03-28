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

using mint = modint1000000007;
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

const ll INF = 0xfffffffffffff;
int N, K;
vl A, C;
ll ans = -INF;

ll solve2(int x){ // xからスタート
    ll res = -INF;
    int k = 0;
    ll score = 0;
    vector<LP> memo(N, LP(0, 0)); // mp[i] = (何番目か, スコア)

    while(true){
        k++; // 個数加算
        x = A[x]; // 移動
        score += C[x]; // スコア加算
        chmax(res, score);

        if(k == K){ // K個目まで調べ尽くした
            break;
        }

        if(memo[x] == LP(0, 0)){ // 初めて来た場合
            memo[x] = LP(k, score);
            continue;
        }

        LP lpPast = memo[x];
        ll pastK = lpPast.fr;
        ll pastScore = lpPast.sc;

        ll dK = k - pastK;
        ll dScore = score - pastScore;

        if(dScore <= 0LL){ // 0以下のループに入ってる
            break;
        }

        ll remainK = K - k;
        ll loopNum = remainK / dK;

        k += dK * loopNum;
        score += dScore * loopNum;

        chmax(res, score);

        if(k == K){ // K個目まで調べ尽くした
            break;
        }
    }

    return res;
}

void solve()
{
    cin >> N >> K;
    rep(i, N){
        ll a;
        cin >> a;
        A.eb(--a);
    }
    rep(i, N){
        ll c;
        cin >> c;
        C.eb(c);
    }
    rep(i, N){
        chmax(ans, solve2(i));
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