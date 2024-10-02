#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == "X++" || arr[i] == "++X")
        {
            res++;
        }
        else
        {
            res--;
        }
    }
    cout << res;
}