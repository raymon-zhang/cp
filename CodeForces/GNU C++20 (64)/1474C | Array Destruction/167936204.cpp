#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
template<class T> using V = vector<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
 
template<class T> bool smin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool smax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
const int MOD = 1e9+7; // 998244353
const int MX = 2e5+5;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
 
void solve() {
    int n;
    cin >> n;
    V<int> a(2*n);
    map<int, int> f;
    for (int &i: a) {
        cin >> i;
        f[i]++;
    }
 
    sort(all(a));
 
    V<int> u = a;
    u.erase(unique(all(u)), end(u));
    // reverse(all(u));
    // cout << n*2 << "hi\n";
    bool good = false;
 
    for (int i = 0; i < 2*n-1; i++) {
        int start = a[i] + a[2*n-1];
        // cout << start << "\n";
        // cout << a[i] << "\n";
        map<int, int> nf = f;
        V<pii> moves;
        nf[a[2*n-1]]--; nf[a[i]]--;
        moves.pb({a[i], a[2*n-1]});
        int curS = a[2*n-1], curP = 2*n-2;
        bool ok = true;
        // for (pii x: nf) cout << x.first << " ";
        // cout << "\n";
        for (int j = 1; j < n; j++) {
            // if (start == 21) {
            //     cout << u[curP] << " hi\n";
            // }
            while (nf[u[curP]] == 0) curP--;
            // cout << 2*n << " curp\n";
            if ((u[curP] == curS - u[curP] && nf[curS - u[curP]] > 1) || (u[curP] != curS - u[curP] && nf[curS - u[curP]] >= 1)) {
                moves.pb({curS - u[curP], u[curP]});
                nf[curS - u[curP]]--; nf[u[curP]]--;
                curS = u[curP];
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            cout << start << "\n";
            for (pii x: moves) {
                cout << x.first << " " << x.second << "\n";
            }
            good = true;
            break;
        }
    }
 
    if (!good) {
        cout << "NO\n";
    }
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