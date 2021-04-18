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

ll N, M, Q;
vl T, _Y, X, Y;
vl id2Num;
ll A[200000];
ll B[200000];

//数列a(a[0],a[1],…,a[n-1])についての区間和と点更新を扱う
//区間和,点更新,二分探索はO(log{n})で動作する
class BIT {
public:
    //データの長さ
    ll n;
    //データの格納先
    vector<ll> a;
    //コンストラクタ
    BIT(ll n):n(n),a(n+1,0){}

    //a[i]にxを加算する
    void add(ll i,ll x){
        i++;
        if(i==0) return;
        for(ll k=i;k<=n;k+=(k & -k)){
            a[k]+=x;
        }
    }

    //a[i]+a[i+1]+…+a[j]を求める
    ll sum(ll i,ll j){
        if(i > j) return 0;
        return sum_sub(j)-sum_sub(i-1);
    }

    //a[0]+a[1]+…+a[i]を求める
    ll sum_sub(ll i){
        i++;
        ll s=0;
        if(i==0) return s;
        for(ll k=i;k>0;k-=(k & -k)){
            s+=a[k];
        }
        return s;
    }

    //a[0]+a[1]+…+a[i]>=xとなる最小のiを求める(任意のkでa[k]>=0が必要)
    ll lower_bound(ll x){
        if(x<=0){
            //xが0以下の場合は該当するものなし→0を返す
            return 0;
        }else{
            ll i=0;ll r=1;
            //最大としてありうる区間の長さを取得する
            //n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
            while(r<n) r=r<<1;
            //区間の長さは調べるごとに半分になる
            for(int len=r;len>0;len=len>>1) {
                //その区間を採用する場合
                if(i+len<n && a[i+len]<x){
                    x-=a[i+len];
                    i+=len;
                }
            }
            return i;
        }
    }
};

int main()
{
    cin >> N >> M >> Q;
    rep(i, Q){
        ll t, x, y;
        cin >> t >> x >> y;
        x--;
        T.pb(t);
        X.pb(x);
        _Y.pb(y);
        Y.pb(y);
        id2Num.pb(y);
    }
    id2Num.pb(0);
    sort(rng(id2Num));

    uni(id2Num);
    ll numL = id2Num.size();

    rep(i, Q){
        Y[i] = lower_bound(rng(id2Num), Y[i]) - id2Num.begin();
    }

    ll ans = 0;
    BIT aNum(numL), aVal(numL), bNum(numL), bVal(numL);
    aNum.add(0, N);
    bNum.add(0, M);

    rep(i, Q){
        ll t = T[i];
        ll x = X[i];
        ll oldY;
        ll newY = Y[i];

        if(t == 1LL){ // aを変える。
            oldY = A[x];
            if(oldY == newY){
                goto f;
            }

            if(oldY < newY){
                // Bの[oldY + 1, newY]の値合計を引き算
                ans -= bVal.sum(oldY + 1, newY);

                // Bの[oldY + 1, newY]の合計数 * newYを足し算
                ans += bNum.sum(oldY + 1, newY) * id2Num[newY];

                // Bの[0, oldY]の合計数 * (newY - oldY)を足し算
                ans += bNum.sum(0, oldY) * (id2Num[newY] - id2Num[oldY]);
            }

            if(oldY > newY){
                // Bの[newY + 1, oldY]の合計数 * oldYを引き算
                ans -= bNum.sum(newY + 1, oldY) * id2Num[oldY];

                // Bの[newY + 1, oldY]の値合計を足し算
                ans += bVal.sum(newY + 1, oldY);

                // Bの[0, newY]の合計数 * (newY - oldY)を足し算
                ans += bNum.sum(0, newY) * (id2Num[newY] - id2Num[oldY]);
            }

            A[x] = newY;
            aNum.add(oldY, -1);
            aNum.add(newY, 1);
            aVal.add(oldY, -id2Num[oldY]);
            aVal.add(newY, id2Num[newY]);
        } else { // bを変える
            oldY = B[x];
            if(oldY == newY){
                goto f;
            }

            if(oldY < newY){
                // Aの[oldY, newY - 1]の値合計を引き算
                ans -= aVal.sum(oldY, newY - 1);

                // Aの[oldY, newY - 1]の合計数 * newYを足し算
                ans += aNum.sum(oldY, newY - 1) * id2Num[newY];

                // Aの[0, oldY - 1]の合計数 * (newY - oldY)を足し算
                ans += aNum.sum(0, oldY - 1) * (id2Num[newY] - id2Num[oldY]);
            }

            if(oldY > newY){
                // Aの[newY, oldY - 1]の合計数 * oldYを引き算
                ans -= aNum.sum(newY, oldY - 1) * id2Num[oldY];

                // Aの[newY, oldY - 1]の値合計を足し算
                ans += aVal.sum(newY, oldY - 1);

                // Aの[0, newY - 1]の合計数 * (newY - oldY)を足し算
                ans += aNum.sum(0, newY - 1) * (id2Num[newY] - id2Num[oldY]);
            }

            B[x] = newY;
            bNum.add(oldY, -1);
            bNum.add(newY, 1);
            bVal.add(oldY, -id2Num[oldY]);
            bVal.add(newY, id2Num[newY]);
        }
        f:
        cout << ans << endl;
    }

    return 0;
}