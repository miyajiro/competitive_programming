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

ll pow2Minus[50];
ll pow2[50];
bool is1[50];
int maxKeta;

void calc(ll N){
    if(N == 0){
        return;
    }
    int cnt = 0;
    ll r = 1;

    while(true){
        if(cnt % 2 == 0){
            if(N <= r && N >= 0){
                is1[cnt] = true;
                N -= pow2Minus[cnt];
                calc(N);
                return;
            }
            r = r - pow2[cnt + 2] + 1;
        } else {
            if(r <= N && N < 0){
                is1[cnt] = true;
                N -= pow2Minus[cnt];
                calc(N);
                return;
            }
            r = r + pow2[cnt + 2] - 1;
        }
        cnt++;
    }
}

void solve()
{
    ll N;
    pow2Minus[0] = 1;
    pow2[0] = 1;
    rep1(i, 49){
        pow2Minus[i] = pow2Minus[i - 1] * -2LL;
        pow2[i] = pow2[i - 1] * 2LL;
    }
    cin >> N;
    calc(N);
    string ans;
    rep(i, 50){
        if(is1[i]){
            maxKeta = i;
        }
    }
    rep(i, maxKeta + 1){
        if(is1[i]){
            ans = "1" + ans;
        } else {
            ans = "0" + ans;
        }
    }

    cout << ans << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}