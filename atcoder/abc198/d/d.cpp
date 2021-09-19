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

string s1, s2, s3;
set<char> st;
map<char, int> mp;

void solve()
{
    cin >> s1 >> s2 >> s3;
    rep(i, sz(s1)){
        st.insert(s1[i]);
    }
    rep(i, sz(s2)){
        st.insert(s2[i]);
    }
    rep(i, sz(s3)){
        st.insert(s3[i]);
    }

    if(st.size() > 10){
        cout << "UNSOLVABLE" << "\n";
        return;
    }

    int C = 0;
    {
        for(auto c : st){
            mp[c] = C;
            C++;
        }
    }
    vi vec(10);
    iota(rng(vec), 0);
    vl pow10(10);
    pow10[0] = 1LL;
    rep(i, 9){
        pow10[i + 1] = pow10[i] * 10LL;
    }

    do {
        ll a = 0;
        ll b = 0;
        ll c = 0;

        rrep(i, sz(s1)){
            int n = sz(s1);
            ll val = vec[mp[s1[i]]];
            if(i == 0 && val == 0){
                goto nx;
            }
            a += pow10[n - 1 - i] * val;
        }

        rrep(i, sz(s2)){
            int n = sz(s2);
            ll val = vec[mp[s2[i]]];
            if(i == 0 && val == 0){
                goto nx;
            }
            b += pow10[n - 1 - i] * val;
        }

        rrep(i, sz(s3)){
            int n = sz(s3);
            ll val = vec[mp[s3[i]]];
            if(i == 0 && val == 0){
                goto nx;
            }
            c += pow10[n - 1 - i] * val;
        }

        if(a + b == c){
            cout << a << "\n" << b << "\n" << c << "\n";
            return;
        }

        nx: ;
    } while(next_permutation(rng(vec)));

    cout << "UNSOLVABLE\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}