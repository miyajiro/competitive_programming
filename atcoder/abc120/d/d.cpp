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

ll N, M;
vl A, B;
vl ans;

ll par[100000];
ll cnt[100000];

void init(){
    rep(i, N){
        par[i] = i;
        cnt[i] = 1LL;
    }
}

ll getPar(ll n){
    if(par[n] == n){
        return n;
    }

    return par[n] = getPar(par[n]);
}

bool same(ll a, ll b){
    return getPar(a) == getPar(b);
}

ll size(ll a){
    ll root = getPar(a);
    return cnt[root];
}

ll calc(ll a, ll b){
    return same(a, b) ? 0LL : size(a) * size(b);
}

void merge(ll a, ll b){
    if(same(a,b))
        return;

    ll ra = getPar(a);
    ll rb = getPar(b);

    cnt[ra] += cnt[rb];
    par[rb] = ra;
}

int main()
{
    cin >> N >> M;
    ll cnt = N * (N - 1) / 2LL;
    init();

    rep(i, M){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        A.pb(a);
        B.pb(b);
    }

    ans.pb(cnt);
    rrep1(i, M - 1){
        cnt -= calc(A[i], B[i]);
        merge(A[i], B[i]);
        ans.pb(cnt);
    }

    rrep(i, ans.size()){
        cout << ans[i] << endl;
    }

    return 0;
}