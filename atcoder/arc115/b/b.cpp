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

const ll INF = 0xffffffffffffff;

ll N;
ll mat[500][500];
ll mat2[500][500];
ll mat3[500][500];

bool check(){
    rep(i, N){
        rep(j, N){
            mat2[i][j] = mat[i][j] - mat[i][0]; // 1列目からの差分
            mat3[i][j] = mat[i][j] - mat[0][j]; // 1行目からの差分
        }
    }

    rep(i, N){
        rep(j, N){
            if(mat2[i][j] != mat2[0][j]){
                return false;
            }

            if(mat3[i][j] != mat3[i][0]){
                return false;
            }

        }
    }

    return true;
}

int main()
{

    cin >> N;

    ll minVal = INF;
    ll minRowId = -1;

    rep(i, N){
        rep(j, N){
            cin >> mat[i][j];
        }
        if(chmin(minVal, mat[i][0])){
            minRowId = i;
        }
    }

    if(!check()){
        puts("No");
        return 0;
    }

    // yes

    puts("Yes");


    cout << mat[0][0] - mat[minRowId][0];

    rep1(i, N - 1){
        cout << " " << mat[i][0] - mat[minRowId][0];
    }
    cout << endl;

    cout << mat[minRowId][0];

    rep1(i, N - 1){
        cout << " " << mat[minRowId][i];
    }
    cout << endl;


    return 0;
}