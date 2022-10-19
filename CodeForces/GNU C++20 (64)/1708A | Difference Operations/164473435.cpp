#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int f;
        cin >> f;
        int good = true;
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            if (x%f) {
                good = false;
            }
        }
        cout << (good ? "YES" : "NO") << "\n";
    }
}