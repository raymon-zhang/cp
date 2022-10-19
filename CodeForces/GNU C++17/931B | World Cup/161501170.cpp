#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n, a, b;
    cin >> n >> a >> b;
    int rounds = 0;
    int teams = 2;
    while (n > 1) {
        rounds++;
        int aMatch = (a-1)/teams;
        int bMatch = (b-1)/teams;
        if (aMatch == bMatch) {
            if (n == 2) {
                cout << "Final!" << "\n";
            } else {
                cout << rounds << "\n";
                break;
            }
        }
        teams *= 2;
        n /= 2;
    }
}