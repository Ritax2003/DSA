/*input: 5
output: 
   1234554321
   1234**4321
   123****321
   12******21
   1********1
*/#include<iostream>
using namespace std;

int main(){
    int i,j,n,k;
    
    cin >>n;
    
    for(i = n; i>=1;i--)
    {
        for( j = 1 ; j<= n;j++)
        {
            if(j<=i)
                cout <<j;
            else
                cout <<"*";
            
        }
    
    
    for(j = n ;j>=1;j--)
    {
        if(j<=i)
        {
            cout <<j;
        }
        else
            cout <<"*";
    }
        cout <<endl;
    }
}