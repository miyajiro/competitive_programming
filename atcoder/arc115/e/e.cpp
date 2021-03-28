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
vl nums;
vl rang;
ll N;

ll n;

map<ll, ll> numVal2numId;

modint data[2000000]; // 区間の和、またはその合計。
modint upper[2000000]; // 区間に対して上位から与えられた倍率。
modint lower[200000]; // 区間に対して下位が何通りだったか。
bool flag0[200000]; // 区間が0化されたかどうかのフラグ。

void eval(int k, int l, int r){
    if(flag0[k]){
        data[k] = 0;
        upper[k] = 0;
        lower[k] = 0;
        flag0[k] = false;

        if(r - l > 1){
            flag0[k*2 + 1] = true;
            flag0[k*2 + 2] = true;
        }
    }


}

void init(int _n){
    n = 1;
    while(n < _n){
        n *= 2;
    }
}

modint getSum(ll a, ll b, ll k, ll l, ll r){
    eval(k, l, r);

    if(b <= l || r <= a){
        return 0;
    }

    if(a <= l && r <= b){
        return data[k];
    }

    return getSum(a, b, k * 2 + 1, l, (l + r) / 2) + getSum(a, b, k * 2 + 2, (l + r) / 2, r);
}

void setZero(ll a, ll b, ll k, ll l, ll r){

}

void add(ll lowerSum, ll upperSum, ll a, ll b, ll k, ll l, ll r){
    eval(k, l, r);

    if(b <= l || r <= a){
        return 0;
    }

    if(a <= l && r <= b){
        return data[k];
    }

    return getSum(a, b, k * 2 + 1, l, (l + r) / 2) + getSum(a, b, k * 2 + 2, (l + r) / 2, r);
}

void check(ll val){
    ll ni = numVal2numId[val];

    ll lowerSum = getSum(0, ni + 1, 0, 0, n);
    ll upperSum = getSum(ni + 1, N + 1, 0, 0, n);

    setZero(ni + 1, N + 1, 0, 0, n);
    add(lowerSum, upperSum, ni + 1, N + 1, 0, 0, n);
}

int main()
{
    cin >> N;
    nums.pb(0);
    rep(i, N){
        cin >> A[i];
        nums.pb(A[i]);
        rang.pb(-1);
    }

    init(N+1);

    sort(rng(nums));

    rep(i, nums.size()){
        if(i > 0){
            rang[i] = nums[i] - nums[i - 1];
        }
        numVal2numId[nums[i]] = i;
    }



    return 0;
}