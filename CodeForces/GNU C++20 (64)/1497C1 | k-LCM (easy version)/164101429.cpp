#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (n % 2) cout << 1 << " " << n / 2 << " " << n / 2 << "\n";
        else if (n % 2 == 0 && n % 4) cout << 2 << " " << n / 2 - 1 << " " << n / 2  - 1 << "\n";
        else cout << n / 2 << " " << n / 4 << " " << n / 4 << "\n";
    }
    return 0;
}