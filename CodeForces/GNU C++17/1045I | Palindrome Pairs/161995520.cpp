 
#include <bits/stdc++.h>
using namespace std;
 
map<int, int> p;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    vector<int> words;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int b = 0;
        for (char c: s) {
            b ^= 1 << (c-'a');
        }
        p[b]++;
        words.push_back(b);
    }
 
    long long total = 0;
    for (int s: words) {
        total += p[s]-1;
        for (int b = 0; b < 26; b++) {
            int x = s ^ (1<<b);
            total += p[x];
        }
    }
 
    total /= 2;
    cout << total << "\n";
}