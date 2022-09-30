#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
   int t1=0,t2=1;
    int i = 1;
    int nextTerm = t1 + t2;
    for (i = 3; i <= n; ++i){
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;
}
    cout<<nextTerm;
    
        
}
