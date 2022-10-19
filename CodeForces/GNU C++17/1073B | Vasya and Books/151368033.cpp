#include <bits/stdc++.h>
using namespace std;
 
int main() {
    deque<int> d;
 
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        d.push_front(x);
    }
 
    vector<bool> done(N+1);
 
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        int count = 0;
        if (!done[x]) {
            while (d.back() != x) {
                done[d.back()] = true;
                count++;
                d.pop_back();
            }
            count++;
            done[d.back()] = true;
            d.pop_back();
        }
        cout << count << "\n";
    }
}