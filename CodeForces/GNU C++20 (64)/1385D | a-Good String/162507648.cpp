#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define pb push_back
#define F first
#define S second
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
vector<vector<int>> ps(26, vector<int>(131073));
string s;
 
int cost(int l, int r, int letter) {
    if (l == r) {
        return s[l-1]-'a' != letter;
    }
    int ml = (l+r)/2;
    int lFreq = ps[letter][ml] - ps[letter][l-1];
    int rFreq = ps[letter][r] - ps[letter][ml];
    return min((ml-l+1) - lFreq + cost(ml+1, r, letter+1), r - ml - rFreq + cost(l, ml, letter+1));
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cin >> s;
        fill(all(ps), vector<int>(n+1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                ps[j][i+1] = ps[j][i] + (s[i]-'a' == j);
            }
        }
 
        cout << cost(1, n, 0) << "\n";
    }
}