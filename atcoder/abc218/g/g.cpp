#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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

ll N, L;
vl A;
vl As;
vl U, V;
vvl G;
vl maxMedians, minMedians;
fenwick_tree<ll> ft;

void calcMedians(ll now, ll prev){
    ft.add(A[now], 1); // 今入ってる

    if(sz(G[now]) == 1 && G[now][0] == prev){ // 末端の場合
        // この時点のftから中央値求める
        ll ftSum = ft.sum(0, L);
        if(ftSum % 2 == 0){ // 偶数個
            ll medVal1 = ftSum / 2;
            ll l1 = -1LL;
            ll r1 = L;

            while(r1 - l1 > 1){
                ll mid = (l1 + r1) / 2;
                if(ft.sum(0, mid + 1) >= medVal1){
                    r1 = mid;
                } else {
                    l1 = mid;
                }
            }

            ll medVal2 = ftSum / 2 + 1;
            ll l2 = -1LL;
            ll r2 = L;

            while(r2 - l2 > 1){
                ll mid = (l2 + r2) / 2;
                if(ft.sum(0, mid + 1) >= medVal2){
                    r2 = mid;
                } else {
                    l2 = mid;
                }
            }

            ll m = (As[r1] + As[r2]) / 2;
            maxMedians[now] = m;
            minMedians[now] = m;
        } else { // 奇数個
            ll medVal = ftSum / 2 + 1;
            ll l = -1LL;
            ll r = L;

            while(r - l > 1){
                ll mid = (l + r) / 2;
                if(ft.sum(0, mid + 1) >= medVal){
                    r = mid;
                } else {
                    l = mid;
                }
            }
            maxMedians[now] = As[r];
            minMedians[now] = As[r];
        }

        ft.add(A[now], -1LL);
        return;
    }

    ll maxMed = 0;
    ll minMed = 0xfffffffffffffff;
    for(auto nex : G[now]){
        if(nex == prev){
            continue;
        }

        calcMedians(nex, now);

        chmax(maxMed, minMedians[nex]);
        chmin(minMed, maxMedians[nex]);
    }

    maxMedians[now] = maxMed;
    minMedians[now] = minMed;

    ft.add(A[now], -1LL);
}

void solve()
{
    cin >> N;
    G = vvl(N);
    maxMedians = vl(N);
    minMedians = vl(N);
    rep(i, N){
        ll a;
        cin >> a;
        A.eb(a);
        As.eb(a);
    }
    sort(rng(As));
    uni(As);

    rep(i, N){
        A[i] = (lower_bound(rng(As), A[i]) - As.begin());
    }
    L = sz(As);
    ft = fenwick_tree<ll>(L);

    rep(i, N - 1){
        ll u, v;
        cin >> u >> v;
        U.eb(--u);
        V.eb(--v);
        G[u].eb(v);
        G[v].eb(u);
    }

    calcMedians(0, -1LL);

    // rep(i, N){
    //     show(i + 1);
    //     show(maxMedians[i]);
    //     show(minMedians[i]);
    // }

    cout << maxMedians[0] << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}