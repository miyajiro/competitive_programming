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

double X, Y, R;
ll x, y, _r;
bool inside(ll _y, ll _x)
{
    ll dist = (y - _y) * (y - _y) + (x - _x) * (x - _x);

    return (dist <= _r * _r);
}

int main()
{
    cin >> X >> Y >> R;
    x = round(X * 10000LL);
    y = round(Y * 10000LL);
    _r = round(R * 10000LL);
    if (x < 0)
        x = -x;
    if (Y < 0)
        y = -y;

    ll xMin = ((x - _r) / 10000LL) * 10000LL - 30000LL;
    ll xMax = ((x + _r) / 10000LL) * 10000LL + 30000LL;
    ll yMin = ((y - _r) / 10000LL) * 10000LL - 30000LL;
    ll yMax = ((y + _r) / 10000LL) * 10000LL + 30000LL;

    ll by = (round(y / 10000LL)) * 10000LL;

    ll l = xMin;
    ll r = xMax;

    ll ans = 0;

    for (ll ny = by; ny <= yMax; ny += 10000LL)
    {
        if (ny <= by + 50000LL)
        {
            l = xMin;
            r = xMax;
        }
        while (l <= r && !inside(ny, l))
        {
            l += 10000LL;
        }

        while (l <= r && !inside(ny, r))
        {
            r -= 10000LL;
        }

        if (r < l)
        {
            break;
        }

        ans += ((r - l) / 10000LL + 1LL);
    }

    l = xMin;
    r = xMax;

    for (ll ny = by - 10000LL; ny >= yMin; ny -= 10000LL)
    {
        if (ny >= by - 60000LL)
        {
            l = xMin;
            r = xMax;
        }
        while (l <= r && !inside(ny, l))
        {
            l += 10000LL;
        }

        while (l <= r && !inside(ny, r))
        {
            r -= 10000LL;
        }

        if (r < l)
        {
            break;
        }

        ans += ((r - l) / 10000LL + 1LL);
    }

    cout << ans << endl;
}