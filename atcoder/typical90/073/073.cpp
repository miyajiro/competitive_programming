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
#define show(x) cerr << #x << " = " << x << endl;
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

using mint = modint1000000007;

int N;
vvi G;
vector<char> C;
vector<vector<mint>> dp;

vector<mint> dfs(int now, int from){
    vector<mint> res(3, 0);
    int A = 0;
    int B = 1;
    int AB = 2;

    if(C[now] == 'b'){
        swap(A, B);
    }

    // ここからはC[now] == 'a'とみなす
    if(sz(G[now]) == 1 && G[now][0] == from){ // 自分が葉である場合
        res[A] = 1;
        res[B] = 0;
        res[AB] = 0;
        return dp[now] = res;
    }

    vector<vector<mint>> chValArray;
    for(auto nex : G[now]){
        if(nex == from){
            continue;
        }

        chValArray.eb(dfs(nex, now));
    }

    mint aVal = 1;
    mint abVal1 = 1;
    mint abVal2 = 1;

    for(auto chVal : chValArray){
        aVal *= (chVal[A] + chVal[AB]);
        abVal1 *= (chVal[A] + chVal[B] + 2 * chVal[AB]);
        abVal2 *= (chVal[A] + chVal[AB]);
    }

    res[A] = aVal;
    res[B] = 0;
    res[AB] = abVal1 - abVal2;

    return dp[now] = res;
}

void solve()
{
    cin >> N;
    G = vvi(N);
    dp = vector<vector<mint>>(N, vector<mint>(3, 0));
    rep(i, N){
        string c;
        cin >> c;
        C.eb(c[0]);
    }
    rep(i, N - 1){
        int x, y;
        cin >> x >> y;
        G[--x].eb(--y);
        G[y].eb(x);
    }

    cout << dfs(0, -1)[2].val() << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}