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
// モノイドの型 S
// \cdot: S \times S \to S⋅:S×S→S を計算する関数 S op(S a, S b)
// e を返す関数 S e()
// 写像の型 F
// f(x)f(x) を返す関数 S mapping(F f, S x)
// f∘g を返す関数 F composition(F f, F g)
// idid を返す関数 F id()
using mod = modint998244353;
struct segMonoidType {
    mod value;
    ll size;
};

struct segFType {
    mod a;
    mod b;
};

segMonoidType segOP(segMonoidType a, segMonoidType b){
    return segMonoidType{a.value + b.value, a.size + b.size};
}

segMonoidType segE(){
    return segMonoidType{0, 0};
}

segMonoidType segMapping(segFType f, segMonoidType x){
    return segMonoidType{f.a * x.value + f.b * x.size, x.size};
}

segFType segComposition(segFType f, segFType g){
    return segFType{f.a * g.a, f.a * g.b + f.b};
}

segFType segID(){
    return segFType{1, 0};
}

ll N, Q;

int main()
{
    cin >> N >> Q;

    lazy_segtree<segMonoidType, segOP, segE, segFType, segMapping, segComposition, segID> lazySeg(N);

    rep(i, N){
        ll a;
        cin >> a;
        lazySeg.set(i, segMonoidType{a, 1});
    }
    rep(i, Q){
        int q;
        cin >> q;
        if(q == 0){
            ll l, r, b, c;
            cin >> l >> r >> b >> c;
            lazySeg.apply(l, r, segFType{b, c});
        } else {
            ll l, r;
            cin >> l >> r;
            cout << lazySeg.prod(l, r).value.val() << endl;
        }
    }
    return 0;
}