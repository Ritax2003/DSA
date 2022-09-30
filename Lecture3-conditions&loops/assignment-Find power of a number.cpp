#include<iostream>
using namespace std;

int main() {
	int x,n,result=1;
    cin>>x>>n;
    while(n!=0){
        result = result*x;
        n=n-1;
    }
    cout<<result;
	
}
