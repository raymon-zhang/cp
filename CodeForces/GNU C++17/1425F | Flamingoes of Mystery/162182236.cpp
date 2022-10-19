#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    int firstThree;
    cout << "? 1 3" << endl;
    cin >> firstThree;
 
    int twoThree;
    cout << "? 2 3" << endl;
    cin >> twoThree;
 
    vector<int> res(n);
 
    int p = firstThree - twoThree;
    int oneTwo;
    res[0] = p;
    for (int i = 1; i < n; i++) {
        if (i == 2) {
            res[i] = twoThree - p;
            p = res[i];
            continue;
        }
        cout << "? " << i << " " << i+1 << endl;
        cin >> oneTwo;
        res[i] = oneTwo - p;
        p = res[i];
    }
    
    cout << "! ";
 
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}