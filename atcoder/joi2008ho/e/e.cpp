#include <bits/stdc++.h>
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
using namespace std;
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

int N;
vi X1, Y1, X2, Y2;
vi Xs, Ys;
int imos[2004][2004];
int H, W;
int gridH, gridW;

int vy[4] = {0, 1, 0, -1};
int vx[4] = {1, 0, -1, 0};

void dfs(int x, int y){
    imos[x][y] = 1;
    rep(i, 4){
        int nx = x + vx[i];
        int ny = y + vy[i];
        if(isin(nx, 0, gridW) && isin(ny, 0, gridH) && imos[nx][ny] == 0){
            dfs(nx, ny);
        }
    }
}

void solve()
{
    cin >> W >> H;

    Xs.pb(0);
    Ys.pb(0);
    Xs.pb(W - 1);
    Xs.pb(W);
    Ys.pb(H - 1);
    Ys.pb(H);

    cin >> N;
    rep(i, N){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        X1.pb(x1);
        Y1.pb(y1);
        X2.pb(x2);
        Y2.pb(y2);

        Xs.pb(x1);
        Ys.pb(y1);
        Xs.pb(x2);
        Ys.pb(y2);
    }
    sort(rng(Xs));
    sort(rng(Ys));
    uni(Xs);
    uni(Ys);

    rep(i, N){
        int cx1 = lower_bound(rng(Xs), X1[i]) - Xs.begin();
        int cy1 = lower_bound(rng(Ys), Y1[i]) - Ys.begin();
        int cx2 = lower_bound(rng(Xs), X2[i]) - Xs.begin();
        int cy2 = lower_bound(rng(Ys), Y2[i]) - Ys.begin();

        imos[cx1][cy1]++;
        imos[cx1][cy2]--;
        imos[cx2][cy1]--;
        imos[cx2][cy2]++;
    }

    rep(cx, sz(Xs)){
        rep1(cy, sz(Ys) - 1){
            imos[cx][cy] += imos[cx][cy - 1];
        }
    }

    rep(cy, sz(Ys)){
        rep1(cx, sz(Xs) - 1){
            imos[cx][cy] += imos[cx - 1][cy];
        }
    }

    gridW = sz(Xs) - 1;
    gridH = sz(Ys) - 1;

    int ans = 0;

    rep(w, gridW){
        rep(h, gridH){
            if(imos[w][h] == 0){
                ans++;
                dfs(w, h);
            }
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