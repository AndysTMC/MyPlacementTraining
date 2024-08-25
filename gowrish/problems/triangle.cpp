//how many 2*2 squares can be formed in a right angled isosceles triangle of base n

#include <iostream> 
using namespace std;

int main() {
    int n;
    cin >> n;
    cout <<  (n-1)*(n-1)/2;
    return 0;
}