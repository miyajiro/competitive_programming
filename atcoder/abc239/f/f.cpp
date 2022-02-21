#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
// #include <atcoder/modint>
// #include <atcoder/dsu>
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
#define show(x) cerr << #x << " = " << x << "\n";
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



int N, M;
vi D, A, B;

vi par;
vector<multiset<int>> st; // ここに欲しい人を格納。常に親を参照
vector<P> ans; // a, b

void dsuInit(){
    par = vi(N);
    st = vector<multiset<int>>(N);

    rep(i, N){
        par[i] = i;
    }

    rep(i, N){
        rep(j, D[i]){
            st[i].insert(i);
        }
    }
}

int getPar(int a){
    if(par[a] == a){
        return a;
    }
    return par[a] = getPar(par[a]);
}

void merge(int a, int b){
    a = getPar(a);
    b = getPar(b);

    auto aReqIte = st[a].begin();
    int aReq = *aReqIte;
    st[a].erase(aReqIte);

    auto bReqIte = st[b].begin();
    int bReq = *bReqIte;
    st[b].erase(bReqIte);

    ans.eb(P(aReq, bReq));

    par[b] = a;
    st[a].merge(st[b]);

    return;
}

int getReq(int a){ // その塊がどれくらい欲しているか
    a = getPar(a);
    return st[a].size();
}

bool isSame(int a, int b){
    return getPar(a) == getPar(b);
}

void solve()
{
    cin >> N >> M;

    int dSum = 0;
    rep(i, N){
        int d;
        cin >> d;
        D.eb(d);
        dSum += d;
    }
    if(dSum != 2 * N - 2){
        cout << -1 << "\n";
        return;
    }

    dsuInit();

    rep(i, M){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        if(getReq(a) <= 0 || getReq(b) <= 0){ // 元々つなげない場合はアウト
            cout << -1 << "\n";
            return;
        }
        merge(a, b);
    }

    // rep(i, N){
    //     show(i);
    //     show(getReq(i));
    // }

    // 連結成分がでかいやつから繋いでいく
    vp reqAndPar;
    rep(i, N){
        // show(i);
        // show(getPar(i));
        if(i != getPar(i)){
            continue;
        }

        reqAndPar.eb(P(getReq(i), i));
    }
    sort(rrng(reqAndPar));

    {
        // show(reqAndPar[0].fr);
        // show(reqAndPar[0].sc);
        int a = reqAndPar[0].sc;
        rep1(pi, sz(reqAndPar) - 1){
            // show(reqAndPar[pi].fr);
            // show(reqAndPar[pi].sc);
            int b = reqAndPar[pi].sc; // 受け継ぎ先の親

            if(getReq(a) <= 0 || getReq(b) <= 0){ // 元々つなげない場合はアウト
                cout << -1 << "\n";
                return;
            }
            merge(a, b);
        }
    }

    // 最後に0~N-1で連結してるか, 欲してるやついないか見る
    rep(i, N){
        if(getReq(i) > 0){
            cout << -1 << "\n";
            return;
        }
        if(!isSame(0, i)){
            cout << -1 << "\n";
            return;
        }
    }

    srep(i, M, N - 1){
        cout << ans[i].fr + 1 << " " << ans[i].sc + 1 << "\n";
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