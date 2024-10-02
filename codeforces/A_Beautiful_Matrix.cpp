#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> arr(6, vector<int>(6));
    int a, b;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                a = i;
                b = j;
            }
        }
    }
    int res = abs(a - 3) + abs(b - 3);
    cout << res;
}