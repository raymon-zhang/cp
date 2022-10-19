#include <bits/stdc++.h>
using namespace std;
 
const int M = 1e9+1;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    vector<int> triples;
    triples.push_back(0);
    for (int i = 3; i*i/2+1 < M; i+=2) {
        triples.push_back(i*i/2+1);
    }
 
    // for (int i = 0; i < 10; i++) {
    //     cout << triples[i] << " ";
    // }
    // cout << "\n";
 
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        int l = 0, r = triples.size()-1;
        while (l < r) {
            int m = (l+r+1)/2;
            if (triples[m] <= x) {
                l = m;
            } else {
                r = m-1;
            }
        }
        cout << l << "\n";
    }
}