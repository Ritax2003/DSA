#include<iostream>
using namespace std;

int main() {
	int n;
    long pow = 1;
    cin>>n;
    long bin=0;
    int rem=0;
    while(n>0){
        rem = n%2;
        n=n/2;
        bin = bin + rem*pow;
        pow=pow*10;
        
    }
    cout<<bin;
	
}
