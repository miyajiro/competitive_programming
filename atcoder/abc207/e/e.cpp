#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
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
#define pb emplace_back
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

const int MOD = 1000000007;

int N;
int ans = 0;
vl A(3030), sum(3030);
vector<vvi> modMemo(3030, vvi(3030)); // modMemo[k][v]: sum[i + 1]をkで割った余りがvとなるiを格納

vvi dp(3030, vi(3030, 0)); // x番目までグループkの場合の数
vvi ik2L(3030, vi(3030, -1));

void solve()
{
    cin >> N;

    rep(i, N){
        cin >> A[i];
    }

    rep(i, N){
        sum[i + 1] = sum[i] + A[i];
        rep1(k, N){
            int m = sum[i+1] % k;
            int szMemo = sz(modMemo[k][m]);
            if(szMemo > 0){
                ik2L[i][k] = modMemo[k][m][szMemo - 1];
            }
            modMemo[k][m].pb(i);
        }
    }

    rep(i, N){
        rep1(k, i + 1){ // dp[i][k]: A[i]までがキリ良くグループk
            if(k == 1){
                dp[i][k] = 1;
                continue;
            }
            int l = ik2L[i][k];
            if(l < 0){
                continue;
            }
            dp[i][k] = (dp[l][k] + dp[l][k-1]);
            if(dp[i][k] >= MOD){
                dp[i][k] -= MOD;
            }
        }
    }

    rep1(k, N){
        ans = (ans + dp[N - 1][k]) % MOD;
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