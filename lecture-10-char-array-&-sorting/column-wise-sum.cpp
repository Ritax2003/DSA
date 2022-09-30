/*
input: 4 2 1 2 3 4 5 6 7 8
output: 16 20*/
#include<iostream>
using namespace std;


int main(){

       int m =0;
    int n=0;
    cin>>m>>n;
    int arr[m][n];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int j =0;
    while(j<n){
        int result=0;
        for(int i=0;i<m;i++){
            result= result+arr[i][j];
        }
        j++;
        cout<<result<<" ";
    }
  
}


