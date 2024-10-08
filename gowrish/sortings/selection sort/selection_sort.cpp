#include<bits/stdc++.h>
using namespace std;

/*
    Selection sort repeatedly finds the minimum element from the unsorted portion of the list and swaps it with the first unsorted element.
    This process continues until the entire list is sorted.
*/

void selectionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(min!=i) swap(arr[i],arr[min]);
    }
}

int main(){
    vector<int>arr = {4,7,3,7,2,9,4,74,68,2,9,0,552};
    selectionSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" "; 
    }
    return 0;
}