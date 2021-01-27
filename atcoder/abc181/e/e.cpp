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

ll N, M;

int main()
{
    cin >> N >> M;

    vl H(N), W(M);
    vl pairSum(N), pairSumR(N);

    rep(i, N)
    {
        cin >> H[i];
    }

    rep(i, M)
    {
        cin >> W[i];
    }

    sort(rng(H));
    sort(rng(W));

    for (int i = 1; i < N; i += 2)
    {
        if (i == 1)
        {
            pairSum[i] = H[i] - H[i - 1];
            continue;
        }

        pairSum[i] = pairSum[i - 2] + H[i] - H[i - 1];
    }

    for (int i = N - 2; i >= 0; i -= 2)
    {
        if (i == N - 2)
        {
            pairSumR[i] = H[i + 1] - H[i];
            continue;
        }

        pairSumR[i] = pairSumR[i + 2] + H[i + 1] - H[i];
    }

    ll wi = 0;
    ll ans = 0xffffffffffffff;
    for (ll hi = -1; hi < N; hi++)
    { // [H[hi], H[hi+1])の変身形態を処理
        while (wi < M && (hi == -1 || H[hi] <= W[wi]) && (hi == N - 1 || W[wi] < H[hi + 1]))
        {
            // cerr << "W[wi]=" << W[wi] << " H[hi]=" << ((hi == -1) ? -1000 : H[hi]) << " H[hi+1]=" << ((hi == N - 1) ? 1000 : H[hi + 1]) << endl;
            if ((hi + 2) % 2 == 0)
            { // hiが偶数。H[hi]とペアを組ませる場合
                ll left = ((hi == 0) ? 0LL : pairSum[hi - 1]);
                ll right = ((hi == N - 1) ? 0LL : pairSumR[hi + 1]);
                ans = min(ans, left + right + W[wi] - H[hi]);
            }
            else
            { // H[hi + 1]とペアを組ませる場合
                ll left = ((hi == -1) ? 0LL : pairSum[hi]);
                ll right = ((hi == N - 2) ? 0LL : pairSumR[hi + 2]);
                ans = min(ans, left + right + H[hi + 1] - W[wi]);
            }
            wi++;
        }
    }

    cout << ans << endl;

    return 0;
}