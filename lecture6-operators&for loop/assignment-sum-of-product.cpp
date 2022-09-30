#include<iostream>
using namespace std;

int main() {
	int n , c,i=1;
    cin>>n;
    cin>>c;
    if(c == 1){
        int result1 = 0;
    for(i = 1;i<=n;i++){
        result1 = result1 + i;
        
    }   
        cout<<result1;
    }
    else if(c == 2){
        int result2 = 1;
        for(i = 1;i<=n;i++){
            result2 = result2*i;
        }
        cout<<result2;
    }
    if(c != 1 && c!= 2){
        cout<<"-1";
    }
	
}
