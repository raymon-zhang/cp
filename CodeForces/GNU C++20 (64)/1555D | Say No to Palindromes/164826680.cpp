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
 
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> costA;
    vector<int> costB;
    vector<int> costC;
    vector<int> costRA;
    vector<int> costRB;
    vector<int> costRC;
    int cost = 0;
    char c = 'a';
    for (int i = 0; i < n; i++) {
        costA.pb(cost);
        if (s.at(i) != c) {
            cost++;
        }
        c++;
        if (c > 'c') {
            c = 'a';
        }
    }
    costA.pb(cost);
    cost = 0;
    c = 'b';
    for (int i = 0; i < n; i++) {
        costB.pb(cost);
        if (s.at(i) != c) {
            cost++;
        }
        c++;
        if (c > 'c') {
            c = 'a';
        }
    }
    costB.pb(cost);
    cost = 0;
    c = 'c';
    for (int i = 0; i < n; i++) {
        costC.pb(cost);
        if (s.at(i) != c) {
            cost++;
        }
        c++;
        if (c > 'c') {
            c = 'a';
        }
    }
    costC.pb(cost);
    cost = 0;
    c = 'a';
    for (int i = 0; i < n; i++) {
        costRA.pb(cost);
        if (s.at(i) != c) {
            cost++;
        }
        c--;
        if (c < 'a') {
            c = 'c';
        }
    }
    costRA.pb(cost);
    cost = 0;
    c = 'b';
    for (int i = 0; i < n; i++) {
        costRB.pb(cost);
        if (s.at(i) != c) {
            cost++;
        }
        c--;
        if (c < 'a') {
            c = 'c';
        }
    }
    costRB.pb(cost);
    cost = 0;
    c = 'c';
    for (int i = 0; i < n; i++) {
        costRC.pb(cost);
        if (s.at(i) != c) {
            cost++;
        }
        c--;
        if (c < 'a') {
            c = 'c';
        }
    }
    costRC.pb(cost);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        int minCost = min(costA[r]-costA[l-1], min(costB[r]-costB[l-1], costC[r]-costC[l-1]));
        minCost = min(minCost, min(costRA[r]-costRA[l-1], min(costRB[r]-costRB[l-1], costRC[r]-costRC[l-1])));
        cout << minCost << "\n";
    }
}