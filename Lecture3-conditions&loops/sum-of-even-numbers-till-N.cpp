#include<iostream>
using namespace std;


int main(){

       	int N;
    int sum = 0;
    cin>>N;
    for(int i = 0;i<=N;i++){
        if(i%2==0){
            sum = sum +i;
        }
    }
    cout<<sum;