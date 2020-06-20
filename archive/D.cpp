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

typedef double db;
using namespace std;

ll N, K;
ll V[52];
ll dl[52][52], dr[52][52]; //dl[x][y]左からxまで取り出し&y個まで突っ込んでいいよのスコア最大値

int main()
{
  cin>>N>>K;
  rep1(i,N){
    cin>>V[i];
    dl[i][0]=dl[i-1][0]+V[i];
  }
  rrep1(i,N){
    dr[i][0]=dr[i+1][0]+V[i];
  }


  vector<ll> v;
  rep1(i,N){
    v.push_back(V[i]);
    sort(v.begin(), v.end());
    rep1(j,N){
      dl[i][j] = dl[i][j-1];
      if(j <= v.size() && v[j-1]<0) dl[i][j]-=v[j-1];
    }
  }

  vector<ll> w;
  rrep1(i,N){
    w.push_back(V[i]);
    sort(w.begin(), w.end());
    rep1(j,N){
      dr[i][j]=dr[i][j-1];
      if(j<=w.size() && w[j-1]<0) dr[i][j]-=w[j-1];
    }
  }
  ll ans = 0;
  rep(i, N+1){
    rep(j, i+1){
      rep(k, N+1){
        if(i+k>N) continue;
        rep(l, k+1){
          if(i+j+k+l>K) continue;
          ans = max(ans, dl[i][j]+dr[N+1-k][l]);
        }
      }
    }
  }
  cout<<ans<<endl;

}