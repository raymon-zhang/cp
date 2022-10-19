#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        float diff = fmod((x + z) / 2.0 - y, 1.5);
        if (diff == 0)
        {
            cout << "0"
                 << "\n";
        }
        else
        {
            cout << "1"
                 << "\n";
        }
    }
}