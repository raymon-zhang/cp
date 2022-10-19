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
        int n;
        cin >> n;
        string s;
        cin >> s;
 
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.at(i) == '1')
            {
                count++;
            }
        }
 
        vector<int> indicies;
        int countZeros = 0;
        for (int i = n - 1; i > n - 1 - count; i--)
        {
            if (s.at(i) == '0')
            {
                countZeros++;
                indicies.push_back(i);
            }
        }
 
        int countOnes = 0;
        int j = 0;
        while (countOnes < countZeros)
        {
            if (s.at(j) == '1')
            {
                countOnes++;
                indicies.push_back(j);
            }
            j++;
        }
 
        if (countZeros * 2)
        {
 
            cout << 1 << "\n";
            cout << countZeros * 2 << " ";
            for (int i = 0; i < countZeros; i++)
            {
                cout << indicies[countZeros + i] + 1 << " ";
            }
            for (int i = countZeros - 1; i >= 0; i--)
            {
                cout << indicies[i] + 1 << " ";
            }
        }
        else
        {
            cout << 0;
        }
 
        cout << "\n";
    }
}