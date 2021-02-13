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

ll B, C;

// 負で作れる最小の数. 負が作れないなら0
ll negMin(ll b, ll c){
    if(b > 0LL) {
        c--;
        b = -b;
    }

    b -= c / 2LL;
    return b;
}

// 負で作れる最大の数. 負が作れないなら0
ll negMax(ll b, ll c){
    if(b == 0LL){
        if (c <= 1LL){
            return 0LL;
        } else {
            return -1LL;
        }
    }

    if(b<0LL && c < 4LL){
        return b;
    }

    if (b < 0LL){
        c--;
        b = -b;
    }

    c--; // 最後のc--やっとく。

    b -= (c / 2LL);

    return min(-1LL, -b);
}

// 0を作れるかどうか
ll zero(ll b, ll c){
    if(b < 0LL){
        c -= 1LL;
        b = -b;
    }

    c -= (b * 2);

    if(c >= 0LL)
        return 1LL;
    return 0LL;
}

// 正で作れる最小の数. 正が作れないなら0
ll posMin(ll b, ll c){
    if (b == 0LL){
        if(c < 3LL) // 正が作れない場合。
            return 0LL;
        else
            return 1LL;
    }

    if (b < 0LL){
        c--;
        b = -b;
    }

    b -= (c / 2LL);

    return max(1LL, b);
}

// 正で作れる最大の数. 正が作れないなら0
ll posMax(ll b, ll c){
    if (b == 0LL && c < 3LL){ // 正が作れない場合。
        return 0LL;
    }

    if (b > 0LL && c <= 3LL){
        return b;
    }

    if (b > 0LL){
        b = -b;
        c--;
    }

    c--; // 正に戻る分先にひいとく。

    b -= (c/2LL); // 引けるだけ引く。

    return -b;
}

int main()
{
    cin >> B >> C;

    ll ans = 0LL;
    ll negmin = negMin(B, C);
    ll negmax = negMax(B, C);
    ll z = zero(B, C);
    ll posmin = posMin(B, C);
    ll posmax = posMax(B, C);

    if(negmin != 0LL){
        ans += (negmax - negmin + 1LL);
    }

    if(posmin != 0LL){
        ans += (posmax - posmin + 1LL);
    }

    ans += z;

    cout << ans << endl;

    return 0;
}