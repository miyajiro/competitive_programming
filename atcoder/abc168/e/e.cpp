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

using mint = modint1000000007;

map<LP, int> mp1; // 第１象限+y軸正
map<LP, int> mp4; // 第４象限+x軸正
set<LP> st;

int N;
vl A, B;

ll gcd(ll a, ll b){
    if(b == 0LL){
        return a;
    }
    return gcd(b, a % b);
}

void solve()
{
    int N;
    cin >> N;
    int cnt0 = 0;
    rep(i, N){
        ll a, b;
        cin >> a >> b;
        A.eb(a);
        B.eb(b);

        if(a == 0LL && b == 0LL){
            cnt0++;
            continue;
        }

        ll g = gcd(abs(a), abs(b));
        a /= g;
        b /= g;

        if(a == 0LL && b < 0LL){
            b = -b;
        }

        if(a < 0LL){
            a = -a;
            b = -b;
        }

        if(b > 0LL){ // 第1象限の場合
            st.insert(LP(a, b));
            mp1[LP(a, b)] += 1;
        } else { // 第4象限の場合
            st.insert(LP(-b, a));
            mp4[LP(-b, a)] += 1;
        }
    }

    mint ans = 1;
    mint m2 = 2;
    for(auto lp : st){
        ans *= (m2.pow(mp1[lp]) + m2.pow(mp4[lp]) - 1);
    }
    ans--;
    ans += cnt0;
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