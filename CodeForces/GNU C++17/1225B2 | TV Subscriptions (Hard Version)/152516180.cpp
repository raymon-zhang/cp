#include <bits/stdc++.h>
using namespace std;
 
int days[200000];
 
void solve () {
    int n,k,d;
    cin >> n >> k >> d;
 
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }
 
    int toBuy = 0;
    map<int, int> shows;
    for (int i = 0; i < d; i++) {
        if (shows[days[i]] == 0) {
            toBuy++;
        }
        shows[days[i]]++;
    }
    int res = toBuy;
    for (int i = 1; i <= n-d; i++) {
        shows[days[i-1]]--;
        if (!shows[days[i-1]]) {
            toBuy--;
        }
 
        if (!shows[days[i-1+d]]) {
            toBuy++;
        }
        shows[days[i-1+d]]++;
        res = min(res, toBuy);
    }
 
    cout << res << "\n";
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