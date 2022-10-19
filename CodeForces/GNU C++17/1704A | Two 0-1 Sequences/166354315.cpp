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
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        bool good = false;
        for (int i = 0; i < n - (m-1); i++) {
            if (a[i] == b[0]) good = true;
        }
 
        for (int i = n-(m-1); i < n; i++) {
            if (a[i] != b[i-(n-(m-1))+1]) good = false;
        }
 
        cout << (good ? "YES\n": "NO\n");
    }
}