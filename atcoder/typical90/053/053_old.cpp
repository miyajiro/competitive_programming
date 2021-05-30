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

int T, N;
int l, r;
int cl, cr;
const double goldR = 2 / (3 + sqrt(5));
int A[1501];

void init(){
    rep(i, N+1){
        A[i] = -1;
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
        l = 1;
        r = N;

        cl = l + goldR * (r - l);
        cr = r - goldR * (r - l);

        while(r - l > 2){
            // cout << "\n\n";
            // show(l);
            // show(r);
            // show(cl);
            // show(cr);

            if(r - l > 2 && cl == cr){
                if(cr < l - 1){
                    cr++;
                } else {
                    cl--;
                }
            }

            if(getA(cl) == getA(cr)){
                l = cl;
                r = cr;

                cl = l + goldR * (r - l);
                cl = max(l + 1, cl);
                cl = min(r - 1, cl);

                cr = r - goldR * (r - l);
                cr = max(cr, cl + 1);
                cr = max(l + 1, cr);
                cr = min(r - 1, cr);
            } else if(getA(cl) < getA(cr)){
                l = cl;
                cl = cr;

                cr = r - goldR * (r - l);
                cr = max(cr, cl + 1);
                cr = max(l + 1, cr);
                cr = min(r - 1, cr);
            } else {
                r = cr;
                cr = cl;

                cl = l + goldR * (r - l);
                cl = min(cl, cr - 1);
                cl = max(l + 1, cl);
                cl = min(r - 1, cl);
            }
        }

        int valL = getA(l);
        int valR = getA(r);
        int valCL = getA(cl);
        int valCR = getA(cr);
        cout << "! " << max({valL, valR, valCL, valCR}) << "\n" << flush;
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