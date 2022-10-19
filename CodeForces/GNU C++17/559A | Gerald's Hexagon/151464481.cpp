#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int s1,s2,s3,s4,s5,s6;
    cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
 
    int triangles = 0;
    int sLength = (s1-1)*2+1;
 
    for (int i = 0; i < s2+s3; i++) {
        if (i+1 <= s2) {
            sLength++;
        } else if (i > s2){
            sLength--;
        }
 
        if (i+1 <= s6) {
            sLength++;
        } else if (i > s6){
            sLength--;
        }
        triangles += sLength;
    }
 
    cout << triangles << "\n";
}