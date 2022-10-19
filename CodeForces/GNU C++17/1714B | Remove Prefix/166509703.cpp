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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i: a) cin >> i;
 
        unordered_set<int> nums;
        int cur = n-1;
        while (cur >= 0 && !nums.count(a[cur])) {
            nums.insert(a[cur]);
            cur--;
        }
        cout << cur+1 << "\n";
    }
}