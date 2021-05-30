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
#define PQ(T) priority_queue<T, v(T), greater<T>>
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

int fib[16] = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 };

int T, N;
int l, r;
int cl, cr;

int A[1609];
int ans = 0;


void init(){
    rep(i, N+1){
        A[i] = -1;
    }
    srep(i, N+1, 1601){
        A[i] = -i;
    }
}

int getA(int i){
    if(A[i] == -1){
        cout << "? " << i << "\n" << flush;
        cin >> A[i];
    }
    return A[i];
}

void solve()
{
    cin >> T;
    rep(_, T){
        cin >> N;
        init();

        ans = 0;
        if(N <= 15){
            rep1(i, N){
                chmax(ans, getA(i));
            }
            goto out;
        }

        l = 0;
        r = 1597;
        cl = 610;
        cr = 987;

        chmax(ans, getA(cl));
        chmax(ans, getA(cr));

        if(getA(cl) < getA(cr)){
            l = cl;
            cl = cr;
            cr = -1;
        } else {
            r = cr;
            cr = cl;
            cl = -1;
        }

        rrep(i, 13){
            if(cl == -1){
                cl = l + fib[i];
            } else {
                cr = r - fib[i];
            }
            ans = max({ans, getA(cl), getA(cr)});
            if(getA(cl) < getA(cr)){
                l = cl;
                cl = cr;
                cr = -1;
            } else {
                r = cr;
                cr = cl;
                cl = -1;
            }
        }

        srep(i, l + 1, r){
            chmax(ans, getA(i));
        }

        out:
        cout << "! " << ans << "\n" << flush;
    }
    return;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}