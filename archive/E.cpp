#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);++i)
#define rrep(i,n) for(int (i)=(n)-1;(i)>=0;--i)
#define rep1(i,n) for(int (i)=1;(i)<=(n);++i)
#define rrep1(i,n) for(int (i)=(n);(i)>=1;--i)
#define pb push_back
#define fr first
#define sc second
#define INF 0xffffffffffffff
//#define int long long

typedef long long ll;
typedef pair<int,int> P;
typedef pair<long long,long long> LP;
typedef double db;
using namespace std;
ll N,Q;
ll S[200000],T[200000],X[200000],S1[200000],T1[200000],X1[2000000];
LP idX[200000];
ll D[200000];
ll ans[200000];

ll data[1000000];

ll n_;
void init(ll n){
  n_ = 1;
  while(n_ < n){
    n_*=2;
  }
  rep(i, 2*n_-1) data[i] = INF;
}

void update(ll a, ll b, ll x, ll k, ll l, ll r){
  if(a<=l && r<=b){
    data[k] = min(data[k], x);
  }
  else if(r<=a || b<=l){
    return;
  }
  else{
    update(a, b, x, k*2+1, l, (l+r)/2);
    update(a, b, x, k*2+2, (l+r)/2, r);
  }
}

ll get1(ll q){
  if(q==0) return data[q];
  else return min(data[q], get1((q-1)/2));
}
ll lb, ub;

int main()
{
  cin>>N>>Q;
  rep(i,N) {cin>>S1[i]>>T1[i]>>X1[i]; idX[i]=LP(X1[i],i);}
  rep(i,Q) {cin>>D[Q-1-i]; D[Q-1-i]=-D[Q-1-i]; ans[i]=INF;}
  sort(idX, idX+N);
  rep(i,N){
    S[i]=S1[idX[i].sc];
    T[i]=T1[idX[i].sc];
    X[i]=X1[idX[i].sc];
  }
  init(N);
  rep(i,N){
    ll l = X[i] - T[i];
    ll r = X[i] - S[i];
    lb = upper_bound(D, D+N, l) - D;
    ub = upper_bound(D, D+N, r) - D;
    update(lb, ub, i, 0, 0, n_);
  }
  rep(i, Q){
    ans[i] = get1(i);
    if(ans[i]==INF) ans[i] = -1;
    else{
      ans[i] = X[ans[i]];
    }
    cout<<ans[i]<<endl;
  }
}