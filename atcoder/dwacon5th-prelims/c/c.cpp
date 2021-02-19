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



void solve(ll N, string S, ll k){
    ll numM = 0, numC = 0, numMC = 0, ans = 0;

    rep(i, k - 1){
        if(S[i] == 'M'){
            numM++;
        } else if(S[i] == 'C') {
            numMC += numM;
            numC++;
        }
    }

    rep(i, N){ // S[i+k-1] in, S[i] out.
        if(i+k-1 < N){
            if(S[i+k-1] == 'C'){
                numMC+=numM;
                numC++;
            } else if(S[i+k-1] == 'M') {
                numM++;
            }
        }

        if(S[i] == 'M') {
            numMC -= numC;
            numM--;
        } else if(S[i] == 'C') {
            numC--;
        } else if(S[i] == 'D') {
            ans += numMC;
        }
    }

    cout << ans << endl;
}

int main()
{
    ll N, Q;
    string S;
    vl k;

    cin >> N >> S >> Q;

    rep(i, Q){
        ll _k;
        cin >> _k;
        k.pb(_k);
        solve(N, S, _k);
    }

    return 0;
}