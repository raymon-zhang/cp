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
 
    int n;
    cin >> n;
    ll fact = 1;
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            fact *= i;
            fact %= n;
            count++;
        }
    }
    
    if (fact == 1) {
        cout << count << "\n";
        for (int i = 1; i < n; i++) {
            if (gcd(i, n) == 1) {
                cout << i << " ";
            }
        }
        cout << "\n";
    } else {
        cout << count-1 << "\n";
        for (int i = 1; i < n; i++) {
            if (gcd(i, n) == 1 && i != fact) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}