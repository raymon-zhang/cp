#include <bits/stdc++.h>
using namespace std;
 
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
typedef pair<int, int> pii;
 
pii getRatio(int a, int b) {
    int g = gcd(a, b);
    a/=g;
    b/=g;
    return {a, b};
}
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    map<pii,int>mp;
    int d = 0, k = 0;
    for (char c: s) {
        if (c == 'D') {
            d++;
        } else {
            k++;
        }
        pii p = getRatio(d, k);
 
        mp[p]++;
        cout << mp[p] << " ";
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}