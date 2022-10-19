#include <bits/stdc++.h>
 
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long x, n;
        cin >> x >> n;
        int m = n%4;
        if (m == 1) {
            if (x%2) {
                cout << x+n;
            }
            else {
                cout << x-n;
            }
        } else if (m == 2) {
            if (x%2) {
                cout << x-1;
            } else {
                cout << x+1;
            }
        } else if(m == 3) {
            if (x%2) {
                cout << x - n - 1;
            } else {
                cout << x + n + 1;
            }
        } else {
            cout << x;
        }
 
        cout << "\n";
    }
} 