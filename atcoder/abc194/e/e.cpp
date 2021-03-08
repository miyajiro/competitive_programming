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

int M, N;
vi A;
int num2kosu[1500001];
set<int> notInside;

int main()
{
    cin >> N >> M;
    rep(i, N){
        int a;
        cin >> a;
        A.pb(a);
        num2kosu[a] = 0;
        notInside.insert(i);
    }
    notInside.insert(N);

    rep(i, M - 1){
        num2kosu[A[i]]++;
        notInside.erase(A[i]);
    }

    int ans = N;

    rep(i, N - M + 1){
        if(num2kosu[A[i + M - 1]] == 0){
            notInside.erase(A[i + M - 1]);
        }
        num2kosu[A[i + M - 1]]++;

        chmin(ans, *(notInside.begin()));

        num2kosu[A[i]]--;
        if(num2kosu[A[i]] == 0){
            notInside.insert(A[i]);
        }
    }

    cout << ans << endl;

    return 0;
}