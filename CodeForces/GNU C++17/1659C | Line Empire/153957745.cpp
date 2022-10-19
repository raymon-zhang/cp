#include<bits/stdc++.h>
using namespace std;
 
int a[200010];
long long sum[200010];
int main() {
 ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
 int T;
 cin>>T;
 while(T--) {
  int n,x,y;
  cin>>n>>x>>y;
  for(int i=1; i<=n; i++) {
   cin>>a[i];
   sum[i]=sum[i-1]+a[i];
  }
  long long ans=1e18,s=0;
  for(int i=0; i<=n; i++) {
   ans=min(ans,(long long)x*a[i]+y*(sum[n]-sum[i]-(long long)a[i]*(n-i)+a[i]));
  }
  cout<<ans<<"\n";
 }
 return 0;
}