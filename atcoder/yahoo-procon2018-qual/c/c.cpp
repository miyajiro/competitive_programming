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
#define bn(x) ((1LL << x) - 1LL)
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

void showBit(ll N)
{
    ll keta = 0;
    ll _N = N;
    while (_N > 0)
    {
        _N /= 2;
        keta++;
    }

    rrep(i, keta)
    {
        if ((N >> i) % 2LL == 1LL)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    cout << endl;
}

int N;
vl X(18), C(18), V(18), money(19);
vl dp_memo(1 << 18, -1LL);
vv(ll) f_memo(1 << 18, vl(19, -1LL));

ll size_of_set(ll S)
{
    ll res = 0LL;
    while (S > 0)
    {
        if (S % 2LL == 1LL)
            res++;
        S /= 2LL;
    }
    return res;
}

ll f(ll S, ll k)
{ // Sが販売停止の状態でk個財宝売り払ったときの得点の最大値
    if (f_memo[S][k] != -1LL)
    {
        return f_memo[S][k];
    }

    ll moneyPos = money[k];
    ll sumCost = 0LL;
    ll sumValue = 0LL;
    rep(i, N)
    {
        if ((S | (1LL << i)) != S) // Sにiが入っていないなら。
        {
            sumCost += C[i];
            sumValue += V[i];
        }
    }

    if (sumCost <= moneyPos) // 全部買えるなら買う
        return f_memo[S][k] = sumValue;

    ll res = 0;
    rep(i, N)
    {
        if ((S | (1LL << i)) != S) // Sにiが入っていないなら。
        {
            res = max(res, f(S | (1LL << i), k));
        }
    }

    return f_memo[S][k] = res;
}

ll dp(ll S) // Sに含まれる商品の販売が停止している時の最終的な得点。dp(S) = max{f(S, sum[この時点の所持金合計]), min{dp(S∪{t})}}
{
    if (dp_memo[S] != -1LL)
    {
        return dp_memo[S];
    }

    ll nowBuyingPoint = f(S, size_of_set(S)); // この時点で購入した場合の得点。

    ll nowSellingPoint = 0xfffffffffffffff;

    rep(i, N)
    { // 次にどの商品を停止するか全探索
        ll newS = (S | (1LL << i));
        if (newS == S)
            continue;

        nowSellingPoint = min(nowSellingPoint, dp(newS));
    }

    if (nowSellingPoint == 0xfffffffffffffff)
        nowSellingPoint = 0LL;

    dp_memo[S] = max(nowBuyingPoint, nowSellingPoint);

    return dp_memo[S];
}

int main()
{

    cin >> N;
    rep(i, N)
    {
        cin >> X[i];
    }
    rep(i, N)
    {
        cin >> C[i];
    }
    rep(i, N)
    {
        cin >> V[i];
    }

    rep1(i, N)
    {
        money[i] = money[i - 1] + X[i - 1];
    }

    cout << dp(0LL) << endl;
    return 0;
}