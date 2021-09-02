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

int N, Q;
vi A, X, Y;
vector<LP> sum2S;
const LP UNDEFINED = LP(-1LL, -1LL);
const int HALF = 44;
vector<vector<bool>> ok;

void printAns(LP lp){
    vi ans;
    rep(i, HALF){
        if((lp.fr >> i) % 2LL == 1LL){
            ans.eb(i + 1);
        }
    }
    rep(i, N - HALF){
        if((lp.sc >> i) % 2LL == 1LL){
            ans.eb(i + 1 + HALF);
        }
    }
    cout << sz(ans) << "\n";
    rep(ai, sz(ans)){
        cout << ans[ai] << (ai == sz(ans) - 1 ? "\n" : " ");
    }
}

bool is1(LP lp, int n){ // lpにおいてA[n]を使ってるか。
    if(n < HALF){
        return (lp.fr >> n) % 2LL == 1LL;
    } else {
        return (lp.sc >> (n - HALF)) % 2LL == 1LL;
    }
}

bool dfs(int n, LP lp, int sumVal){ // n番目まで埋めた状態で集合がlp, 合計値sumValの場合。
    // show(n);
    // show(lp.fr);
    // show(lp.sc);

    if(sum2S[sumVal] != UNDEFINED && sumVal != 0 && lp != sum2S[sumVal]){
        printAns(sum2S[sumVal]);
        printAns(lp);
        return true;
    }
    sum2S[sumVal] = lp;

    if(n == N - 1){ // N - 1番目まで来てたらアウト
        return false;
    }

    if(dfs(n + 1, lp, sumVal)){ // n + 1番目が0の場合
        return true;
    }

    rep(ni, N){
        if(is1(lp, ni) && !ok[ni][n + 1]){ // 使ってるもので、そんでn + 1が1無理だった場合
            return false;
        }
    }

    if(n + 1 < HALF){
        lp.fr |= (1LL << (n + 1));
    } else {
        lp.sc |= (1LL << (n + 1 - HALF));
    }

    return dfs(n + 1, lp, sumVal + A[n + 1]);
}

void solve()
{
    cin >> N >> Q;
    sum2S = vector<LP>(8881, UNDEFINED);
    ok = vector<vector<bool>>(N, vector<bool>(N, true));
    rep(n, N){
        int a;
        cin >> a;
        A.eb(a);
    }

    rep(q, Q){
        int x, y;
        cin >> x >> y;
        X.eb(--x);
        Y.eb(--y);
        ok[x][y] = ok[y][x] = false;
    }

    if(!dfs(0, LP(0, 0), 0)){
        dfs(0, LP(1LL, 0LL), A[0]);
    }
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