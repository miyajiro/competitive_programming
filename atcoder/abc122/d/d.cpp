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
int N;
vector<string> chars = {"A", "C", "G", "T"};
map<string, bool> ok;
vector<map<string, mint>> dp;
vector<string> Ss;

void solve()
{
    cin >> N;
    dp = vector<map<string, mint>>(N+1);
    if(N == 3){
        cout << 4 * 4 * 4 - 3 << "\n";
        return;
    }

    for(auto c1 : chars){
        for(auto c2 : chars){
            for(auto c3 : chars){
                for(auto c4 : chars){
                    string s = c1 + c2 + c3 + c4;
                    ok[s] = true;
                    Ss.eb(s);

                    rep(i, 4){
                        string tmpS = s;
                        if(i < 3){
                            swap(tmpS[i], tmpS[i + 1]);
                        }

                        if(tmpS.substr(0, 3) == "AGC" || tmpS.substr(1, 3) == "AGC"){
                            ok[s] = false;
                        }
                    }


                    if(ok[s]){
                        dp[4][s] = 1;
                    }
                }
            }
        }
    }

    srep(i, 4, N){ // dp[i]
        for(auto nowS : Ss){
            if(!ok[nowS]){
                continue;
            }

            for(auto c : chars){
                string nexS = nowS.substr(1, 3) + c;
                if(!ok[nexS]){
                    continue;
                }

                dp[i + 1][nexS] += dp[i][nowS];
            }
        }
    }

    mint ans = 0;
    for(auto s : Ss){
        ans += dp[N][s];
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