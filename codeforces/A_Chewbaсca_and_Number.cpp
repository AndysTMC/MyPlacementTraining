#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x;
    cin >> x;
    string temp = to_string(x);
    int i=0;
    if (temp[i] == '9')
        i++;
    while (i < temp.size())
    {
        int a = min(temp[i] - '0', 9 - (temp[i] - '0'));
        temp[i] = a + '0';
        i++;
    }

    cout << temp;
    return 0;
}
