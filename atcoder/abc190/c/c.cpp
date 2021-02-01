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

int N, M, K;
vi A, B, C, D;

int countJoken(int s)
{ // Dを選ぶものが1になってる。
    v(bool) hasBall(N + 1, false);

    rep(i, K)
    {
        if ((s >> i) % 2 == 0)
        {
            hasBall[D[i]] = true;
        }
        else
        {
            hasBall[C[i]] = true;
        }
    }

    int cnt = 0;
    rep(i, M)
    {
        if (hasBall[A[i]] && hasBall[B[i]])
            cnt++;
    }
    // if (cnt == 4)
    //     cerr << s << endl;
    return cnt;
}

int main()
{
    cin >> N >> M;
    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        A.pb(a);
        B.pb(b);
    }
    cin >> K;
    rep(i, K)
    {
        int c, d;
        cin >> c >> d;
        C.pb(c);
        D.pb(d);
    }

    int ans = 0;

    rep(s, bn(K) + 1)
    {
        chmax(ans, countJoken(s));
    }

    cout << ans << endl;

    return 0;
}