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
    vector<int> a(n);
    for (int &i: a) {
        cin >> i;
    }
    
    sort(all(a));
 
    vector<bool> taken(150002);
    int boxers = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]-1 && !taken[a[i]-1]) {
            boxers++;
            taken[a[i]-1] = true;
        } else if (!taken[a[i]]) {
            boxers++;
            taken[a[i]] = true;
        } else if (!taken[a[i]+1]) {
            boxers++;
            taken[a[i]+1] = true;
        }
    }
    cout << boxers << "\n";
}