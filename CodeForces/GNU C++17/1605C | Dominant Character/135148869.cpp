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
        string s;
        cin >> n;
        cin >> s;
 
        vector<int> p_a;
        vector<int> p_b;
        vector<int> p_c;
        p_a.push_back(0);
        p_b.push_back(0);
        p_c.push_back(0);
        for (int i = 0; i < n; i++)
        {
            p_a.push_back(p_a[i] + (s.at(i) == 'a'));
            p_b.push_back(p_b[i] + (s.at(i) == 'b'));
            p_c.push_back(p_c[i] + (s.at(i) == 'c'));
        }
 
        vector<int> a_indicies;
        int countA = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.at(i) == 'a')
            {
                countA++;
                a_indicies.push_back(i);
            }
        }
 
        if (countA < 2)
        {
            cout << "-1"
                 << "\n";
            continue;
        }
        int dist = n + 1;
 
        int found = 0;
        for (int i = 0; i < countA - 1; i++)
        {
            for (int j = i + 1; j < min(countA, i + 3); j++)
            {
                int a1 = a_indicies[i];
                int a2 = a_indicies[j];
                int num_a = p_a[a2] - p_a[a1] + 1;
                int num_b = p_b[a2] - p_b[a1];
                int num_c = p_c[a2] - p_c[a1];
                if (num_a > num_b && num_a > num_c)
                {
                    dist = min(dist, a2 - a1);
                    found++;
                }
            }
        }
        if (found)
        {
            cout << dist + 1 << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
}