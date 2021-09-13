#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
// #include <atcoder/modint>
#include <atcoder/dsu>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/scc>
// #include <atcoder/twosat>

namespace atcoder{};
using namespace atcoder;
using namespace std;

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
#define show(x) cerr << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
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

int N, Q;
vi C, T, X, Y;

void input(){
    cin >> N >> Q;
    rep(i, N){
        int c;
        cin >> c;
        C.eb(--c);
    }

    rep(i, Q){
        int t, x, y;
        cin >> t >> x >> y;
        T.eb(t);
        X.eb(--x);
        Y.eb(--y);
    }
}

vi student2Leader;
vector<set<int>> leader2AskedClassSet;

struct DSU2{
    int par;
    map<int, int> class2Cnt;
};

vector<DSU2> dsu2;

void initD(){
    dsu2 = vector<DSU2>(N);
    rep(i, N){
        dsu2[i].par = i;
        int leader = student2Leader[i];
        if(leader2AskedClassSet[leader].find(C[i]) != leader2AskedClassSet[leader].end()){ // exist
            dsu2[i].class2Cnt[C[i]]++;
        }
    }
}

int getPar(int x){
    if(x == dsu2[x].par){
        return x;
    }
    return dsu2[x].par = getPar(dsu2[x].par);
}

void merge(int x, int y){
    x = getPar(x);
    y = getPar(y);
    if(x == y){
        return;
    }

    if(dsu2[x].class2Cnt.size() < dsu2[y].class2Cnt.size()){
        swap(x, y);
    }

    dsu2[y].par = x;
    for(auto [yClass, yClassSize] : dsu2[y].class2Cnt){
        dsu2[x].class2Cnt[yClass] += yClassSize;
    }
    return;
}

int query(int x, int y){
    x = getPar(x);
    return dsu2[x].class2Cnt[y];
}

void solve()
{
    input();
    dsu d0(N);
    student2Leader = vi(N);
    leader2AskedClassSet = vector<set<int>>(N);

    rep(q, Q){
        int t = T[q];
        int x = X[q];
        int y = Y[q];

        if(t == 1){
            d0.merge(x, y);
        }
    }

    rep(i, N){
        student2Leader[i] = d0.leader(i);
    }

    rep(q, Q){
        int t = T[q];
        int x = X[q];
        int y = Y[q];
        if(t == 2){
            leader2AskedClassSet[student2Leader[x]].insert(y);
        }
    }

    initD();

    rep(q, Q){
        int t = T[q];
        int x = X[q];
        int y = Y[q];

        if(t == 1){
            merge(x, y);
        } else {
            cout << query(x, y) << "\n";
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}