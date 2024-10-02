#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int total_drink = k * l;
    int total_slices = c * d;
    int for_one_drink = nl * n;
    int for_one_salt = np * n;

    int nd = total_drink / nl;
    int ns = total_slices;
    int np_salt = p / np;

    int max_toasts = min({nd, ns, np_salt}) / n;

    cout << max_toasts;
    return 0;
}
