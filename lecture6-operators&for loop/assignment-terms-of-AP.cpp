#include<iostream>
using namespace std;

int main() {
	 int x;
    cin>>x;
    int i=1;
    while(x>0){
        int cal = (3*i) +2;
        if(cal%4!=0){
            cout<<cal<<" ";
            x--;
        }
        i++;
    }
    
}
