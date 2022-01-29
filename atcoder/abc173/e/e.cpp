#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/convolution>
#include <atcoder/modint>
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

int N, K;
using mint = modint1000000007;
using vm = vector<mint>;
vl nA, pA;

void solve()
{
    cin >> N >> K;
    rep(i, N){
        ll a;
        cin >> a;

        if(a >= 0){
            pA.eb(a);
        } else {
            nA.eb(-a);
        }
    }

    sort(rrng(pA));
    sort(rrng(nA));

    mint ans = 1;
    int pCnt = 0;
    int pL = sz(pA);
    int nCnt = 0;
    int nL = sz(nA);

    if(pL == 0 && K % 2 == 1){ // 絶対マイナス
        sort(rng(nA));
        rep(i, K){
            ans *= -nA[i];
        }
        cout << ans.val() << "\n";
        return;
    }

    while(pCnt + nCnt < K){
        if(pCnt == pL){ // pを使い切った
            ans *= -nA[nCnt++];
            continue;
        }

        if(nCnt == nL){ // nを使い切った
            ans *= pA[pCnt++];
            continue;
        }

        if(nCnt == nL - 1){ // マイナスが残り1個
            ans *= pA[pCnt++];
            continue;
        }

        if(pCnt == pL - 1){ // プラスが残り1個
            if((K - (pCnt + nCnt)) % 2 == 1){ // Kまで奇数ならプラスを入れる
                ans *= pA[pCnt++];
                continue;
            } else { // Kまで偶数ならマイナス2つ
                ans *= -nA[nCnt++];
                ans *= -nA[nCnt++];
                continue;
            }
            ans *= pA[pCnt++];
            continue;
        }

        if(K - (pCnt + nCnt) == 1){ // 残り1個ならプラス
            ans *= pA[pCnt++];
            continue;
        }

        if(pA[pCnt] * pA[pCnt + 1] <= nA[nCnt] * nA[nCnt + 1]) {
            ans *= -nA[nCnt++];
            ans *= -nA[nCnt++];
            continue;
        } else {
            ans *= pA[pCnt++];
            continue;
        }
    }

    cout << ans.val() << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}