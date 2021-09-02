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
#define show(x) cout << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
// using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
// using vp = vector<P>;
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

ll N, P, K;
vvl A;

ll cnt(ll X){
    vvl D(N, vl(N, 0));
    rep(h, N){
        rep(w, N){
            D[h][w] = (A[h][w] == -1LL ? X : A[h][w]);
        }
    }

    rep(k, N){
        rep(n1, N){
            rep(n2, N){
                chmin(D[n1][n2], D[n1][k] + D[k][n2]);
            }
        }
    }

    ll res = 0;
    rep(n1, N){
        srep(n2, n1 + 1, N){
            if(D[n1][n2] <= P){
                res++;
            }
        }
    }
    return res;
}

void solve()
{
    cin >> N >> P >> K;
    A = vvl(N, vl(N));
    rep(h, N){
        rep(w, N){
            cin >> A[h][w];
        }
    }

    ll l1 = -1LL; // K個以上
    ll r1 = 1e9 + 2LL; // K個未満
    ll mid1;

    ll l2 = -1LL; // K個より多い
    ll r2 = 1e9 + 2LL; // K個以下
    ll mid2;

    while(r1 - l1 > 1LL){
        mid1 = (r1 + l1) / 2LL;
        if(cnt(mid1) >= K){
            l1 = mid1;
        } else {
            r1 = mid1;
        }
    }

    while(r2 - l2 > 1LL){
        // show(l2);
        // show(r2);
        mid2 = (r2 + l2) / 2LL;
        if(cnt(mid2) > K){
            l2 = mid2;
        } else {
            r2 = mid2;
        }
    }

    if(l1 == l2 || l1 == -1LL){
        cout << "0\n";
        return;
    }

    if(l1 == 1e9 + 1LL){
        cout << "Infinity\n";
        return;
    }

    if(r2 == 0LL){
        r2++;
    }

    cout << l1 - r2 + 1 << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}