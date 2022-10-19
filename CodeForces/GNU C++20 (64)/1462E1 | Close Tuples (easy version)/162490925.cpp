#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> freqs(n+1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freqs[x]++;
        }
 
        long long total = 0;
        for (int i = 1; i <= n-2; i++) {
            total += freqs[i] * (freqs[i]-1) * (freqs[i]-2) / 6;
            total += freqs[i] * (freqs[i]-1) / 2 * freqs[i+1];
            total += freqs[i] * (freqs[i]-1) / 2 * freqs[i+2];
            total += freqs[i] * freqs[i+1] * (freqs[i+1]-1) / 2;
            total += freqs[i] * freqs[i+1] * freqs[i+2];
            total += freqs[i] * freqs[i+2] * (freqs[i+2]-1) / 2;
        }
        total += freqs[n-1] * (freqs[n-1]-1) * (freqs[n-1]-2) / 6;
        total += freqs[n-1] * (freqs[n-1]-1) / 2 * (freqs[n]);
        total += freqs[n-1] * freqs[n] * (freqs[n]-1) / 2;
        total += freqs[n] * (freqs[n]-1) * (freqs[n]-2) / 6;
        cout << total << "\n";
    }
}