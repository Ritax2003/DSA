#include<iostream>
using namespace std;

int main() {
 int n;
    int temp=0;
    cin>>n;
    int sqrt = n/2;
    while(sqrt!=temp){
        temp = sqrt ;
        sqrt = ( (n/temp) + temp) / 2;
    }
    cout<<sqrt;
    
    
    
}
