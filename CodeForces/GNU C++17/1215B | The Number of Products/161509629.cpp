#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<long long> dpP(n+1);
    vector<long long> dpN(n+1);
 
    dpP[0] = 0;
    dpN[0] = 0;
 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            dpN[i+1] = dpP[i] + 1;
            dpP[i+1] = dpN[i];
        } else {
            dpP[i+1] = dpP[i] + 1;
            dpN[i+1] = dpN[i];
        }
    }
 
    long long ps = 0, ns = 0;
 
    for (int i = 1; i <= n; i++) {
        ps += dpP[i];
        ns += dpN[i];
    }
 
    cout << ns << " " << ps << "\n";
}