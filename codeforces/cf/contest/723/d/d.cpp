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
#define PQ(T) priority_queue<T, v(T), greater<T>>
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

int vy[4] = {0, 1, 0, -1};
int vx[4] = {1, 0, -1, 0};

bool visited[51][51];
bool isLand[51][51];
bool isSea[51][51];
string str[51];
int H, W, K;
using T = pair<int, P>;

int dfs(int y, int x, bool edge){
    int res = 1;
    visited[y][x] = true;
    if(edge){
        isLand[y][x] = true;
        isSea[y][x] = true;
    }

    rep(vi, 4){
        int ny = y + vy[vi];
        int nx = x + vx[vi];

        if(isin(ny, 0, H) && isin(nx, 0, W) && !isLand[ny][nx] && !visited[ny][nx]){
            res += dfs(ny, nx, edge);
        }
    }

    return res;
}

void umeDfs(int y, int x){
    isLand[y][x] = true;
    rep(vi, 4){
        int ny = y + vy[vi];
        int nx = x + vx[vi];

        if(isin(ny, 0, H) && isin(nx, 0, W) && !isLand[ny][nx]){
            umeDfs(ny, nx);
        }
    }
}

void solve()
{
    cin >> H >> W >> K;
    rep(h, H){
        cin >> str[h];
        rep(w, W){
            isLand[h][w] = str[h][w] == '*';
        }
    }

    rep(h, H){
        if(!isLand[h][0])
        dfs(h, 0, true);
        if(!isLand[h][W-1])
        dfs(h, W - 1, true);
    }
    rep(w, W){
        if(!isLand[0][w])
        dfs(0, w, true);
        if(!isLand[H-1][w])
        dfs(H - 1, w, true);
    }

    vector<T> A;
    int nowK = 0;
    rep1(h, H - 2){
        rep1(w, W - 2){
            if(!isLand[h][w] && !visited[h][w]){
                nowK++;
                A.pb(T(dfs(h, w, false), P(h, w)));
            }
        }
    }

    sort(rng(A));

    int ans = 0;
    rep(i, nowK - K){
        ans += A[i].fr;
        umeDfs(A[i].sc.fr, A[i].sc.sc);
    }

    cout << ans << "\n";

    rep(h, H){
        string s = "";

        rep(w, W){
            if(!isLand[h][w] || isSea[h][w]){
                s += '.';
            } else {
                s += '*';
            }
        }

        cout << s << "\n";
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