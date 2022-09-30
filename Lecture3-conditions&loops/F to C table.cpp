#include<iostream>
using namespace std;


int main(){

       int S,E,W;
    cin>>S>>E>>W;
    int fah=0,cel=0;
    for(int i = 0;i<=((E-S)/W);i++){
        fah = S + W*i;
        cel = (5*(fah-32))/9;
    cout<<fah<<" "<<cel<<endl;
    } 
  
}