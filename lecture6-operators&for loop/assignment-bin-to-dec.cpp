#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;
    int dec=0,i=0,rem=0;
	while(n>0){
        rem = n%10;
        n=n/10;
        dec = dec + (rem*pow(2,i));
        i++;
    }
    cout<<dec;
	
}