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

ll N, M, V, X;
vl A;

bool hasPossibility(ll n)
{
    vl diff;
    vl B;
    ll remainVote = M * V;

    rep(i, N)
    {
        diff.pb(0LL);
        B.pb(A[i]);
    }
    B[n] += M;
    remainVote -= M;
    sort(rng(B));

    ll newN;
    ll nowRank;

    rrep(i, N)
    {
        if (B[i] == A[n] + M)
        {
            newN = i;
            nowRank = N - i;
            diff[newN] += M;
            break;
        }
    }

    // cerr << "n=" << n << ": ";
    // rep(i, N)
    // {
    //     cerr << B[i] << " ";
    // }
    // cerr << endl;
    // cerr << "nowRank=" << nowRank << endl;
    // cerr << "X=" << X << endl;

    if (nowRank > X) // この時点でX位より悪い順位ならアウト
    {
        return false;
    }

    // newNより大きいスコアに全部投票。
    remainVote -= (N - 1LL - newN) * M;

    rep(i, newN)
    { // newNより小さいスコアにnewN以下まで全部投票。
        ll numOfVote = min(M, B[newN] - B[i]);
        diff[i] += numOfVote;
        B[i] += numOfVote;
        remainVote -= numOfVote;
    }

    if (remainVote <= 0)
    {
        return true;
    }

    rrep(i, newN)
    { // i番目をnewNよりデカくする。

        nowRank++;

        if (nowRank > X)
        { // X位に入らないならアウト
            return false;
        }

        remainVote -= (M - diff[i]);

        if (remainVote <= 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> N >> M >> V >> X;
    rep(i, N)
    {
        ll a;
        cin >> a;
        A.pb(a);
    }

    sort(rng(A));

    // lb: 入らない, ub: 入る
    ll lb = -1LL;
    ll ub = N;
    while (ub - lb > 1LL)
    {
        ll mid = (ub + lb) / 2LL;
        if (hasPossibility(mid))
        {
            ub = mid;
        }
        else
        {
            lb = mid;
        }
    }

    cout << N - ub << endl;

    return 0;
}