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

ll N, Q;
vl A;
vl T, X, Y;

using segType = ll;

segType segOP(segType a, segType b) {
    return max(a, b);
}

segType segE(){
    return -1LL;
}

ll segFVar;
bool segF(segType a){
    return a < segFVar;
}

int main()
{
    cin >> N >> Q;
    segtree<segType, segOP, segE> seg(N);

    rep(i, N){
        ll a;
        cin >> a;
        A.pb(a);
        seg.set(i, a);
    }

    rep(q, Q){
        ll t, x, y;
        cin >> t >> x >> y;

        if(t == 1LL){
            x--;
            seg.set(x, y);
        }
        if(t == 2LL){
            x--;
            y--;
            cout << seg.prod(x, y + 1) << endl;
        }
        if(t == 3LL){
            x--;
            segFVar = y;
            cout << seg.max_right<segF>(x) + 1 << endl;
        }
    }

    return 0;
}