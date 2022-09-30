#include<iostream>
using namespace std;

int main() {
    int n,r=0,evensum=0,oddsum=0;
    cin>>n;
    while(n>1){
        r = n%10;
        
        if(r%2==0){
            evensum = evensum + r;
            
        }
        else oddsum = oddsum + r;
         n = n/10;
    }
	
	cout<<evensum<<" "<<oddsum;
}
