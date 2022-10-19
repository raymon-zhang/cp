#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    int block = 5;
    while (N > block) {
        N -= block;
        block *= 2;
    }
    vector<string> names{"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    cout << names[(N-1) / (block/5)] << "\n";
}