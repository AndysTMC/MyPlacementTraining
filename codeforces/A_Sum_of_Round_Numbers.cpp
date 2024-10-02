#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int x = 10;
        int y = 1;
        vector<int>res;
        while(n!=0){
            if (((n % 10) * y))
                res.push_back((n % 10) * y);
            x *=10;
            y*=10;
            n = n/10;
        }
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}