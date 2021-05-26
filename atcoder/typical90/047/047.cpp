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

ll p = 1e9+7;
ll b = 3;
int N;
vl hashS0; // S[0] ... S[x]までのハッシュ
vl hashT0;
vl powB;


ll getHashS(int l, int r){ // S[l]...S[r-1]までのハッシュ
    if(l == 0){
        return hashS0[r - 1];
    }
    return (((hashS0[r - 1] - hashS0[l - 1] * powB[r - l]) % p) + p) % p;// l = r - 1なら b^1
}

ll getHashT(int l, int r){
    if(l == 0){
        return hashT0[r - 1];
    }
    return (((hashT0[r - 1] - hashT0[l - 1] * powB[r - l]) % p) + p) % p;// l = r - 1なら b^1
}

void initHash(vi S, vi T){
    hashS0.clear();
    hashT0.clear();

    hashS0.eb(S[0]);
    rep1(i, N - 1){
        hashS0.eb((hashS0[i - 1] * b + S[i]) % p);
    }

    hashT0.eb(T[0]);
    rep1(i, N - 1){
        hashT0.eb((hashT0[i - 1] * b + T[i]) % p);
    }
}

void printNums(vi S, int l, int r){
    for(int i = l; i < r ; i++){
        cout << S[i];
    }
    cout << "\n";
}

int calc(vi S, vi T){
    int res = 0;
    initHash(S, T);

    int sL = N - 1;
    int sR = N; // fix
    int tL = 0; // fix
    int tR = 1;

    rep(i, N){
        if(getHashS(sL - i, sR) == getHashT(tL, tR + i)){
            // cout << "same:\n";
            // printNums(S, sL - i, sR);
            // printNums(T, tL, tR + i);
            // cout << "\n";
            res++;
        }
    }

    sL = 0;
    sR = N;
    tL = 0;
    tR = N;
    // sL: 0 fix
    // sR: N
    // tL: 0
    // tR: N fix
    rep1(i, N - 1){
        if(getHashS(sL, sR - i) == getHashT(tL + i, tR)){
            res++;
        }
    }
    return res;
}

void solve()
{
    string strS, strT;
    cin >> N >> strS >> strT;
    powB.pb(1);
    rep(i, N){
        powB.pb((powB[i] * b) % p);
    }

    vi S, rT, gT, bT;

    rep(i, N){
        int sVal, tVal;
        if(strS[i] == 'R'){
            S.pb(0);
        } else if(strS[i] == 'G'){
            S.pb(1);
        } else {
            S.pb(2);
        }
        if(strT[i] == 'R'){
            rT.pb(0);
            gT.pb(2);
            bT.pb(1);
        } else if(strT[i] == 'G'){
            rT.pb(2);
            gT.pb(1);
            bT.pb(0);
        } else {
            rT.pb(1);
            gT.pb(0);
            bT.pb(2);
        }
    }

    cout << calc(S, rT) + calc(S, gT) + calc(S, bT) << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}