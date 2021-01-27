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

ll X, Y, Z, K;
vl A, B, C;

priority_queue<ll> pq;
// 二分探索
// val以上のものがK個ジャストになるように見る

ll count(ll val) // val以上の美味しさのケーキが何通りありえるか。
{
    ll res = 0LL;
    rep(ai, A.size())
    {
        ll a = A[ai];
        rep(bi, B.size())
        {
            ll b = B[bi];
            ll diff = (C.size() - (ll)(lower_bound(rng(C), val - (a + b)) - C.begin()));
            // cerr << "diff:" << diff << endl;
            res += diff;
        }
    }
    return res;
}

int main()
{
    cin >> X >> Y >> Z >> K;

    rep(i, X)
    {
        ll x;
        cin >> x;
        A.pb(x);
    }
    sort(rng(A));

    rep(i, Y)
    {
        ll y;
        cin >> y;
        B.pb(y);
    }
    sort(rng(B));

    rep(i, Z)
    {
        ll z;
        cin >> z;
        C.pb(z);
    }
    sort(rng(C));

    ll lb = 0;             // lbだとK個以上
    ll ub = 30000000000LL; // ubだとK個未満
    ll mid, cnt;

    while (ub - lb > 1LL)
    {
        mid = (ub + lb) / 2LL;
        cnt = count(mid);
        // cout << "mid:" << mid << " cnt:" << cnt << endl;
        if (cnt >= K)
        {
            lb = mid;
        }
        else
        {
            ub = mid;
        }
    }

    ll kVal = lb;

    rep(ai, A.size())
    {
        ll a = A[ai];
        rep(bi, B.size())
        {
            ll b = B[bi];
            ll cMinId = (ll)(lower_bound(rng(C), kVal - (a + b)) - C.begin());
            srep(ci, cMinId, C.size())
            {
                ll c = C[ci];
                if (a + b + c > kVal)
                {
                    pq.push(a + b + c);
                }
            }
        }
    }

    rep(i, K)
    {
        if (!pq.empty())
        {
            cout << pq.top() << endl;
            pq.pop();
        }
        else
        {
            cout << kVal << endl;
        }
    }

    return 0;
}