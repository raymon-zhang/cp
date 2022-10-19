#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &i: h) {
        cin >> i;
    }
    ll count = 0;
    for (int i = 1; i < n-1; i+=2) {
        if (h[i] <= max(h[i-1], h[i+1])) {
            count += max(h[i-1], h[i+1])+1-h[i];
        }
    }
    if (!(n%2)) {
        ll count2 = 0;
        for (int i = 2; i < n-1; i+=2) {
            if (h[i] <= max(h[i-1], h[i+1])) {
                count2 += max(h[i-1], h[i+1])+1-h[i];
            }
        }
        count = min(count, count2);
    }
    if (n < 6 || n%2) {
        cout << count << "\n";
        return;
    }
 
    ll sum = 0;
    sum += h[1] <= max(h[0], h[2]) ? (max(h[0], h[2])+1-h[1]) : 0;
    sum += h[4] <= max(h[3], h[5]) ? (max(h[3], h[5])+1-h[4]) : 0;
    for (int i = 6; i < n-1; i+=2) {
        sum += h[i] <= max(h[i-1], h[i+1]) ? (max(h[i-1], h[i+1])+1-h[i]) : 0;
    }
    count = min(count, sum);
    int curPos = 4;
    for (int i = 0; i < n/2 - 2; i++) {
        sum -= h[curPos] <= max(h[curPos-1], h[curPos+1]) ? (max(h[curPos-1], h[curPos+1])+1-h[curPos]) : 0;
        sum += h[curPos-1] <= max(h[curPos-2], h[curPos]) ? (max(h[curPos-2], h[curPos])+1-h[curPos-1]) : 0;
        curPos += 2;
        count = min(count, sum);
    }
   
    cout << count << "\n";
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