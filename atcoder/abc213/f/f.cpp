#define TO_BE_SUBMITTED
#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
#include <atcoder/lazysegtree>
#include <atcoder/string>
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

int N;
string S;
vl ans;

vl calc(vi lcp) {
    // 0~i - 1までのminの合計を返す。
    ll now = 0;
    stack<LP> st;
    st.push(LP(-1, 0));

    vl res;
    res.eb(now);

    rep(i, N - 1){ // lcp[i]に関するi - 1までの合計
        ll lcpVal = lcp[i];
        ll cnt = 1; // lcp[i]に丸める数

        now += lcpVal;

        while(true){
            LP lp = st.top();
            if(lp.fr < lcpVal){
                break;
            }

            cnt += lp.sc;
            now += lp.sc * (lcpVal - lp.fr);

            st.pop();
        }

        res.eb(now);
        st.push(LP(lcpVal, cnt));
    }

    return res;
}

void solve()
{
    cin >> N >> S;
    vi sa = suffix_array(S);

    vi lcp = lcp_array(S, sa);

    vi lcpRev = vi(rrng(lcp));
    ans = vl(N, -1LL);

    vl calcRes = calc(lcp);

    vl calcResRev = calc(lcpRev);

    rep(i, N){
        int ansI = sa[i];
        ll sumVal = N - ansI;
        sumVal += calcRes[i];
        sumVal += calcResRev[N - 1 - i];
        ans[ansI] = sumVal;
    }

    for(auto an : ans){
        cout << an << "\n";
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