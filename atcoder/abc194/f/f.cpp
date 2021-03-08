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
using MOD = modint1000000007;



bool used[16];
int dp[200001][17][17];

MOD comb[17][17];


MOD calc(int N, int A, int B){ // 長さNにA種類の数字を入れる。B種類はマスト。その組み合わせ数。
    if(dp[N][A][B] != -1) {
        MOD m = dp[N][A][B];
        return m;
    }

    if(N < B || A < B){ // 不可能なパターン。
        MOD m = 0;
        dp[N][A][B] = 0;
        return m;
    }

    if(A == 0){ // Aが0なら既に確定。
        MOD m = 1;
        dp[N][A][B] = 1;
        return m;
    }

    if(B == 0){ // Bが0ならAだけで決まる。
        MOD m = A;
        m = m.pow(N);
        dp[N][A][B] = m.val();
        return m;
    }

    MOD m = calc(N - 1, A, B) * (A - B) + calc(N - 1, A, B - 1) * B;
    dp[N][A][B] = m.val();
    return m;
}

int main()
{
    string sX;
    int N;
    vi X;
    int K;
    cin >> sX >> K;
    MOD ans;
    ans = 0;
    N = sX.size();

    rep(i, 17){
        rep(j, i + 1){
            if(j == 0 || i == j){
                comb[i][j] = 1;
            } else {
                comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
            }
        }
    }

    rep(i, 200001){
        rep(j, 17){
            rep(k, 17){
                dp[i][j][k] = -1;
            }
        }
    }

    rep(i, N){
        if('A' <= sX[i] && sX[i] <= 'F'){
            X.pb(sX[i] - 'A' + 10);
        } else {
            X.pb(sX[i] - '0');
        }
    }

    rep(i, 16){
        used[i] = false;
    }

    int usedNum = 0;

    rep(i, N){ // i桁一致。X[i]をずらすとき。
        if(usedNum > K){
            continue;
        }

        rep(a, X[i]) {// i桁一致。X[i] = aのとき
            if(i == 0 && a == 0){ // N - 1桁未満は後で考える。
                continue;
            }
            bool alreadyUsedA = used[a];
            if(!alreadyUsedA){
                used[a] = true;
                usedNum++;
            }

            MOD m;

            if(usedNum + N - i - 1 < K){
                goto fin;
            }

            // K種類にして足す。
            ans += calc(N - i - 1, K, K - usedNum) * comb[16-usedNum][K - usedNum];

            fin:
            ;

            if(!alreadyUsedA){
                used[a] = false;
                usedNum--;
            }
        }

        if(!used[X[i]]){
            usedNum++;
            used[X[i]] = true;
        }
    }

    // 全部の桁一致ケース。
    if(usedNum == K){
        ans += 1;
    }

    rep1(keta, N - 1){ // keta桁の数字の組み合わせ。
        ans += 15 * calc(keta - 1, K, K - 1) * comb[15][K - 1];
    }

    cout << ans.val() << endl;

    return 0;
}