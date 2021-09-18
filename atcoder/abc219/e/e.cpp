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

int A[4][4];
int X[4][4];
int Y[4][4];
int a = 0;
int vy[4] = {1, 0, -1, 0};
int vx[4] = {0, 1, 0, -1};

bool ok(int y, int x){
    return isin(y, 0, 4) && isin(x, 0, 4);
}

void dfs(int y, int x){
    X[y][x] = 0;
    rep(i, 4){
        int ny = y + vy[i];
        int nx = x + vx[i];
        if(ok(ny, nx) && X[ny][nx] == 1){
            dfs(ny, nx);
        }
    }
}

void dfs2(int y, int x){
    Y[y][x] = 0;
    rep(i, 4){
        int ny = y + vy[i];
        int nx = x + vx[i];
        if(ok(ny, nx) && Y[ny][nx] == 1){
            dfs2(ny, nx);
        }
    }
}

bool ok(int b){ // bで表されるやつがaを全部含みかつ
    if((a & b) != a){
        return false;
    }

    // 連結判定
    rep(i, 4){
        rep(j, 4){
            int n = i * 4 + j;
            if((b >> n) % 2 == 1){
                X[i][j] = 1;
                Y[i][j] = 0;
            } else {
                X[i][j] = 0;
                Y[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    rep(i, 4){
        rep(j, 4){
            if(X[i][j] == 1){
                dfs(i, j);
                cnt++;
            }
        }
    }
    if(cnt > 1){
        return false;
    }

    // 自己交差判定
    rep(i, 4){
        if(Y[i][0] == 1){
            dfs2(i, 0);
        }
        if(Y[0][i] == 1){
            dfs2(0, i);
        }
        if(Y[i][3] == 1){
            dfs2(i, 3);
        }
        if(Y[3][i] == 1){
            dfs2(3, i);
        }
    }

    rep(i, 4){
        rep(j, 4){
            if(Y[i][j] == 1){
                return false;
            }
        }
    }
    return true;
}

void solve()
{
    rep(i, 4){
        rep(j, 4){
            cin >> A[i][j];
            int n = i * 4 + j;
            if(A[i][j] == 1){
                a |= 1 << n;
            }
        }
    }

    int ans = 0;
    rep(s, 1 << 16){
        if(ok(s)){
            ans++;
        }
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