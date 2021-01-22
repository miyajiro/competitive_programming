#include <bits/stdc++.h>
#include <atcoder/all>
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
#define v(T) vector<T>
#define vv(T) v(v(T))
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

int H, W, N, M;
vi A(500000), B(500000), C(500000), D(500000);

vv(bool) calc(int H, int W, vvi grid)
{
    vv(bool) isLit(1500, v(bool)(1500, false));
    v(bool) tate(1500, false), yoko(1500, false);
    rep(h, H)
    {
        rep(w, W)
        {
            if (grid[h][w] == 1)
            {
                isLit[h][w] = true;
                tate[w] = true;
                yoko[h] = true;
            }
            else if (grid[h][w] == 2)
            {
                tate[w] = false;
                yoko[h] = false;
            }
            else
            {
                if (tate[w] || yoko[h])
                    isLit[h][w] = true;
            }
        }
    }
    return isLit;
}

int main()
{
    cin >> H >> W >> N >> M;
    vvi grid(1500, vi(1500, 0));  // 0: null, 1: light, 2: block
    vvi gridT(1500, vi(1500, 0)); // 0: null, 1: light, 2: block
    int ans = 0;

    rep(i, N)
    {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        grid[A[i]][B[i]] = 1;
        gridT[H - 1 - A[i]][W - 1 - B[i]] = 1;
    }

    rep(i, M)
    {
        cin >> C[i] >> D[i];
        C[i]--;
        D[i]--;
        grid[C[i]][D[i]] = 2;
        gridT[H - 1 - C[i]][W - 1 - D[i]] = 2;
    }

    vv(bool) isLit = calc(H, W, grid);
    vv(bool) isLitT = calc(H, W, gridT);

    rep(h, H)
    {
        rep(w, W)
        {
            if (isLit[h][w] || isLitT[H - 1 - h][W - 1 - w])
            {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}