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

ll N;
vl A, B, B2A;
vi ans;

void solve()
{
    cin >> N;
    rep(i, N){
        ll a;
        cin >> a;
        A.eb(a);
    }

    rep(i, N){
        if(i == 0){
            B.eb(A[0]);
            B2A.eb(0);
            continue;
        }

        if(A[i] == A[i - 1]){
            continue;
        }
        B.eb(A[i]);
        B2A.eb(i);
    }

    int M = sz(B);

    ans = vi(N, 0);
    if(M == 1){
        rep(i, N){
            cout << "0 ";
        }
        cout << "\n";
        return;
    }

    rep(i, M){
        if(i == 0){
            if(B[0] > B[1]){
                ans[B2A[0]] = 1;
            }
            continue;
        }
        if(i == M - 1){
            if(B[M - 2] > B[M - 1]){
                ans[B2A[M - 1]] = 1;
            }
            continue;
        }

        if((B[i - 1] < B[i] && B[i] > B[i + 1]) || (B[i - 1] > B[i] && B[i] < B[i + 1])){
            ans[B2A[i]] = 1;
        }
    }

    rep(i, N){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}