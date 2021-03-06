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

bool isPrime[200001];
vi primes;

MOD myGamma[300001];

MOD comb(int n, int m){
    return myGamma[n] * ((myGamma[n - m] * myGamma[m]).inv());
}

void init(){
    int n = 200000;
    rep(i, n+1){
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    rep1(i, n){
        if(!isPrime[i]){
            continue;
        }

        for(int j = i * 2; j <= n; j+=i){
            isPrime[j] = false;
        }
    }

    rep1(i, n){
        if(isPrime[i]){
            primes.pb(i);
        }
    }

    myGamma[0] = 1;
    rep1(i, 300000){
        myGamma[i] = myGamma[i - 1] * i;
    }
}

vi divPowNums(int n){ // powの係数の列。12なら2 * 2 * 3なので[2, 1]が返る。
    vi res;
    rep(pi, primes.size()){
        if(n == 1){
            break;
        }
        int p = primes[pi];
        if(p * p > n){ // もう残っているのがデカい素数のとき。
            res.pb(1);
            break;
        }
        if(n % p != 0){
            continue;
        }

        int cnt = 0;
        while(n % p == 0){
            n /= p;
            cnt++;
        }

        res.pb(cnt);
        if(n == 1){
            break;
        }
    }

    return res;
}

MOD solve(int n, int m){ // n個で最後の要素m
    MOD res = 1;
    vi powNums = divPowNums(m);
    for(auto pn : powNums){
        res *= comb(n - 1 + pn, pn);
    }
    return res;
}

int main()
{
    init();
    int N, M;
    cin >> N >> M;
    MOD ans = 0;
    rep1(i, M){
        // cerr << "solve(" << N << ", " << i << ") = " << solve(N, i).val() << endl;
        ans += solve(N, i);
    }

    cout << ans.val() << endl;
    return 0;
}