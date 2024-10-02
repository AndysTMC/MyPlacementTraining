#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute(vector<int> &arr, int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = start; i <= end; ++i)
        {
            swap(arr[start], arr[i]);
            permute(arr, start + 1, end);
            swap(arr[start], arr[i]);
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    permute(arr, 0, n - 1);
    return 0;
}