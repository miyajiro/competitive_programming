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
typedef long long ll;
typedef pair<int,int> P;
typedef pair<long long,long long> LP;
typedef double db;
using namespace std;

ll N;
ll X[18],W[18],V[18];

ll dfs(ll n,ll m,int s){
  if(n == N) return 0;
  if( ( (s>>n) & 1 ) || m < W[n] ){
    return dfs(n+1,m,s);
  }
  else return max( dfs(n+1,m,s), dfs(n+1,m-W[n],s) + V[n] );
}

int main()
{
  cin>>N;
  rep(i,N) cin>>X[i];
  rep(i,N) cin>>W[i];
  rep(i,N) cin>>V[i];
  ll ans = 0;
  ll m = 0;
  rep(k,N-1){
    ll tmp = 0xfffffffffffffff;
    int s = (1<<(k+1)) -1;
    m += X[k];
    //cout<<m<<endl;
    while(s < 1<<N){
      tmp = min(dfs(0,m,s),tmp);
      int x = s & -s;
      int y = s + x;
      s = ( (s & ~y) / x >> 1 ) | y;
    }
    ans = max(ans,tmp);
  }
  cout<<ans<<endl;
}
