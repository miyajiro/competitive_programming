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

int H, W, A, B;

int yx2N(int y, int x){
    return y * W + x;
}

P n2YX(int n){
    return P(n / W, n % W);
}

bool isUsed(int y, int x, int used){
    int n = yx2N(y, x);
    return (used >> n) % 2 == 1;
}

int use(int y, int x, int used){
    int n = yx2N(y, x);
    return used | (1 << n);
}

int dfs(int n, int nokori, int used){
    P p = n2YX(n);
    int y = p.fr;
    int x = p.sc;

    if(nokori == 0){
        return 1;
    }
    if(y == H - 1 && x == W - 1 && nokori > 0){
        return 0;
    }

    int res = 0;
    // 横の場合
    if(x < W - 1 && !isUsed(y, x, used) && !isUsed(y, x + 1, used)){
        int newUsed = use(y, x, used);
        newUsed = use(y, x + 1, used);
        res += dfs(n + 1, nokori - 1, newUsed);
    }

    // 縦の場合
    if(y < H - 1 && !isUsed(y, x, used) && !isUsed(y + 1, x, used)){
        int newUsed = use(y, x, used);
        newUsed = use(y + 1, x, used);
        res += dfs(n + 1, nokori - 1, newUsed);
    }

    // 敷き詰めない場合
    res += dfs(n + 1, nokori, used);
    return res;
}

void solve()
{
    cin >> H >> W >> A >> B;
    cout << dfs(0, A, 0) << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}