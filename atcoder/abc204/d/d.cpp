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

// 差分何分までいけるか
set<ll> st1;
set<ll> st2;
vl T;
ll sumT = 0;

void solve()
{
    ll N, N1, N2;
    cin >> N;

    N1 = N / 2LL;
    N2 = N - N1;
    rep(i, N){
        ll t;
        cin >> t;
        T.pb(t);
        sumT += t;
    }

    if(N == 1LL){
        cout << T[0] << "\n";
        return;
    }

    if(N == 2LL){
        cout << max(T[0], T[1]) << "\n";
        return;
    }

    rep(ni1, N1){
        if(ni1 == 0){
            st1.insert(T[ni1]);
            st1.insert(-T[ni1]);
            continue;
        }

        vl gen = vl();
        for(auto ite = st1.begin(); ite != st1.end(); ++ite){
            gen.pb((*ite) - T[ni1]);
            gen.pb((*ite) + T[ni1]);
        }

        st1.clear();
        for(auto t : gen){
            st1.insert(t);
        }
    }

    rep(ni2, N2){
        if(ni2 == 0){
            st2.insert(T[N1 + ni2]);
            st2.insert(-T[N1 + ni2]);
            continue;
        }

        vl gen = vl();
        for(auto ite = st2.begin(); ite != st2.end(); ++ite){
            gen.pb((*ite) - T[N1 + ni2]);
            gen.pb((*ite) + T[N1 + ni2]);
        }

        st2.clear();
        for(auto t : gen){
            st2.insert(t);
        }
    }

    vl diff1, diff2;
    for(auto ite = st1.begin(); ite != st1.end(); ++ite){
        diff1.pb(*ite);
    }
    for(auto ite = st2.begin(); ite != st2.end(); ++ite){
        diff2.pb(*ite);
    }
    sort(rng(diff1));
    sort(rng(diff2));

    ll minDiff = INT64_MAX;

    for(auto d1 : diff1){
        int idA, idB;
        idA = lower_bound(rng(diff2), -d1) - diff2.begin();
        idB = idA - 1;

        if(isin(idA, 0, sz(diff2))){
            chmin(minDiff, abs(d1 + diff2[idA]));
        }
        if(isin(idB, 0, sz(diff2))){
            chmin(minDiff, abs(d1 + diff2[idB]));
        }
    }

    ll ans;
    if(sumT % 2LL == 0){
        ans = sumT / 2LL + minDiff / 2LL;
    } else {
        ans = sumT / 2LL + minDiff / 2LL + 1LL;
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