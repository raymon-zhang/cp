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
    vector<int> potions(n);
    for (int &i: potions) {
        cin >> i;
    }
    ll total = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        if (total + potions[i] >= 0) {
            total += potions[i];
            q.push(potions[i]);
        } else if (!q.empty() && potions[i] > q.top()) {
            total -= q.top();
            q.pop();
            total += potions[i];
            q.push(potions[i]);
        }
    }
    cout << q.size() << "\n";
}