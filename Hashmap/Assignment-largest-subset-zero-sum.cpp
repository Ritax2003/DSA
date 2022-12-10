#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int,int> mp;
    int sum =0,max=0;
    mp[0]=0;
    for(int i =0;i<n;i++){
        sum +=arr[i];
        if(mp.count(sum)>0){
            max=(max>(i+1-mp[sum]))?max:(i+1-mp[sum]);
        }
        else{
            mp[sum]=i+1;
        }
        
    }
    return max;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}