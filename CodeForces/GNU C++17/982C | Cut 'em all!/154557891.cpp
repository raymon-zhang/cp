#include <bits/stdc++.h>
using namespace std;
 
vector<int> g[1000000];
int ans = 0;
 
int dfs(int i, int p) {
    int size = 1;
    for (int e: g[i]) {
        if (e == p) continue;
        size += dfs(e, i);
    }
    if (size % 2 == 0) {
        ans += 1;
        return 0;
    }
    return size;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    for (int i = 0; i < n-1; i++) {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
 
    if (n & 1) ans = -1;
    else {
        dfs(1, 0);
        ans--;
    }
    cout << ans << "\n";
}