#include <bits/stdc++.h>
using namespace std;
 
 
void printPerm(vector<int> &perm) {
    for (int i: perm) {
        cout << i << " ";
    }
    cout << "\n";
}
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = n-i;
    }
 
    printPerm(perm);
 
    for (int i = 1; i < n; i++) {
        swap(perm[i-1], perm[i]);
        printPerm(perm);
        swap(perm[i-1], perm[i]);
    }
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}