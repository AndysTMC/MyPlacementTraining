#include<bits/stdc++.h>
using namespace std;

/*
    Insertion sort builds a sorted portion of the list by repeatedly picking the next element and inserting it into its correct position.
    It shifts larger elements to the right to make space for the insertion.
*/

void insertion (vector<int>&arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    vector<int> arr = {4, 7, 3, 7, 2, 9, 4, 74, 68, 2, 9, 0, 552};
    insertion(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}