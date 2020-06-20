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
#define las(v) v[v.size()-1]
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<long long,long long> LP;
typedef double db;
using namespace std;

ll N,M;
ll K[10];
ll P[10];
vector<ll> T[10];
ll a[10];

int main()
{
  cin>>N>>M;
  rep(i, M){
    cin>>K[i];
    ll x;
    rep(j, K[i]){
      cin>>x;
      x--;
      T[x].push_back(i);
    }
  }
  rep(i, M) cin>>P[i];
  ll ans = 0;
  rep(i, 1<<N){
    rep(j,M) a[j] = P[j];
    rep(j,N){
      if((i>>j)&1){
        rep(k, T[j].size()){
          a[ T[j][k] ] ^= 1;
        }
      }
    }
    bool b = 1;
    rep(j,M){
      if(a[j]==1) b=0;
    }
    if(b) ans++;
  }
  cout<<ans<<endl;
}