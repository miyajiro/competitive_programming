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
#define ll int
#define rep(i,n) for(int (i)=0;(i)<(n);++i)
#define rrep(i,n) for(int (i)=(n)-1;(i)>=0;--i)
#define rep1(i,n) for(int (i)=1;(i)<=(n);++i)
#define rrep1(i,n) for(int (i)=(n);(i)>=1;--i)
#define pb push_back
#define fr first
#define sc second
typedef pair<int,int> P;
typedef pair<long long,long long> LP;
typedef double db;
using namespace std;
string s;
ll ans;
ll A[2002];
ll dp[4002][4002];
ll cnt=0;
ll mod = 998244353;
ll N,r,b;
int main()
{
  cin>>s;
  N=s.size();
  rep(i,N){
    A[i+1]=0;
    if(s[i]=='1') A[i+1]=1;
    else if(s[i]=='2') A[i+1]=2;
  }
  //rep1(i,N) cout<<A[i]<<endl;
  //cout<<"asd"<<endl;
  dp[0][0] = 1;
  rep1(i,2*N){
    if(i<=N) cnt+=2;
    
    rep(j,2*N){ // dp[i-1][j]
      r = i<=N ? j + A[i] : j;
      b = cnt-r;
      if(b > 0 && r <= 2*N) dp[i][r] = (dp[i][r]+dp[i-1][j])%mod; //青
      if(r > 0 && r <= 2*N)  dp[i][r-1] = (dp[i][r-1] + dp[i-1][j])%mod;
    }
    cnt-=1;
  }
  // rep(i,2*N+1){
  //   rep(j,2*N+1){
  //     cout<<dp[i][j]<<"a"<<i<<"b"<<j<<endl;
  //   }
  // }
  cout<<dp[2*N][0]<<endl;
}
