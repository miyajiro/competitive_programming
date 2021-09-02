#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
using vi = vector<ll>;
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
ll N, K;
vi A, _A;
vi C;

vector<mint> dp, dpImos;

void solve()
{
    cin >> N >> K;
    dp = vector<mint>(N + 1, 0); // dp[r]: A[r - 1]まで分断したときの答え。
    dpImos = vector<mint>(N + 1, 0); // dpImos[r] := dp[0] + ... + dp[r]
    dp[0] = 1;
    dpImos[0] = 1;

    C = vi(N + 1, 0); // C[r]: A[r - 1]まで分断したときの最も左側のインデックス
    fenwick_tree<ll> fw(N + 1); // fw[i]: 数字iが格納されている個数

    rep(i, N){
        ll a;
        cin >> a;
        A.eb(a);
        _A.eb(a);
    }
    sort(rng(_A));
    uni(_A);
    for(auto &a : A){
        a = (lower_bound(rng(_A), a) - _A.begin());
    }

    ll l = N;
    ll numOfPartitions = 0;
    rrep1(r, N){
        // while(l >= 0 && numOfPartitions <= K){
        while(true){
            if(l == 0 || numOfPartitions + fw.sum(0, A[l - 1]) > K){ // lが左端か、A[l - 1]加えるとK超えるか
                break;
            }

            numOfPartitions += fw.sum(0, A[--l]);
            fw.add(A[l], 1);
        }
        C[r] = l;
        numOfPartitions -= fw.sum(A[r - 1] + 1, N + 1);
        fw.add(A[r - 1], -1LL);
    }

    rep1(r, N){ // dp[r]: A[r - 1]まで分断したときの答え。
        int cl = C[r];

        if(cl == 0){
            dp[r] = dpImos[r - 1];
        } else {
            dp[r] = dpImos[r - 1] - dpImos[cl - 1];
        }

        dpImos[r] = dp[r];
        if(r > 0){
            dpImos[r] += dpImos[r - 1];
        }
    }

    cout << dp[N].val() << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}