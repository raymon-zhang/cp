#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e9+1;
 
void solve() {
    int n;
    cin >> n;
    long long upCost = 0;
    long long bestUp = MAX;
    long long horCost = 0;
    long long bestHor = MAX;
    long long numHor = 0;
    long long numUp = 0;
    bool isHor = true;
    long long bestCost = 1e15;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (isHor) {
            numHor++;
            if (x < bestHor) {
                if (bestHor != MAX) {
                    horCost += bestHor;
                }
                bestHor = x;
            } else {
                horCost += x;
            }
            bestCost = min(bestCost, horCost + (n-numHor+1) * bestHor + upCost + (n-numUp+1) * bestUp);
    // cout << "info " << bestUp << " " << bestHor << "\n";
    // cout << upCost << " " << (n-numUp) << " " << horCost << " " << (n-numHor) << "\n";
        } else {
            numUp++;
            if (x < bestUp) {
                if (bestUp != MAX) {
                    upCost += bestUp;
                }
                bestUp = x;
            } else {
                upCost += x;
            }
            bestCost = min(bestCost, upCost + (n-numUp+1) * bestUp + horCost + (n-numHor+1) * bestHor);
    // cout << "info " << bestUp << " " << bestHor << "\n";
    // cout << upCost << " " << (n-numUp) << " " << horCost << " " << (n-numHor) << "\n";
        }
        isHor = !isHor;
    }
 
 
    cout << bestCost << "\n";
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