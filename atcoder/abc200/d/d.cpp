#include <bits/stdc++.h>
#include <atcoder/all>
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
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
using namespace atcoder;
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

ll N;
vl A;
vl ans1, ans2;
void ansYes(){
    puts("Yes");
    cout << ans1.size();
    ll sum1 = 0LL, sum2 = 0LL;
    rep(i, ans1.size()){
        sum1 = (sum1 + A[ans1[i] - 1]) % 200LL;
        cout << " " << ans1[i];
    }
    newline;
    cout << ans2.size();
    rep(i, ans2.size()){
        sum2 = (sum2 + A[ans2[i] - 1]) % 200LL;
        cout << " " << ans2[i];
    }
    newline;
    // assert(sum1 == sum2);
    return;
}

vi dp[2][200]; // dp[X]: Xを作るのに必要なAのインデックスを格納

int main()
{
    cin >> N;
    rep(i, N){
        int a;
        cin >> a;
        A.pb(a % 200);
    }

    int last = 0;
    int now = 1;
    rep(a_i, N){
        int a = A[a_i];
        rep(j, 200){ // lastからnowにコピー
            dp[now][j].clear();
            for(auto val : dp[last][j]){
                dp[now][j].pb(val);
            }
        }

        if(dp[last][a].size() > 0){
            ans1.pb(a_i+1);
            for(auto dpi : dp[last][a]){
                ans2.pb(dpi + 1);
            }
            ansYes();
            return 0;
        }

        dp[now][a].pb(a_i); // A[i]単体

        rep(base, 200){ // baseにAを足したもの
            if(dp[last][base].size() == 0){
                continue;
            }
            int newVal = (base + a) % 200;

            if(dp[now][newVal].size() > 0){
                for(auto dpi : dp[now][newVal]){
                    ans1.pb(dpi + 1);
                }

                for(auto dpi : dp[last][base]){
                    ans2.pb(dpi + 1);
                }
                ans2.pb(a_i + 1);
                ansYes();

                return 0;
            }

            for(auto dpi : dp[last][base]){
                dp[now][newVal].pb(dpi);
            }
            dp[now][newVal].pb(a_i);
        }

        last = 1 - last;
        now = 1 - now;
    }

    puts("No");

    return 0;
}