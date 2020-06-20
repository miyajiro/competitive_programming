#include <bits/stdc++.h>
#define fr first
#define sc second
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define rep1(i, n) for(ll i = 1; i <= (n); ++i)
#define rrep(i, n) for(ll i = (n)-1; i >= 0; --i)
#define rrep1(i, n) for(ll i = (n); i >= 1; --i)
#define srep(i, s, t) for(ll i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (ll)(x).size()
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
typedef long long int ll;
typedef unsigned ull;
// typedef unsigned long long uint;
typedef pair<ll, ll> P;
// typedef tuple<ll, ll, ll> T;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
// typedef vector<T> vt;
inline ll getll() {
    ll x;
    scanf("%d", &x);
    return x;
}
template <typename T> inline istream &operator>>(istream &i, v(T) & v) {
    rep(j, sz(v)) i >> v[j];
    return i;
}
template <typename T> string join(const v(T) & v) {
    stringstream s;
    rep(i, sz(v)) s << ' ' << v[i];
    return s.str().substr(1);
}
template <typename T> inline ostream &operator<<(ostream &o, const v(T) & v) {
    if(sz(v))
        o << join(v);
    return o;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &i, pair<T1, T2> &v) {
    return i >> v.fi >> v.se;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &o, const pair<T1, T2> &v) {
    return o << v.fi << "," << v.se;
}
template <typename T> inline ll suma(const v(T) & a) {
    ll res(0);
    for(auto &&x : a)
        res += x;
    return res;
}
template <class T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if(b < a) {
        a = b;
        return 1;
    }
    return 0;
}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const ll INF = 1001001001;
#define dame                                                                   \
    {                                                                          \
        puts("-1");                                                            \
        return 0;                                                              \
    }
#define yn                                                                     \
    { puts("Yes"); }                                                           \
    else {                                                                     \
        puts("No");                                                            \
    }

ll N, Q;
ll A[200000], B[200000];

struct cmp1 {
    bool operator()(const ll &a, const ll &b) const {
        if(A[a] == A[b])
            return a < b;
        return A[a] > A[b];
    }
};
struct cmp2 {
    bool operator()(const ll &a, const ll &b) const {
        if(A[a] == A[b])
            return a < b;
        return A[a] < A[b];
    }
};

set<ll, cmp1> s_array[200000];
set<ll, cmp2> s;

int main() {

    cin >> N >> Q;

    rep(i, N) {
        cin >> A[i] >> B[i];
        B[i]--;
        s_array[B[i]].insert(i);
    }

    rep(i, 200000) {
        if(sz(s_array[i]) > 0) {
            s.insert(*(s_array[i].begin()));
        }
    }

    rep(i, Q) {
        ll C, to;
        cin >> C >> to;
        C--;
        to--;
        ll from = B[C];

        B[C] = to;

        if(*(s_array[from].begin()) == C) {
            s_array[from].erase(C);
            s.erase(C);
            if(s_array[from].size() > 0) {
                s.insert(*(s_array[from].begin()));
            }
        } else {
            s_array[from].erase(C);
        }

        if(s_array[to].size() > 0) {
            ll highest_index = *(s_array[to].begin());
            s_array[to].insert(C);
            if(C == *(s_array[to].begin())) {
                s.erase(highest_index);
                s.insert(C);
            }
        } else {
            s_array[to].insert(C);
            s.insert(C);
        }

        cout << A[*(s.begin())] << endl;
    }
}