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
 
    map<ll, ll> products;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        products[b] += a;
    }
 
    int c = 0;
    ll total = 0;
    vector<pll> p;
    for (auto product: products) {
        p.pb(product);
        total += product.S;
        c++;
    }
 
    int l = 0;
    int r = c-1;
    ll bought = 0;
    ll price = 0;
    while (l <= r) {
        if (bought < p[l].F) {
            ll need = p[l].F - bought;
            if (need > p[r].S) {
                bought += p[r].S;
                price += p[r].S * 2;
                r--;
            } else {
                p[r].S -= need;
                bought += need;
                price += need * 2;
            }
        } else {
            bought += p[l].S;
            price += p[l].S;
            l++;
        }
    }
    cout << price << "\n";
}