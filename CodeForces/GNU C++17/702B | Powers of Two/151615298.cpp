#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 998244353;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, x;
    map<ll,int> M;
    ll ret = 0;
 
 cin >> n;
 while(n--) {
  cin>>x;
  for(ll a=1;a<=1LL<<32;a<<=1) ret += M[a-x];
  M[x]++;
 }
 cout<<ret<<endl;
}