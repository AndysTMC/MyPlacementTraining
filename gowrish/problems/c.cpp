#include <bits/stdc++.h>
using namespace std;

string ans = "";

bool isValidPalindrome(const string &s)
{
    if (s.size() == 1)
        return true;
    if (s[0] == '0')
        return false;
    return true;
}

bool generatePalindrome(string s, int k)
{
    unordered_map<char, int> freq;
    for (char c : s)
    {
        freq[c]++;
    }

    string half, middle;
    for (const auto &entry : freq)
    {
        if (entry.second % 2 != 0)
        {
            if (!middle.empty())
                return false; // More than one odd frequency character
            middle = string(1, entry.first);
        }
        half += string(entry.second / 2, entry.first);
    }

    string reversedHalf = half;
    reverse(reversedHalf.begin(), reversedHalf.end());
    string res = half + middle + reversedHalf;

    // Check if the number is divisible by k
    ans = res;
    long long num = stoll(res);
    // cout<<s<<" "<<num<<endl;
    return num % k == 0;
}

bool isPalindrome(const string &s)
{
    unordered_map<char, int> charCount;
    for (char c : s)
        charCount[c]++;

    int oddCount = 0;
    for (const auto &entry : charCount)
    {
        if (entry.second % 2 != 0)
            oddCount++;
    }

    return oddCount <= 1;
}

int countGoodIntegers(int n, int k)
{
    int count = 0;
    int start = pow(10, n - 1);
    int end = pow(10, n) - 1;

    for (int i = start; i <= end; ++i)
    {
        string s = to_string(i);
        ans = "";
        if (isPalindrome(s) && generatePalindrome(s, k) && isValidPalindrome(ans))
        {
            // cout << s << " ";
            ++count;
        }
    }
    return count;
}

int main()
{
    unordered_map<int, int> cache;
    for (int i=1;i<=10;i++){
        for(int j=1;j<=9;j++){
            cout<<i<<" "<<j<<" "<<countGoodIntegers(i, j)<<endl;
        }
    }
    return 0;
}
