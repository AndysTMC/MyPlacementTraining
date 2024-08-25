// Given an integer k, and an array of integers A.
// A transmitter can cover another transmitter if they are within the range of k
// Example 4 can cover 7 transmitter with a k value of 3
// Print the minimum number of transmitters required to cover all the transmitters

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int t = a[i] + k;
        while ((i + 1) < n && a[i + 1] <= t)
        {
            i++;
        }
        count++;
        t = a[i] + k;
        while ((i + 1) < n && a[i + 1] <= t)
        {
            i++;
        }
    }
    cout << count;
}


//ip & op
// 11 = n
// 3 = k
// 1 3 9 5 6 11 7 14 10 12 4 = a(n)
// 2 = output