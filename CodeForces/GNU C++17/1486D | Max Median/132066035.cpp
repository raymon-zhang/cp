#include <bits/stdc++.h>
using namespace std;
 
bool check(int median, int N, int K, vector<int> a) {
    vector<int> p(N+1);
    for (int i = 1; i < N+1; i++) {
        if (a[i-1] < median) {
            p[i] = p[i-1] - 1;
        } else if (a[i-1] >= median) {
            p[i] = p[i-1] + 1;
        } else {
            p[i] = p[i-1];
        }
        
        // cout << p[i] << "\n";
    }
 
    int lowest = 0;
    int highest = p[K];
 
    for (int i = K+1; i < N+1; i++) {
        lowest = min(lowest, p[i-K]);
        highest = max(highest, p[i] - lowest);
 
        // cout << "lowest " << lowest << "\n";
    }
 
    // cout << "highest " << highest << "\n";
 
    return highest > 0;
}
 
int main() {
    int N, K;
    cin >> N >> K;
 
    int lo = 1, hi = N+1;
    vector<int> a(N);
    for (int &i : a) {
        cin >> i;
        // lo = min(lo, i);
        // hi = max(hi, i);
    }
    // int mid = 5;
 
    // cout << check(mid, N, K, a) << "\n";
 
    while (lo + 1 < hi) {
        // cout << "lo: " << lo << ", hi: " << hi << "\n";
        int mid = (lo + hi) / 2;
        // cout << "mid: " << mid << "\n";
 
        if (check(mid, N, K, a)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
 
    cout << lo << "\n";
}