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

ll N, L, K;
vl A;
vl B;

bool check(ll minLen){
    ll cnt = 0;
    ll nowLen = 0;
    rep(bi, N){
        nowLen += B[bi];

        if(nowLen >= minLen){
            cnt++;
            nowLen = 0;
        }
    }

    return (cnt >= K);
}

int main()
{
    cin >> N >> L >> K;
    K++;
    A.pb(0);
    rep(i, N){
        ll a;
        cin >> a;
        A.pb(a);
    }
    A.pb(L);

    N = A.size() - 1;

    rep(i, N){
        B.pb(A[i+1]-A[i]);
    }

    ll lb = 1;
    ll ub = 1e+10;

    while(ub - lb > 1){
        ll mid = (ub + lb) / 2LL;
        if(check(mid)){
            lb = mid;
        } else {
            ub = mid;
        }
    }

    cout << lb << endl;

    return 0;
}