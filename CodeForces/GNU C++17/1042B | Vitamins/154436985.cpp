#include <bits/stdc++.h>
using namespace std;
 
int m = 1e9;
 
int main() {
    int minA = m, minB = m, minC = m;
    int minAB = m, minAC = m, minBC = m;
    int minABC = m;
    int n;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        int price;
        string s;
        cin >> price >> s;
        bool hasA = 0, hasB = 0, hasC = 0;
        for (auto c: s) {
            if (c == 'A') {
                hasA = true;
            }
            if (c == 'B') {
                hasB = true;
            }
            if (c == 'C') {
                hasC = true;
            }
        }
        if (hasA) {
            minA = min(minA, price);
        }
        if (hasB) {
            minB = min(minB, price);
        }
        if (hasC) {
            minC = min(minC, price);
        }
        if (hasA && hasB) {
            minAB = min(minAB, price);
        }
        if (hasA && hasC) {
            minAC = min(minAC, price);
        }
        if (hasB && hasC) {
            minBC = min(minBC, price);
        }
        if (hasA && hasB && hasC) {
            minABC = min(minABC, price);
        }
    }
 
    minAB = min(minAB, minA + minB);
    minAC = min(minAC, minA + minC);
    minBC = min(minBC, minB + minC);
    minABC = min(minABC, minAB + minC);
    minABC = min(minABC, minAC + minB);
    minABC = min(minABC, minBC + minA);
 
    if (minABC == m) {
        cout << "-1" << "\n";
    } else {
        cout << minABC << "\n";
    }
}