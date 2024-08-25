#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        bool swaaped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j + 1]);
                swaaped = true;
            }
        }
        if(!swaaped) break;
    }
}

int main(){
    vector<int> arr = {4, 7, 3, 7, 2, 9, 4, 74, 68, 2, 9, 0, 552};
    bubbleSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
