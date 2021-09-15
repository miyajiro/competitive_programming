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

int H, W;
int M;
vi Y, X;
map<int, int> y2Cnt;
map<int, int> x2Cnt;
set<P> exist;

void solve()
{
    cin >> H >> W >> M;

    if(M == 1){
        cout << 1 << "\n";return;
    }
    rep(i, M){
        int y, x;
        cin >> y >> x;
        exist.insert(P(y, x));
        y2Cnt[y]++;
        x2Cnt[x]++;
        Y.eb(y);
        X.eb(x);
    }

    vp cntAndY;
    vp cntAndX;

    for(const auto& [y, cnt] : y2Cnt){
        cntAndY.eb(P(cnt, y));
    }

    for(const auto [x, cnt] : x2Cnt){
        cntAndX.eb(P(cnt, x));
    }

    sort(rrng(cntAndY));
    sort(rrng(cntAndX));

    int maxYVal = cntAndY[0].fr;
    int maxXVal = cntAndX[0].fr;

    ll yRng = 0;
    rep(i, sz(cntAndY)){
        int cnt = cntAndY[i].fr;
        if(cnt == maxYVal){
            yRng++;
        }
    }

    ll xRng = 0;
    rep(i, sz(cntAndX)){
        int cnt = cntAndX[i].fr;
        if(cnt == maxXVal){
            xRng++;
        }
    }
    ll koho = yRng * xRng; // ホットスポット

    rep(i, M){
        int y = Y[i];
        int x = X[i];
        if(y2Cnt[y] == maxYVal && x2Cnt[x] == maxXVal){
            koho--;
        }
    }

    int ans = maxYVal + maxXVal - 1;

    if(koho > 0){
        ans++;
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