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

using MOD = modint998244353;

MOD dp[500001][2]; // dp[i][isHigherThanNext]
ll A[500001];
ll N;

int main()
{
    cin >> N;
    rep(i, N){
        cin >> A[i];
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    A[N] = 1000000001LL;
    dp[N][0] = 0;
    dp[N][1] = 0;
    N++;

    int isHigher = 1;
    int notHigher = 0;


    if(A[0] > A[1]){ // A0がでかいとき。
        dp[0][notHigher] = A[1];
        dp[0][isHigher] = A[0] - A[1];
    } else { // A0 <= A1
        dp[0][notHigher] = A[0];
    }



    rep(i, N - 1){ // i + 1を更新しに行く。
        if(A[i + 1] > A[i + 2]){
            // dp[i][notHigher]
            dp[i+1][notHigher] += dp[i][notHigher] * (A[i+2] - 1);

            // dp[i][isHigher]
            dp[i+1][notHigher] += dp[i][isHigher] * A[i+2]; // 1~A[i+2]どこでも


        } else { // Ai+1 <= Ai+2
            // dp[i][notHigher]
            dp[i+1][notHigher] += dp[i][notHigher] * (A[i+1] - 1);

            // dp[i][isHigher]
            dp[i+1][notHigher] += dp[i][isHigher] * A[i+1]; // 1~A[i+1]どこでも
        }
    }

    return 0;
}