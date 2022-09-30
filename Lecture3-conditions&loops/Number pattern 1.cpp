#include<iostream>
using namespace std;


int main(){
    int n,i=1,j;
    cin>>n;
    for(i=1;i<=n; i++)
    {
       int k = i;
        for(j=1; j<=i; j++)
        {   
            cout<<k;
            k = k+1;
        }

        cout<<endl;
}
}