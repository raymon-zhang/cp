#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    string s;
    cin >> s;
 
    int dist = 0;
    int start = 0;
    vector<int> pos(26, -1);
    for (int i = 0; i < 27; i++) {
        if (pos[s[i] - 'A'] >= 0) {
            dist = i - pos[s[i] - 'A'] + 1;
            start = pos[s[i] - 'A'];
        }
        pos[s[i] - 'A'] = i;
    }
    if (dist == 2) {
        cout << "Impossible\n";
        return 0;
    }
 
    int topSize = dist / 2;
    int bottomSize = dist - topSize;
 
    for (int i = start + topSize - 1; i >= start; i--) {
        cout << s[i];
    }
    for (int i = 0; i < 13-topSize; i++) {
        cout << s[((start - i - 1) + 27) % 27];
    }
    cout << "\n";
    for (int i = start + topSize; i < start + dist - 1; i++) {
        cout << s[i];
    }
    for (int i = 0; i <= 13-bottomSize; i++) {
        cout << s[(start+dist+ i) % 27];
    }
    cout << "\n";
}