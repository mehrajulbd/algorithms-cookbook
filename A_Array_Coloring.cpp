#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> colors;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            colors.push_back({x, i % 2});
        }

        sort(colors.begin(), colors.end());

        bool possible = true;
        for (int i = 1; i < n; i++)
        {
            if (colors[i].second == colors[i - 1].second)
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}