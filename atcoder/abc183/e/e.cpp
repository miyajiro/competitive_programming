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
using namespace atcoder;
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

v(string) s(2001);
vv(bool) isWall(2001, v(bool)(2001));
using mint = modint1000000007;
vv(mint) dp(2001, v(mint)(2001));
vv(mint) imosNaname;
v(mint) imosTate, imosYoko;

ll H, W;

int main()
{
    cin >> H >> W;

    rep(i, W + 1)
        imosTate.pb(0);

    rep(i, H + 1)
        imosYoko.pb(0);

    imosNaname.pb(v(mint)(W + 1, 0));
    rep(i, H)
    {
        imosNaname.pb(v(mint)(1, 0));
    }

    rep(h, H)
    {
        cin >> s[h];
        rep(w, W)
        {
            isWall[h + 1][w + 1] = (s[h][w] == '#');
        }
    }
    dp[1][1] = 1;
    imosTate[1] = 1;
    imosYoko[1] = 1;
    imosNaname[0][0] = 1;

    rep1(h, H)
    {
        rep1(w, W)
        {
            if (h == 1 && w == 1)
                continue;

            int nanameH;
            int nanameW;
            if (w < h)
            {
                nanameH = h - w;
                nanameW = 0;
            }
            else
            {
                nanameH = 0;
                nanameW = w - h;
            }

            if (isWall[h][w])
            {
                imosTate[w] = 0;
                imosYoko[h] = 0;
                imosNaname[nanameH][nanameW] = 0;
            }

            dp[h][w] = imosTate[w] + imosYoko[h] + imosNaname[nanameH][nanameW];
            imosTate[w] += dp[h][w];
            imosYoko[h] += dp[h][w];
            imosNaname[nanameH][nanameW] += dp[h][w];
        }
    }

    cout << dp[H][W].val() << endl;

    return 0;
}