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

namespace atcoder
{
};
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

template <typename T>
size_t LongestIncreasingSubsequence(const vector<T> &a, bool strict)
{
    vector<T> lis;
    for (auto &p : a)
    {
        typename vector<T>::iterator it;
        if (strict)
            it = lower_bound(begin(lis), end(lis), p);
        else
            it = upper_bound(begin(lis), end(lis), p);
        if (end(lis) == it)
            lis.emplace_back(p);
        else
            *it = p;
    }
    return lis.size();
}

int N;
vi A, B;
vi invA, invB;

void solve()
{
    cin >> N;
    A = vi(N);
    invA = vi(N + 1);
    B = vi(N);
    invB = vi(N + 1);
    rep(i, N)
    {
        cin >> A[i];
        invA[A[i]] = i;
    }
    rep(i, N)
    {
        cin >> B[i];
        invB[B[i]] = i;
    }

    vp C;

    rep1(a, N){
        for(int b = a; b <= N; b += a){
            C.eb(P(invA[a], invB[b]));
        }
    }
    sort(rng(C), [](const P& a, const P& b){
        if(a.fr != b.fr){
            return a.fr < b.fr;
        }
        return a.sc > b.sc;
    });

    vi D;

    for(auto c : C){
        D.eb(c.sc);
    }

    cout << LongestIncreasingSubsequence(D, true) << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}