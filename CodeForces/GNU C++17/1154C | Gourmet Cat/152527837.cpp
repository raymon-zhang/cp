#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 998244353;
 
int update(int& a, int& b, int& c, int& total) {
    if (a) {
        a--;
        total++;
    } else {
        return 0;
    }
    if (b) {
        b--;
        total++;
    } else {
        return 0;
    }
    if (c) {
        c--;
        total++;
    } else {
        return 0;
    }
    if (a) {
        a--;
        total++;
    } else {
        return 0;
    }
    if (c) {
        c--;
        total++;
    } else {
        return 0;
    }
    if (b) {
        b--;
        total++;
    } else {
        return 0;
    }
    if (a) {
        a--;
        total++;
    } else {
        return 0;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    vector<int> a(3);
 cin >> a[0] >> a[1] >> a[2];
 
 vector<int> idx({0, 1, 2, 0, 2, 1, 0});
 
 int full = min({a[0] / 3, a[1] / 2, a[2] / 2});
 a[0] -= full * 3;
 a[1] -= full * 2;
 a[2] -= full * 2;
 
 int ans = 0;
 for (int start = 0; start < 7; ++start) {
  int day = start;
  vector<int> b = a;
  int cur = 0;
  while (b[idx[day]] > 0) {
   --b[idx[day]];
   day = (day + 1) % 7;
   ++cur;
  }
  ans = max(ans, full * 7 + cur);
 }
 
 cout << ans << endl;
 
 return 0;
}