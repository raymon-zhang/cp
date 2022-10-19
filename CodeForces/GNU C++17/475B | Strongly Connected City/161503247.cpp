#include <bits/stdc++.h>
using namespace std;
 
int n, m;
vector<int> horizontal;
vector<int> vertical;
 
void dfs(int x, int y, vector<vector<bool>> &seen) {
    if (x < 0 || x >= m) {
        return;
    }
    if (y < 0 || y >= n) {
        return;
    }
    if (seen[y][x]) {
        return;
    }
 
    // cout << x << " " << y << "\n";
    seen[y][x] = true;
    dfs(x + horizontal[y], y, seen);
    dfs(x, y + vertical[x], seen);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    cin >> n >> m;
 
    string h;
    cin >> h;
    for (char &c: h) {
        if (c == '>') {
            horizontal.push_back(1);
        } else {
            horizontal.push_back(-1);
        }
    }
 
    string v;
    cin >> v;
    for (char &c: v) {
        if (c == 'v') {
            vertical.push_back(1);
        } else {
            vertical.push_back(-1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<vector<bool>> seen(n, vector<bool>(m));
            dfs(j,i, seen);
            for (auto &row: seen) {
                for (auto cell : row) {
                    if (!cell) {
                        cout << "NO\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES\n";
    return 0;
}