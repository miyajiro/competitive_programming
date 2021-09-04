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
#define show(x) cerr << #x << " = " << x << "\n";
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

using mint = modint1000000007;
int N, K;
vi A, B;
vvi G;
vvi chArrayArray;

mint kaijo[100010];

mint P(int n, int k){
    if(n < k){
        return 0;
    }
    return kaijo[n] / kaijo[n - k];
}

void calcCh(int v, int prev){
    for(auto nex : G[v]){
        if(nex != prev){
            chArrayArray[v].eb(nex);
            calcCh(nex, v);
        }
    }
}

mint dfs(int v){ // vと、その1個下まで不定とした場合の通り数
    vi chArray = chArrayArray[v];
    if(sz(chArray) == 0){ // 1番下の場合
        return 1;
    }

    mint res = 1;
    for(auto ch : chArray){
        res *= dfs(ch) * P(K - 2, sz(chArrayArray[ch]));
    }

    return res;
}

void solve()
{
    cin >> N >> K;
    G = vvi(N);
    chArrayArray = vvi(N);
    rep(i, N - 1){
        int a, b;
        cin >> a >> b;
        A.eb(--a);
        B.eb(--b);
        G[a].eb(b);
        G[b].eb(a);
    }

    kaijo[0] = 1;
    rep1(i, 100009){
        kaijo[i] = kaijo[i - 1] * i;
    }
    calcCh(0, -1);

    cout << (dfs(0) * P(K, sz(G[0]) + 1)).val() << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}