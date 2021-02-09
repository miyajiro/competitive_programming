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

ll N, T;
vl NS;
vl A;
vv(ll) AS(2, vl()), timeSum(2, vl());

int main()
{
    cin >> N >> T;
    NS.pb(N/2LL);
    NS.pb(N - NS[0]);
    rep(i, N){
        ll a;
        cin >> a;
        A.pb(a);
    }

    rep(i, N){
        if(i < NS[0]){
            AS[0].pb(A[i]);
        } else {
            AS[1].pb(A[i]);
        }
    }

    timeSum[0].pb(0LL);
    timeSum[1].pb(0LL);

    rep(i, 2){
        ll n = NS[i];
        vl a = AS[i];
        rep(s, 1 << n){
            ll sum = 0;
            rep(bit, n){
                if((s >> bit) % 2 == 1){
                    sum += a[bit];
                }
            }
            timeSum[i].pb(sum);
        }
    }

    ll ans = 0;

    sort(rng(timeSum[0]));
    sort(rng(timeSum[1]));

    vl timeSum0 = timeSum[0];
    vl timeSum1 = timeSum[1];

    // for(auto sum : AS[0]){
    //     cerr << sum << " ";
    // }
    // cerr << endl;

    // for(auto sum : AS[1]){
    //     cerr << sum << " ";
    // }
    // cerr << endl;

    for(auto sum : timeSum0){
        ll sum1Index = upper_bound(rng(timeSum1), T - sum) - timeSum1.begin() - 1LL;
        if(sum1Index >= 0){
            chmax(ans, sum + timeSum1[sum1Index]);
        }
    }

    cout << ans << endl;

    return 0;
}