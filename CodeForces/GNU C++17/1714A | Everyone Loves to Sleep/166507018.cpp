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
        int n, h, m;
        cin >> n >> h >> m;
        int bed = h*60+m;
        int least = 1e5;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            int time = x*60+y;
            if (time < bed) {
                time += 60*24;
            }
            least = min(least, time-bed);
        }
        cout << least/60 << " " << least %60 << "\n";
    }
}